// This file is generated by Ember Desktop.  Please do not edit manually.
//
//

// This file contains the tokens for attributes stored in flash


// Identifier tags for tokens
// Creator for attribute: number of resets, singleton.
#define CREATOR_NUMBER_OF_RESETS_SINGLETON 0xB000
// Creator for attribute: mac tx unicast retry, singleton.
#define CREATOR_MAC_TX_UCAST_RETRY_SINGLETON 0xB001
// Creator for attribute: aps tx unicast retries, singleton.
#define CREATOR_APS_TX_UCAST_RETRY_SINGLETON 0xB002
// Creator for attribute: route discovery initiated, singleton.
#define CREATOR_ROUTE_DISC_INITIATED_SINGLETON 0xB003
// Creator for attribute: neighbor added, singleton.
#define CREATOR_NEIGHBOR_ADDED_SINGLETON 0xB004
// Creator for attribute: neighbor moved, singleton.
#define CREATOR_NEIGHBOR_REMOVED_SINGLETON 0xB005
// Creator for attribute: neighbor stale, singleton.
#define CREATOR_NEIGHBOR_STALE_SINGLETON 0xB006
// Creator for attribute: join indication, singleton.
#define CREATOR_JOIN_INDICATION_SINGLETON 0xB007
// Creator for attribute: child moved, singleton.
#define CREATOR_CHILD_MOVED_SINGLETON 0xB008
// Creator for attribute: average mac retry per aps message sent, singleton.
#define CREATOR_AVERAGE_MAC_RETRY_PER_APS_MSG_SENT_SINGLETON 0xB009
// Creator for attribute: last message lqi, singleton.
#define CREATOR_LAST_MESSAGE_LQI_SINGLETON 0xB00A
// Creator for attribute: last message rssi, singleton.
#define CREATOR_LAST_MESSAGE_RSSI_SINGLETON 0xB00B


// Types for the tokens
#ifdef DEFINETYPES
typedef uint16_t  tokType_average_mac_retry_per_aps_msg_sent;
typedef int8_t  tokType_last_message_rssi;
typedef uint8_t  tokType_last_message_lqi;
typedef uint16_t  tokType_child_moved;
typedef uint16_t  tokType_join_indication;
typedef uint16_t  tokType_neighbor_stale;
typedef uint16_t  tokType_neighbor_removed;
typedef uint16_t  tokType_neighbor_added;
typedef uint16_t  tokType_route_disc_initiated;
typedef uint16_t  tokType_aps_tx_ucast_retry;
typedef uint16_t  tokType_mac_tx_ucast_retry;
typedef uint16_t  tokType_number_of_resets;
#endif // DEFINETYPES


// Actual token definitions
#ifdef DEFINETOKENS
DEFINE_BASIC_TOKEN(NUMBER_OF_RESETS_SINGLETON, tokType_number_of_resets, 0x0000)
DEFINE_BASIC_TOKEN(MAC_TX_UCAST_RETRY_SINGLETON, tokType_mac_tx_ucast_retry, 0x0000)
DEFINE_BASIC_TOKEN(APS_TX_UCAST_RETRY_SINGLETON, tokType_aps_tx_ucast_retry, 0x0000)
DEFINE_BASIC_TOKEN(ROUTE_DISC_INITIATED_SINGLETON, tokType_route_disc_initiated, 0x0000)
DEFINE_BASIC_TOKEN(NEIGHBOR_ADDED_SINGLETON, tokType_neighbor_added, 0x0000)
DEFINE_BASIC_TOKEN(NEIGHBOR_REMOVED_SINGLETON, tokType_neighbor_removed, 0x0000)
DEFINE_BASIC_TOKEN(NEIGHBOR_STALE_SINGLETON, tokType_neighbor_stale, 0x0000)
DEFINE_BASIC_TOKEN(JOIN_INDICATION_SINGLETON, tokType_join_indication, 0x0000)
DEFINE_BASIC_TOKEN(CHILD_MOVED_SINGLETON, tokType_child_moved, 0x0000)
DEFINE_BASIC_TOKEN(AVERAGE_MAC_RETRY_PER_APS_MSG_SENT_SINGLETON, tokType_average_mac_retry_per_aps_msg_sent, 0x0000)
DEFINE_BASIC_TOKEN(LAST_MESSAGE_LQI_SINGLETON, tokType_last_message_lqi, 0x0000)
DEFINE_BASIC_TOKEN(LAST_MESSAGE_RSSI_SINGLETON, tokType_last_message_rssi, 0x0000)
#endif // DEFINETOKENS


