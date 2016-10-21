// *****************************************************************************
// * gpio-sensor.c
// *
// * Plugin used to interface with a generic gpio sensor
// *
// * Copyright 2015 Silicon Laboratories, Inc.                              *80*
// *****************************************************************************

#include PLATFORM_HEADER

#include "stack/include/ember-types.h"
#include "stack/include/event.h"

#include "hal/hal.h"
#include "hal/micro/generic-interrupt-control.h"
#include "hal/micro/micro.h"
#include "hal/micro/gpio-sensor.h"
#ifdef MOTION_SENSOR
#if defined(MOTION_SENSOR_E93196)
#include "E93196.h"
#endif
#include "hal/micro/led-blink.h"
#include "app/framework/include/af.h"
#endif
//------------------------------------------------------------------------------
// Plugin private macros

// Shorthand macros used for referencing plugin options
#define SENSOR_ASSERT_DEBOUNCE   EMBER_AF_PLUGIN_GPIO_SENSOR_ASSERT_DEBOUNCE
#define SENSOR_DEASSERT_DEBOUNCE \
                              EMBER_AF_PLUGIN_GPIO_SENSOR_DEASSERT_DEBOUNCE
#if defined(CONTACT_SWITCH_NETVOX)
#define SENSOR_IS_ACTIVE_HI   0
#elif defined(WL_YG0001)
#define SENSOR_IS_ACTIVE_HI   0
#else
#define SENSOR_IS_ACTIVE_HI   EMBER_AF_PLUGIN_GPIO_SENSOR_SENSOR_POLARITY
#endif
//------------------------------------------------------------------------------
// Plugin private variables

// Events used internal to the plugin
EmberEventControl emberAfPluginGpioSensorInterruptEventControl;
EmberEventControl emberAfPluginGpioSensorDebounceEventControl;

// State variables to track the status of the gpio sensor
static HalGpioSensorState lastSensorStatus = HAL_GPIO_SENSOR_ACTIVE;
static HalGpioSensorState newSensorStatus = HAL_GPIO_SENSOR_NOT_ACTIVE;

// structure used to store irq configuration from GIC plugin
static HalGenericInterruptControlIrqCfg *irqConfig;

//------------------------------------------------------------------------------
// Forward declaration of functions
static void sensorDeassertedCallback(void);
static void sensorAssertedCallback(void);
static void sensorStateChangeDebounce(HalGpioSensorState status);

void emberAfPluginGpioSensorStateChangedCallback(uint8_t);

//------------------------------------------------------------------------------
// Plugin consumed callback implementations

// This function will be called on device init.
void emberAfPluginGpioSensorInitCallback(void)
{
  halGpioSensorInitialize();
}

//------------------------------------------------------------------------------
// Plugin Event Handlers

// gpio sensor state change handler.  This is the handler for the event that is
// activated by the GIC plugin when an interrupt occurs on the gpio sensor.  It
// determines whether the button is asserted or deasserted based on the polarity
// option and GPIO state, and calls the appropriate assert or deassert handler.
void emberAfPluginGpioSensorInterruptEventHandler(void)
{
  uint8_t reedValue;

  emberEventControlSetInactive(emberAfPluginGpioSensorInterruptEventControl);

  reedValue = halGenericInterruptControlIrqReadGpio(irqConfig);

#if defined(MOTION_SENSOR_E93196)
  if(lastSensorStatus == HAL_GPIO_SENSOR_ACTIVE)
  {
    ProcessDOCIInterrupt();
  }
#endif
  // If the gpio sensor was set to active high by the plugin properties, call
  // deassert when the value is 0 and assert when the value is 1.
  if (SENSOR_IS_ACTIVE_HI) {
    if (reedValue == 0) {
      sensorDeassertedCallback();
    } else {
      sensorAssertedCallback();
    }
  } else {
    if (reedValue == 0) {
      sensorAssertedCallback();
    } else {
      sensorDeassertedCallback();
    }
  }
}