// Macro snippet that loads all the attributes from tokens
#define GENERATED_TOKEN_LOADER(endpoint) do {\
  uint8_t ptr[2]; \
  uint8_t curNetwork = emberGetCurrentNetwork(); \
  uint8_t epNetwork; \
  halCommonGetToken((tokType_number_of_resets *)ptr, TOKEN_NUMBER_OF_RESETS_SINGLETON); \
  emberAfWriteServerAttribute(1, ZCL_DIAGNOSTICS_CLUSTER_ID, ZCL_NUMBER_OF_RESETS_ATTRIBUTE_ID, (uint8_t*)ptr, ZCL_INT16U_ATTRIBUTE_TYPE); \
  halCommonGetToken((tokType_mac_tx_ucast_retry *)ptr, TOKEN_MAC_TX_UCAST_RETRY_SINGLETON); \
  emberAfWriteServerAttribute(1, ZCL_DIAGNOSTICS_CLUSTER_ID, ZCL_MAC_TX_UCAST_RETRY_ATTRIBUTE_ID, (uint8_t*)ptr, ZCL_INT16U_ATTRIBUTE_TYPE); \
  halCommonGetToken((tokType_aps_tx_ucast_retry *)ptr, TOKEN_APS_TX_UCAST_RETRY_SINGLETON); \
  emberAfWriteServerAttribute(1, ZCL_DIAGNOSTICS_CLUSTER_ID, ZCL_APS_TX_UCAST_RETRY_ATTRIBUTE_ID, (uint8_t*)ptr, ZCL_INT16U_ATTRIBUTE_TYPE); \
  halCommonGetToken((tokType_route_disc_initiated *)ptr, TOKEN_ROUTE_DISC_INITIATED_SINGLETON); \
  emberAfWriteServerAttribute(1, ZCL_DIAGNOSTICS_CLUSTER_ID, ZCL_ROUTE_DISC_INITIATED_ATTRIBUTE_ID, (uint8_t*)ptr, ZCL_INT16U_ATTRIBUTE_TYPE); \
  halCommonGetToken((tokType_neighbor_added *)ptr, TOKEN_NEIGHBOR_ADDED_SINGLETON); \
  emberAfWriteServerAttribute(1, ZCL_DIAGNOSTICS_CLUSTER_ID, ZCL_NEIGHBOR_ADDED_ATTRIBUTE_ID, (uint8_t*)ptr, ZCL_INT16U_ATTRIBUTE_TYPE); \
  halCommonGetToken((tokType_neighbor_removed *)ptr, TOKEN_NEIGHBOR_REMOVED_SINGLETON); \
  emberAfWriteServerAttribute(1, ZCL_DIAGNOSTICS_CLUSTER_ID, ZCL_NEIGHBOR_REMOVED_ATTRIBUTE_ID, (uint8_t*)ptr, ZCL_INT16U_ATTRIBUTE_TYPE); \
  halCommonGetToken((tokType_neighbor_stale *)ptr, TOKEN_NEIGHBOR_STALE_SINGLETON); \
  emberAfWriteServerAttribute(1, ZCL_DIAGNOSTICS_CLUSTER_ID, ZCL_NEIGHBOR_STALE_ATTRIBUTE_ID, (uint8_t*)ptr, ZCL_INT16U_ATTRIBUTE_TYPE); \
  halCommonGetToken((tokType_join_indication *)ptr, TOKEN_JOIN_INDICATION_SINGLETON); \
  emberAfWriteServerAttribute(1, ZCL_DIAGNOSTICS_CLUSTER_ID, ZCL_JOIN_INDICATION_ATTRIBUTE_ID, (uint8_t*)ptr, ZCL_INT16U_ATTRIBUTE_TYPE); \
  halCommonGetToken((tokType_child_moved *)ptr, TOKEN_CHILD_MOVED_SINGLETON); \
  emberAfWriteServerAttribute(1, ZCL_DIAGNOSTICS_CLUSTER_ID, ZCL_CHILD_MOVED_ATTRIBUTE_ID, (uint8_t*)ptr, ZCL_INT16U_ATTRIBUTE_TYPE); \
  halCommonGetToken((tokType_average_mac_retry_per_aps_msg_sent *)ptr, TOKEN_AVERAGE_MAC_RETRY_PER_APS_MSG_SENT_SINGLETON); \
  emberAfWriteServerAttribute(1, ZCL_DIAGNOSTICS_CLUSTER_ID, ZCL_AVERAGE_MAC_RETRY_PER_APS_MSG_SENT_ATTRIBUTE_ID, (uint8_t*)ptr, ZCL_INT16U_ATTRIBUTE_TYPE); \
  halCommonGetToken((tokType_last_message_lqi *)ptr, TOKEN_LAST_MESSAGE_LQI_SINGLETON); \
  emberAfWriteServerAttribute(1, ZCL_DIAGNOSTICS_CLUSTER_ID, ZCL_LAST_MESSAGE_LQI_ATTRIBUTE_ID, (uint8_t*)ptr, ZCL_INT8U_ATTRIBUTE_TYPE); \
  halCommonGetToken((tokType_last_message_rssi *)ptr, TOKEN_LAST_MESSAGE_RSSI_SINGLETON); \
  emberAfWriteServerAttribute(1, ZCL_DIAGNOSTICS_CLUSTER_ID, ZCL_LAST_MESSAGE_RSSI_ATTRIBUTE_ID, (uint8_t*)ptr, ZCL_INT8S_ATTRIBUTE_TYPE); \
} while(false)


// Macro snippet that saves the attribute to token
#define GENERATED_TOKEN_SAVER do {\
  uint8_t allZeroData[2]; \
  MEMSET(allZeroData, 0, 2); \
  if ( data == NULL ) data = allZeroData; \
  if ( clusterId == 0x0B05 ) { \
    if ( metadata->attributeId == 0x0000 && !emberAfAttributeIsClient(metadata) ) \
      halCommonSetToken(TOKEN_NUMBER_OF_RESETS_SINGLETON, data); \
    if ( metadata->attributeId == 0x0104 && !emberAfAttributeIsClient(metadata) ) \
      halCommonSetToken(TOKEN_MAC_TX_UCAST_RETRY_SINGLETON, data); \
    if ( metadata->attributeId == 0x010A && !emberAfAttributeIsClient(metadata) ) \
      halCommonSetToken(TOKEN_APS_TX_UCAST_RETRY_SINGLETON, data); \
    if ( metadata->attributeId == 0x010C && !emberAfAttributeIsClient(metadata) ) \
      halCommonSetToken(TOKEN_ROUTE_DISC_INITIATED_SINGLETON, data); \
    if ( metadata->attributeId == 0x010D && !emberAfAttributeIsClient(metadata) ) \
      halCommonSetToken(TOKEN_NEIGHBOR_ADDED_SINGLETON, data); \
    if ( metadata->attributeId == 0x010E && !emberAfAttributeIsClient(metadata) ) \
      halCommonSetToken(TOKEN_NEIGHBOR_REMOVED_SINGLETON, data); \
    if ( metadata->attributeId == 0x010F && !emberAfAttributeIsClient(metadata) ) \
      halCommonSetToken(TOKEN_NEIGHBOR_STALE_SINGLETON, data); \
    if ( metadata->attributeId == 0x0110 && !emberAfAttributeIsClient(metadata) ) \
      halCommonSetToken(TOKEN_JOIN_INDICATION_SINGLETON, data); \
    if ( metadata->attributeId == 0x0111 && !emberAfAttributeIsClient(metadata) ) \
      halCommonSetToken(TOKEN_CHILD_MOVED_SINGLETON, data); \
    if ( metadata->attributeId == 0x011B && !emberAfAttributeIsClient(metadata) ) \
      halCommonSetToken(TOKEN_AVERAGE_MAC_RETRY_PER_APS_MSG_SENT_SINGLETON, data); \
    if ( metadata->attributeId == 0x011C && !emberAfAttributeIsClient(metadata) ) \
      halCommonSetToken(TOKEN_LAST_MESSAGE_LQI_SINGLETON, data); \
    if ( metadata->attributeId == 0x011D && !emberAfAttributeIsClient(metadata) ) \
      halCommonSetToken(TOKEN_LAST_MESSAGE_RSSI_SINGLETON, data); \
  }\
} while(false)