// gpio sensor Debounce Handler.  This event is used to provide a short,
// parameterized delay between the gpio sensor state initially changing and
// being verified as needing to take action.  In the case of a bounce scenario,
// this event will be cancelled by the debounce state machine before it can
// execute.
void emberAfPluginGpioSensorDebounceEventHandler(void)
{
  emberEventControlSetInactive(emberAfPluginGpioSensorDebounceEventControl);
  lastSensorStatus = newSensorStatus;

#if defined(MOTION_SENSOR_E93196)
  emberEventControlSetDelayMS(emberAfPluginGpioSensorInterruptEventControl,
                                6*MILLISECOND_TICKS_PER_SECOND);

#endif
  turnLedOff(BOARDLED1);
  if (emberAfNetworkState() == EMBER_JOINED_NETWORK)
  {
#ifdef MOTION_SENSOR
    turnLedOff(BOARDLED1);
#endif
  emberAfPluginGpioSensorStateChangedCallback(newSensorStatus);
  }
}

//------------------------------------------------------------------------------
// Plugin private functions

// Helper function used to define action taken when a not yet debounced change
// in the gpio sensor is detected as having opened the switch.
static void sensorDeassertedCallback(void)
{
  sensorStateChangeDebounce(HAL_GPIO_SENSOR_NOT_ACTIVE);
}

// Helper function used to define action taken when a not yet debounced change
// in the gpio sensor is detected as having closed the switch
static void sensorAssertedCallback(void)
{
  sensorStateChangeDebounce(HAL_GPIO_SENSOR_ACTIVE);
}

// State machine used to debounce the gpio sensor.  This function is called on
// every transition of the gpio sensor's GPIO pin.  A delayed event is used to
// take action on the pin transition.  If the pin changes back to its original
// state before the delayed event can execute, that change is marked as a bounce
// and no further action is taken.
static void sensorStateChangeDebounce(HalGpioSensorState status)
{

  if (status == lastSensorStatus) {
    // we went back to last status before debounce.  don't send the
    // message.
    emberEventControlSetInactive(emberAfPluginGpioSensorDebounceEventControl);
    return;
  }
  if (status == HAL_GPIO_SENSOR_ACTIVE) {
    newSensorStatus = status;
#ifdef MOTION_SENSOR
    //-if (emberAfNetworkState() == EMBER_JOINED_NETWORK)
      turnLedOn(BOARDLED1);
#endif
    emberEventControlSetDelayMS(emberAfPluginGpioSensorDebounceEventControl,
                                SENSOR_ASSERT_DEBOUNCE);
    return;
  } else if (status == HAL_GPIO_SENSOR_NOT_ACTIVE) {
    newSensorStatus = status;
    emberEventControlSetDelayMS(emberAfPluginGpioSensorDebounceEventControl,
                                SENSOR_DEASSERT_DEBOUNCE);
    return;
  }
}

//------------------------------------------------------------------------------
// Plugin public functions

void halGpioSensorInitialize(void)
{
  uint8_t reedValue;

  // Set up the generic interrupt controller to handle changes on the gpio
  // sensor
  irqConfig = halGenericInterruptControlIrqCfgInitialize(GPIO_SENSOR_PIN,
                                                         GPIO_SENSOR_PORT,
                                                         GPIO_SENSOR_IRQ);
  halGenericInterruptControlIrqEventRegister(irqConfig,
                           &emberAfPluginGpioSensorInterruptEventControl);
  halGenericInterruptControlIrqEdgeConfig(irqConfig,1);
  halGenericInterruptControlIrqEnable(irqConfig);

  // Determine the initial value of the sensor
  reedValue = halGenericInterruptControlIrqReadGpio(irqConfig);
  if (SENSOR_IS_ACTIVE_HI) {
    if (reedValue) {
      newSensorStatus = HAL_GPIO_SENSOR_ACTIVE;
      lastSensorStatus = newSensorStatus;
    } else {
      newSensorStatus = HAL_GPIO_SENSOR_NOT_ACTIVE;
      lastSensorStatus = newSensorStatus;
    }
  } else {
    if (reedValue) {
      newSensorStatus = HAL_GPIO_SENSOR_NOT_ACTIVE;
      lastSensorStatus = newSensorStatus;
    } else {
      newSensorStatus = HAL_GPIO_SENSOR_ACTIVE;
      lastSensorStatus = newSensorStatus;
    }
  }
}

// Get the current state of the sensor
HalGpioSensorState halGpioSensorGetSensorValue(void)
{
  return(newSensorStatus);
}

