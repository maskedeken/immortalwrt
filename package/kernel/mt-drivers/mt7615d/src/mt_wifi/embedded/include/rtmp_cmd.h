#ifndef __RTMP_CMD_H__
#define __RTMP_CMD_H__

#include "rtmp_type.h"

/* OS_RTCMDUp is only used in UTIL/NETIF module */
#define OS_RTCMDUp RtmpOsCmdUp
#define OS_RTCMDRunning RtmpOsIsCmdThreadRunning

/* RALINK command status code */
#define RTMP_IO_EINVAL 30000
#define RTMP_IO_EOPNOTSUPP 30001
#define RTMP_IO_EFAULT 30002
#define RTMP_IO_ENETDOWN 30003
#define RTMP_IO_E2BIG 30004
#define RTMP_IO_ENOMEM 30005
#define RTMP_IO_EAGAIN 30006
#define RTMP_IO_ENOTCONN 30007

enum {
#ifdef MAT_SUPPORT
	SHOW_IPV4_MAT_INFO = 1,
	SHOW_IPV6_MAT_INFO = 2,
	SHOW_ETH_CLONE_MAC = 3,
#endif /* MAT_SUPPORT */
	SHOW_CONN_STATUS = 4,
	SHOW_DRVIER_VERION = 5,
	SHOW_BA_INFO = 6,
	SHOW_DESC_INFO = 7,
	RAIO_OFF = 10,
	RAIO_ON = 11,
	SHOW_CFG_VALUE = 21,
	SHOW_ADHOC_ENTRY_INFO = 22,
#if defined(DOT11Z_TDLS_SUPPORT) || defined(CFG_TDLS_SUPPORT)
	SHOW_TDLS_ENTRY_INFO = 25,
#endif /* defined(DOT11Z_TDLS_SUPPORT) || defined(CFG_TDLS_SUPPORT) */
	SHOW_DEV_INFO = 26,
	SHOW_STA_INFO = 27,
	SHOW_TR_INFO = 28,
	SHOW_SYS_INFO = 29,
	SHOW_PWR_INFO = 30,
	SHOW_DIAGNOSE_INFO = 31,
#ifdef MT_MAC
	SHOW_WTBL_INFO = 32,
	SHOW_MIB_INFO = 33,
	SHOW_PS_INFO = 34,
	SHOW_TMAC_INFO = 35,
	SHOW_AGG_INFO = 36,
	SHOW_PSE_INFO = 37,
	SHOW_PSE_DATA = 38,
	SHOW_DSCH_INFO = 39,
#ifdef CUT_THROUGH
	SHOW_CT_INFO = 40,
#endif /* CUT_THROUGH */
#ifdef DBDC_MODE
	SHOW_DBDC_INFO = 41,
#endif /*DBDC_MODE*/
	SHOW_WTBLTLV_INFO = 42,
#endif
#ifdef MEM_ALLOC_INFO_SUPPORT
	SHOW_MEM_INFO = 43,
	SHOW_PKTMEM_INFO = 44,
#endif /* MEM_ALLOC_INFO_SUPPORT */
	SHOW_WIFI_INT_CNT = 45,
	SHOW_EFUSE_INFO = 46,
	SHOW_PLE_INFO = 47,
#ifdef REDUCE_TCP_ACK_SUPPORT
	SHOW_TCP_RACK_INFO = 48,
#endif
	SHOW_TXOP_INFO = 49,
	SHOW_TXD_INFO = 50,
	DUMP_MEM_INFO = 51,
	SHOW_E2P_INFO = 52,
	SHOW_TP_INFO = 53,
	SHOW_CHCTRL_INFO = 54,
};

/* RALINK command handle ID */
/* ap commands */
typedef enum _CMD_RTPRIV_IOCTL_AP {

	/* general */
	CMD_RTPRIV_IOCTL_SET_WSCOOB = 0x0001,
	CMD_RTPRIV_IOCTL_GET_MAC_TABLE,
	CMD_RTPRIV_IOCTL_GSITESURVEY,
	CMD_RTPRIV_IOCTL_STATISTICS,
	CMD_MTPRIV_IOCTL_RD,
	CMD_RTPRIV_IOCTL_RX_STATISTICS,
	CMD_RTPRIV_IOCTL_QUERY_BATABLE,
	CMD_RTPRIV_IOCTL_E2P,
	CMD_RTPRIV_IOCTL_BBP,
	CMD_RTPRIV_IOCTL_MAC,
	CMD_RTPRIV_IOCTL_RF,
	CMD_RT_PRIV_IOCTL,
	CMD_RTPRIV_IOCTL_SET,
	CMD_RTPRIV_IOCTL_SHOW,
	CMD_RTPRIV_IOCTL_ATE,
	CMD_RTPRIV_IOCTL_CHID_2_FREQ,
	CMD_RTPRIV_IOCTL_FREQ_2_CHID,
	CMD_RTPRIV_IOCTL_GET_MAC_TABLE_STRUCT,

	/* mbss */
	CMD_RTPRIV_IOCTL_MBSS_BEACON_UPDATE,
	CMD_RTPRIV_IOCTL_MBSS_OPEN,
	CMD_RTPRIV_IOCTL_MBSS_CLOSE,
	CMD_RTPRIV_IOCTL_MBSS_INIT,
	CMD_RTPRIV_IOCTL_MBSS_REMOVE,
#ifdef MT_MAC
	CMD_RTPRIV_IOCTL_MBSS_CR_ENABLE,
	CMD_RTPRIV_IOCTL_MBSS_CR_DISABLE,
#endif

	/* wsc */
	CMD_RTPRIV_IOCTL_WSC_PROFILE,
	CMD_RTPRIV_IOCTL_WSC_INIT,

	/* apc */
	CMD_RTPRIV_IOCTL_APC_UP,
	CMD_RTPRIV_IOCTL_APC_DISCONNECT,
	CMD_RTPRIV_IOCTL_APC_INIT,
	CMD_RTPRIV_IOCTL_APC_REMOVE,

	/* interface */
	CMD_RTPRIV_IOCTL_MAIN_OPEN,

	/* ioctl */
	CMD_RTPRIV_IOCTL_PREPARE,
	CMD_RTPRIV_IOCTL_AP_SIOCGIWAP,
	CMD_RTPRIV_IOCTL_AP_SIOCGIFHWADDR,
	CMD_RTPRIV_IOCTL_AP_SIOCGIWESSID,
	CMD_RTPRIV_IOCTL_AP_SIOCGIWRATEQ,
	CMD_RTPRIV_IOCTL_AP_SIOCSIWGENIE,

	CMD_RTPRIV_IOCTL_GET_DRIVER_INFO,
#ifdef WIFI_DIAG
	CMD_RTPRIV_IOCTL_GET_PROCESS_INFO,
#endif

	/* can not exceed 0x5000 */
} CMD_RTPRIV_IOCTL_AP;

/* common commands */
typedef enum _CMD_RTPRIV_IOCTL_COMMON {

	/* general */
	CMD_RTPRIV_IOCTL_NETDEV_GET = 0x5000,
	CMD_RTPRIV_IOCTL_NETDEV_SET,
	CMD_RTPRIV_IOCTL_OPMODE_GET,
	CMD_RTPRIV_IOCTL_TASK_LIST_GET,
	CMD_RTPRIV_IOCTL_IRQ_INIT,
	CMD_RTPRIV_IOCTL_IRQ_RELEASE,
	CMD_RTPRIV_IOCTL_NIC_NOT_EXIST,
	CMD_RTPRIV_IOCTL_MCU_SLEEP_CLEAR,
	CMD_RTPRIV_IOCTL_SANITY_CHECK,
	CMD_RTPRIV_IOCTL_SANITY_CHECK_ON_SET_CMD,
#ifdef EXT_BUILD_CHANNEL_LIST
	CMD_RTPRIV_SET_PRECONFIG_VALUE,
#endif /* EXT_BUILD_CHANNEL_LIST */

	/* sniffer */
	CMD_RTPRIV_IOCTL_SNIFF_UP,
	CMD_RTPRIV_IOCTL_SNIFF_DISCONNECT,
	CMD_RTPRIV_IOCTL_SNIFF_INIT,
	CMD_RTPRIV_IOCTL_SNIFF_OPEN,
	CMD_RTPRIV_IOCTL_SNIFF_CLOSE,
	CMD_RTPRIV_IOCTL_SNIFF_REMOVE,

	/* mesh */
	CMD_RTPRIV_IOCTL_MESH_INIT,
	CMD_RTPRIV_IOCTL_MESH_REMOVE,
	CMD_RTPRIV_IOCTL_MESH_OPEN_PRE,
	CMD_RTPRIV_IOCTL_MESH_OPEN_POST,
	CMD_RTPRIV_IOCTL_MESH_IS_VALID,
	CMD_RTPRIV_IOCTL_MESH_CLOSE,

	/* p2p */
	CMD_RTPRIV_IOCTL_P2P_INIT,
	CMD_RTPRIV_IOCTL_P2P_REMOVE,
	CMD_RTPRIV_IOCTL_P2P_OPEN_PRE,
	CMD_RTPRIV_IOCTL_P2P_OPEN_POST,
	CMD_RTPRIV_IOCTL_P2P_IS_VALID,
	CMD_RTPRIV_IOCTL_P2P_CLOSE,

	/* usb */
	CMD_RTPRIV_IOCTL_USB_MORE_FLAG_SET,
	CMD_RTPRIV_IOCTL_USB_CONFIG_INIT,
	CMD_RTPRIV_IOCTL_USB_SUSPEND,
	CMD_RTPRIV_IOCTL_USB_RESUME,
	CMD_RTPRIV_IOCTL_USB_INIT,

	/* pci */
	CMD_RTPRIV_IOCTL_PCI_SUSPEND,
	CMD_RTPRIV_IOCTL_PCI_RESUME,
	CMD_RTPRIV_IOCTL_PCI_CSR_SET,
	CMD_RTPRIV_IOCTL_PCIE_INIT,

	/* rbus */
	CMD_RTPRIV_IOCTL_RBUS_SUSPEND,
	CMD_RTPRIV_IOCTL_RBUS_RESUME,

	/* cfg80211 */
	CMD_RTPRIV_IOCTL_CFG80211_CFG_START,

	/* inf ppa */
	CMD_RTPRIV_IOCTL_INF_PPA_INIT,
	CMD_RTPRIV_IOCTL_INF_PPA_EXIT,

	/* wireless */
	CMD_RTPRIV_IOCTL_BEACON_UPDATE,
	CMD_RTPRIV_IOCTL_RXPATH_GET,
	CMD_RTPRIV_IOCTL_CHAN_LIST_NUM_GET,
	CMD_RTPRIV_IOCTL_CHAN_LIST_GET,
	CMD_RTPRIV_IOCTL_FREQ_LIST_GET,

	/* interface */
	CMD_RTPRIV_IOCTL_VIRTUAL_INF_UP,
	CMD_RTPRIV_IOCTL_VIRTUAL_INF_DOWN,
	CMD_RTPRIV_IOCTL_VIRTUAL_INF_INIT,
	CMD_RTPRIV_IOCTL_VIRTUAL_INF_DEINIT,
	CMD_RTPRIV_IOCTL_VIRTUAL_INF_GET,
	CMD_RTPRIV_IOCTL_INF_TYPE_GET,
	CMD_RTPRIV_IOCTL_INF_STATS_GET,
	CMD_RTPRIV_IOCTL_INF_IW_STATUS_GET,
	CMD_RTPRIV_IOCTL_INF_MAIN_CREATE,
	CMD_RTPRIV_IOCTL_INF_MAIN_ID_GET,
	CMD_RTPRIV_IOCTL_INF_MAIN_CHECK,
	CMD_RTPRIV_IOCTL_INF_P2P_CHECK,

	/* ioctl */
	CMD_RTPRIV_IOCTL_SIOCGIWFREQ,
	CMD_RTPRIV_IOCTL_SIOCGIWNAME,
	CMD_RTPRIV_IOCTL_SIOCGIWRATE,

	/* wds */
	CMD_RTPRIV_IOCTL_WDS_INIT,
	CMD_RTPRIV_IOCTL_WDS_REMOVE,
	CMD_RTPRIV_IOCTL_WDS_STATS_GET,

	CMD_RTPRIV_IOCTL_MAC_ADDR_GET,

#ifdef RT_CFG80211_SUPPORT
	/* cfg802.11 */
	/* Note: All cfg commands must be continue. */
	/* CFG_TODO Sort by function */
	CMD_RTPRIV_IOCTL_80211_START,
	CMD_RTPRIV_IOCTL_80211_CB_GET,
	CMD_RTPRIV_IOCTL_80211_CB_SET,
	CMD_RTPRIV_IOCTL_80211_CHAN_SET,
	CMD_RTPRIV_IOCTL_80211_VIF_CHG,
	CMD_RTPRIV_IOCTL_80211_SCAN,
	CMD_RTPRIV_IOCTL_80211_IBSS_JOIN,
	CMD_RTPRIV_IOCTL_80211_STA_LEAVE,
	CMD_RTPRIV_IOCTL_80211_STA_GET,
	CMD_RTPRIV_IOCTL_80211_STA_KEY_ADD,
	CMD_RTPRIV_IOCTL_80211_STA_KEY_DEFAULT_SET,
	CMD_RTPRIV_IOCTL_80211_POWER_MGMT_SET,
	CMD_RTPRIV_IOCTL_80211_AP_KEY_DEFAULT_SET,
	CMD_RTPRIV_IOCTL_80211_AP_KEY_DEFAULT_MGMT_SET,
	CMD_RTPRIV_IOCTL_80211_CONNECT_TO,
	CMD_RTPRIV_IOCTL_80211_RFKILL,
	CMD_RTPRIV_IOCTL_80211_REG_NOTIFY_TO,
	CMD_RTPRIV_IOCTL_80211_UNREGISTER,
	CMD_RTPRIV_IOCTL_80211_BANDINFO_GET,
	CMD_RTPRIV_IOCTL_80211_SURVEY_GET,
	CMD_RTPRIV_IOCTL_80211_EXTRA_IES_SET,
	CMD_RTPRIV_IOCTL_80211_REMAIN_ON_CHAN_SET,
	CMD_RTPRIV_IOCTL_80211_MGMT_FRAME_REG,
	CMD_RTPRIV_IOCTL_80211_CHANNEL_LOCK,
	CMD_RTPRIV_IOCTL_80211_MGMT_FRAME_SEND,
	CMD_RTPRIV_IOCTL_80211_CHANNEL_LIST_SET,
	CMD_RTPRIV_IOCTL_80211_ACTION_FRAME_REG,
	CMD_RTPRIV_IOCTL_80211_BEACON_ADD,
	CMD_RTPRIV_IOCTL_80211_BEACON_SET,
	CMD_RTPRIV_IOCTL_80211_BEACON_DEL,
	CMD_RTPRIV_IOCTL_80211_AP_KEY_ADD,
	CMD_RTPRIV_IOCTL_80211_RTS_THRESHOLD_ADD,
	CMD_RTPRIV_IOCTL_80211_FRAG_THRESHOLD_ADD,
	CMD_RTPRIV_IOCTL_80211_CHANGE_BSS_PARM,
	CMD_RTPRIV_IOCTL_80211_AP_KEY_DEL,
	CMD_RTPRIV_IOCTL_80211_AP_PROBE_RSP_EXTRA_IE,
	CMD_RTPRIV_IOCTL_80211_AP_ASSOC_RSP_EXTRA_IE,
	CMD_RTPRIV_IOCTL_80211_PORT_SECURED,
	CMD_RTPRIV_IOCTL_80211_AP_STA_DEL,
	CMD_RTPRIV_IOCTL_80211_CANCEL_REMAIN_ON_CHAN_SET,
	CMD_RTPRIV_IOCTL_80211_BITRATE_SET,
	CMD_RTPRIV_IOCTL_80211_VIF_ADD,
	CMD_RTPRIV_IOCTL_80211_VIF_DEL,
	CMD_RTPRIV_IOCTL_80211_RESET,
	CMD_RTPRIV_IOCTL_80211_P2PCLI_ASSSOC_IE_SET,
	CMD_RTPRIV_IOCTL_80211_P2P_CLIENT_KEY_ADD,
	CMD_RTPRIV_IOCTL_80211_CHANNEL_RESTORE,
	CMD_RTPRIV_IOCTL_80211_SCAN_STATUS_LOCK_INIT,
	CMD_RTPRIV_IOCTL_80211_NETDEV_EVENT,
#ifdef RT_CFG80211_P2P_MULTI_CHAN_SUPPORT
	CMD_RTPRIV_IOCTL_MCC_DHCP_PROTECT_STATUS,
	CMD_RTPRIV_IOCTL_80211_SET_NOA,
#endif /* RT_CFG80211_P2P_MULTI_CHAN_SUPPORT */
#ifdef RT_CFG80211_ANDROID_PRIV_LIB_SUPPORT
	CMD_RTPRIV_IOCTL_80211_ANDROID_PRIV_CMD,
#endif /* RT_CFG80211_ANDROID_PRIV_LIB_SUPPORT */
#ifdef RT_P2P_SPECIFIC_WIRELESS_EVENT
	CMD_RTPRIV_IOCTL_80211_SEND_WIRELESS_EVENT,
#endif /* RT_P2P_SPECIFIC_WIRELESS_EVENT */
#ifdef CFG_TDLS_SUPPORT
	/* new TDLS */
	CMD_RTPRIV_IOCTL_80211_STA_TDLS_INSERT_PENTRY,
	CMD_RTPRIV_IOCTL_80211_STA_TDLS_SET_KEY_COPY_FLAG,
#endif
#ifdef APCLI_CFG80211_SUPPORT
	CMD_RTPRIV_IOCTL_APCLI_SITE_SURVEY,
#endif /* APCLI_CFG80211_SUPPORT */
	CMD_RTPRIV_IOCTL_80211_REGISTER,
	CMD_RTPRIV_IOCTL_80211_END,
#endif /* RT_CFG80211_SUPPORT */

	CMD_RTPRIV_IOCTL_ADAPTER_CSO_SUPPORT_TEST,
	CMD_RTPRIV_IOCTL_ADAPTER_TSO_SUPPORT_TEST,
#ifdef CONFIG_HAS_EARLYSUSPEND
	CMD_RTPRIV_IOCTL_LOAD_FIRMWARE_CHECK,
	CMD_RTPRIV_IOCTL_REGISTER_EARLYSUSPEND,
	CMD_RTPRIV_IOCTL_UNREGISTER_EARLYSUSPEND,
	CMD_RTPRIV_IOCTL_CHECK_EARLYSUSPEND,
	CMD_RTPRIV_IOCTL_OS_COOKIE_GET,
	CMD_RTPRIV_IOCTL_SET_SUSPEND_FLAG,
#endif
	CMD_RTPRIV_IOCTL_SDIO_INIT,
	CMD_RTPRIV_IOCTL_CHIP_PREPARE,
#ifdef PROFILE_PATH_DYNAMIC
	CMD_RTPRIV_IOCTL_PROFILEPATH_SET,
#endif /* PROFILE_PATH_DYNAMIC */
#ifdef APCLI_CFG80211_SUPPORT
	CMD_RTPRIV_IOCTL_APCLI_NETDEV_GET,
#endif /* APCLI_CFG80211_SUPPORT */
#ifdef DYNAMIC_VLAN_SUPPORT
	CMD_RTPRIV_IOCTL_SET_STA_VLAN,
#endif
#ifdef HOSTAPD_11R_SUPPORT
	CMD_RTPRIV_IOCTL_SET_FT_PARAM,
#endif /* HOSTAPD_11R_SUPPORT */
	/* can not exceed 0xa000 */
	CMD_RTPRIV_IOCTL_80211_COM_LATEST_ONE,
} CMD_RTPRIV_IOCTL_COMMON;

#ifdef RT_CFG80211_SUPPORT
typedef struct __CMD_RTPRIV_IOCTL_80211_VIF_SET {
	INT vifType;
	char vifName[IFNAMSIZ];
	INT vifNameLen;
} CMD_RTPRIV_IOCTL_80211_VIF_SET;

typedef struct __CMD_RTPRIV_IOCTL_80211_BSS_PARM {
	INT use_cts_prot;
	INT use_short_preamble;
	INT use_short_slot_time;
	UINT8 *basic_rates;
	UINT8 basic_rates_len;
	INT ap_isolate;
	INT ht_opmode;

} CMD_RTPRIV_IOCTL_80211_BSS_PARM;

typedef struct __CMD_RTPRIV_IOCTL_80211_BEACON {
	INT32 interval;
	INT32 dtim_period;
	UCHAR *beacon_head;
	UCHAR *beacon_tail;
	UINT32 beacon_head_len; /* Before TIM IE */
	UINT32 beacon_tail_len; /* After TIM IE */
	UINT32 apidx;
	PNET_DEV pNetDev;

#if (KERNEL_VERSION(3, 4, 0) <= LINUX_VERSION_CODE)
	UCHAR *beacon_ies;
	UINT32 beacon_ies_len;
	UCHAR *proberesp_ies;
	UINT32 proberesp_ies_len;
	UCHAR *assocresp_ies;
	UINT32 assocresp_ies_len;
	UCHAR *probe_resp;
	UINT32 probe_resp_len;
	ULONG ssid_len;
	CHAR ssid[32];
	UCHAR hidden_ssid;
	struct cfg80211_crypto_settings crypto;
	BOOLEAN privacy;
	UCHAR auth_type;
	INT32 inactivity_timeout;
#endif /* LINUX_VERSION_CODE: 3.4.0 */
} CMD_RTPRIV_IOCTL_80211_BEACON;

#define RT_CMD_80211_IFTYPE_UNSPECIFIED 0x00
#define RT_CMD_80211_IFTYPE_ADHOC 0x01
#define RT_CMD_80211_IFTYPE_STATION 0x02
#define RT_CMD_80211_IFTYPE_AP 0x03
#define RT_CMD_80211_IFTYPE_AP_VLAN 0x04
#define RT_CMD_80211_IFTYPE_WDS 0x05
#define RT_CMD_80211_IFTYPE_MONITOR 0x06
#define RT_CMD_80211_IFTYPE_P2P_CLIENT 0x08
#define RT_CMD_80211_IFTYPE_P2P_GO 0x09
#define RT_CMD_80211_IFTYPE_P2P_DEVICE 0x10

/* Must sync with nl80211_channel_type@nl80211.h */
#define RT_CMD_80211_CHANTYPE_NOHT 0x00
#define RT_CMD_80211_CHANTYPE_HT20 0x01
#define RT_CMD_80211_CHANTYPE_HT40MINUS 0x02
#define RT_CMD_80211_CHANTYPE_HT40PLUS 0x03
#define RT_CMD_80211_CHANTYPE_VHT80 0x04

typedef struct __CMD_RTPRIV_IOCTL_80211_CHAN {
	UINT8 ChanId;
	UINT8 CenterChanId;
	UINT8 IfType;
	UINT8 ChanType;

	UINT32 MonFilterFlag;

	UINT64 cookie;
	PVOID chan;
#if (KERNEL_VERSION(3, 6, 0) <= LINUX_VERSION_CODE)
	PWIRELESS_DEV pWdev;
#endif /* LINUX_VERSION_CODE: 3.6.0 */
} CMD_RTPRIV_IOCTL_80211_CHAN;

#define RT_CMD_80211_FILTER_FCSFAIL 0x01
#define RT_CMD_80211_FILTER_PLCPFAIL 0x02
#define RT_CMD_80211_FILTER_CONTROL 0x04
#define RT_CMD_80211_FILTER_OTHER_BSS 0x08

typedef struct __CMD_RTPRIV_IOCTL_80211_VIF_PARM {
	PNET_DEV net_dev;
	UINT8 newIfType;
	UINT8 oldIfType;

	UINT32 MonFilterFlag;

} CMD_RTPRIV_IOCTL_80211_VIF_PARM;

typedef struct __CMD_RTPRIV_IOCTL_80211_IBSS {
	UINT BeaconInterval;
	UCHAR Ssid[33];
	UINT privacy;
	PUCHAR BeaconExtraIe;
	UINT BeaconExtraIeLen;
} CMD_RTPRIV_IOCTL_80211_IBSS;

#define RT_CMD_80211_TXRATE_LEGACY 0x01
#define RT_CMD_80211_TXRATE_BW_40 0x02
#define RT_CMD_80211_TXRATE_SHORT_GI 0x04

typedef struct __CMD_RTPRIV_IOCTL_80211_STA {
	UINT8 MAC[MAC_ADDR_LEN];
	ULONG DataRate;

	UINT32 TxRateFlags;

	UINT32 TxRateMCS;
	INT32 Signal;
	UINT32 TxPacketCnt;
	UINT32 InactiveTime;

	UINT32 rx_packets;
	UINT32 tx_packets;
	UINT64 rx_bytes;
	UINT64 tx_bytes;
	UINT32 tx_retries;
	UINT32 tx_failed;
} CMD_RTPRIV_IOCTL_80211_STA;

#define RT_CMD_80211_KEY_WEP40 0x00
#define RT_CMD_80211_KEY_WEP104 0x01
#define RT_CMD_80211_KEY_WPA 0x02

#ifdef DOT11W_PMF_SUPPORT
#define RT_CMD_80211_KEY_AES_CMAC 0x03
#endif /* DOT11W_PMF_SUPPORT */

typedef struct __CMD_RTPRIV_IOCTL_80211_KEY {
	UINT8 KeyType;
	UINT8 KeyBuf[50];
	UINT8 KeyId;
	BOOLEAN bPairwise;
	UINT8 KeyLen;
	UINT32 cipher;
	UINT8 MAC[MAC_ADDR_LEN];
	PNET_DEV pNetDev;
} CMD_RTPRIV_IOCTL_80211_KEY;

#define RT_CMD_80211_CONN_ENCRYPT_NONE 0x01
#define RT_CMD_80211_CONN_ENCRYPT_WEP 0x02
#define RT_CMD_80211_CONN_ENCRYPT_TKIP 0x04
#define RT_CMD_80211_CONN_ENCRYPT_CCMP 0x08

typedef struct __CMD_RTPRIV_IOCTL_80211_CONNECT {
	UINT8 WpaVer;
	BOOLEAN FlgIs8021x;
	UINT8 AuthType;

	UINT8 PairwiseEncrypType;
	UINT8 GroupwiseEncrypType;

	UINT8 *pKey;
	UINT32 KeyLen;
	UINT8 KeyIdx;

	UINT8 *pSsid;
	UINT32 SsidLen;

	UINT8 *pBssid;

	BOOLEAN bWpsConnection;
	PNET_DEV pNetDev;
#ifdef DOT11W_PMF_SUPPORT
	BOOLEAN mfp;
#endif /* DOT11W_PMF_SUPPORT */
} CMD_RTPRIV_IOCTL_80211_CONNECT;

typedef struct __CMD_RTPRIV_IOCTL_80211_ASSOC_IE {
	PNET_DEV pNetDev;
	UINT8 *ie;
	UINT32 ie_len;
} CMD_RTPRIV_IOCTL_80211_ASSOC_IE;

typedef struct __CMD_RTPRIV_IOCTL_80211_REG_NOTIFY {
	UCHAR Alpha2[2];
	VOID *pWiphy;
} CMD_RTPRIV_IOCTL_80211_REG_NOTIFY;

typedef struct __CMD_RTPRIV_IOCTL_80211_SURVEY {
	VOID *pCfg80211;
	/*	UINT64 ChannelTime; */ /* idle + busy, not support */
	UINT64 ChannelTimeBusy;
	UINT64 ChannelTimeExtBusy;
} CMD_RTPRIV_IOCTL_80211_SURVEY;

#ifdef HOSTAPD_MAP_SUPPORT /* This could be a generic fix */
typedef struct __CMD_RTPRIV_IOCTL_AP_STA_DEL {
	IN UINT8 *pSta_MAC;
	IN struct wifi_dev *pWdev;
} CMD_RTPRIV_IOCTL_AP_STA_DEL;
#endif /* HOSTAPD_MAP_SUPPORT */
#endif /* RT_CFG80211_SUPPORT */

/* station commands */

/* when adding any new type, please also add codes in LINUX_WEVENT_TRANSLATE */
#define RT_WLAN_EVENT_CUSTOM 0x01
#define RT_WLAN_EVENT_CGIWAP 0x02
#define RT_WLAN_EVENT_ASSOC_REQ_IE 0x03
#define RT_WLAN_EVENT_SCAN 0x04
#define RT_WLAN_EVENT_EXPIRED 0x05
#define RT_WLAN_EVENT_SHOWPIN 0x06
#define RT_WLAN_EVENT_PIN 0x07

typedef struct __RT_CMD_RATE_SET {
	IN UINT32 Rate;
	IN UINT32 Fixed;
} RT_CMD_RATE_SET;

typedef struct __RT_CMD_PARAM_SET {
	IN RTMP_STRING *pThisChar;
	IN RTMP_STRING *pValue;
} RT_CMD_PARAM_SET;

typedef struct __RT_CMD_SHARED_KEY_ADD {
	IN UCHAR KeyIdx;
	IN BOOLEAN FlgHaveGTK;
} RT_CMD_SHARED_KEY_ADD;

typedef struct __RT_CMD_MBSS_KICKOUT {
	INT BssId;
	USHORT Reason;
} RT_CMD_MBSS_KICKOUT;

typedef struct __RT_CMD_USB_MORE_FLAG_CONFIG {
	UINT32 VendorID;
	UINT32 ProductID;
} RT_CMD_USB_MORE_FLAG_CONFIG;

typedef struct __RT_CMD_USB_DEV_CONFIG {
	UINT NumberOfPipes;
	UINT8 BulkInEpAddr[2];
	USHORT BulkInMaxPacketSize;
	UINT8 BulkOutEpAddr[6];
	USHORT BulkOutMaxPacketSize;
	VOID *pConfig;
} RT_CMD_USB_DEV_CONFIG;

typedef struct __RT_CMD_WAIT_QUEUE_LIST {
	RTMP_OS_TASK *pMlmeTask;
	RTMP_OS_TASK *pTimerTask;
	RTMP_OS_TASK *pCmdQTask;
	RTMP_OS_TASK *pWscTask;
} RT_CMD_WAIT_QUEUE_LIST;

typedef struct __RT_CMD_INF_UP_DOWN {
	IN int (*virtual_if_init_handler)(VOID *net_dev);
	IN int (*virtual_if_deinit_handler)(VOID *net_dev);
	IN int (*virtual_if_up_handler)(VOID *net_dev);
	IN int (*virtual_if_down_handler)(VOID *net_dev);
	PNET_DEV operation_dev_p;
} RT_CMD_INF_UP_DOWN;

typedef struct __RT_CMD_STATS {
	IN VOID *pNetDev;

	OUT VOID *pStats; /* point to pAd->stats */

	OUT unsigned long rx_packets; /* total packets received       */
	OUT unsigned long tx_packets; /* total packets transmitted */
	OUT unsigned long rx_bytes; /* total bytes received         */
	OUT unsigned long tx_bytes; /* total bytes transmitted      */
	OUT unsigned long rx_errors; /* bad packets received         */
	OUT unsigned long tx_errors; /* packet transmit problems     */
	OUT unsigned long multicast; /* multicast packets received */
	OUT unsigned long collisions;

	OUT unsigned long rx_over_errors; /* receiver ring buff overflow  */
	OUT unsigned long rx_crc_errors; /* recved pkt with crc error    */
	OUT unsigned long rx_frame_errors; /* recv'd frame alignment error */
	OUT unsigned long
		rx_fifo_errors; /* recv'r fifo overrun                  */
} RT_CMD_STATS;

typedef struct __RT_CMD_IW_STATS {
	ULONG priv_flags;
	UCHAR *dev_addr;

	VOID *pStats; /* point to pAd->iw_stats */

	UINT8 qual;
	UINT8 level;
	UINT8 noise;
	UINT8 updated;
} RT_CMD_IW_STATS;

typedef struct __RT_CMD_PCIE_INIT {
	VOID *pPciDev;
	UINT32 ConfigDeviceID;
	UINT32 ConfigSubsystemVendorID;
	UINT32 ConfigSubsystemID;
	BOOLEAN pci_init_succeed;
} RT_CMD_PCIE_INIT;

typedef struct __RT_CMD_AP_IOCTL_CONFIG {
	VOID *net_dev;
	VOID *wdev;
	ULONG priv_flags;
	char *pCmdData;
	INT32 CmdId_RTPRIV_IOCTL_SET;
	char *name;
	INT apidx;

	INT32 Status;
} RT_CMD_AP_IOCTL_CONFIG;

typedef struct __RT_CMD_IOCTL_INTERFACE_CONFIG {
	VOID *net_dev;
	VOID *wdev;
	ULONG priv_flags;
	char *name;
	INT interface_idx;

	INT32 Status;
} RT_CMD_IOCTL_INTERFACE_CONFIG;

typedef struct __RT_CMD_AP_IOCTL_SSID {
	ULONG priv_flags;
	INT apidx;

	char *pSsidStr;
	INT32 length;
} RT_CMD_AP_IOCTL_SSID;

#ifdef DYNAMIC_VLAN_SUPPORT
typedef struct __RT_CMD_AP_STA_VLAN {
	UCHAR sta_addr[6];
	UINT32 vlan_id;
} RT_CMD_AP_STA_VLAN;
#endif

#ifdef HOSTAPD_11R_SUPPORT
typedef struct __RT_CMD_AP_11R_PARAM {
	UCHAR nas_identifier[64];
	INT nas_id_len;
	UCHAR r1_key_holder[ETH_ALEN];
	UCHAR own_mac[ETH_ALEN];
	u32 reassociation_deadline;
} RT_CMD_AP_11R_PARAM;
#endif /* HOSTAPD_11R_SUPPORT */

typedef struct __RT_CMD_IOCTL_RATE {
	IN ULONG priv_flags;
	OUT UINT32 BitRate;
} RT_CMD_IOCTL_RATE;

#define RTMP_CMD_STA_MODE_AUTO 0x00
#define RTMP_CMD_STA_MODE_ADHOC 0x01
#define RTMP_CMD_STA_MODE_INFRA 0x02
#define RTMP_CMD_STA_MODE_MONITOR 0x03

typedef struct __RT_CMD_STA_IOCTL_FREQ {
	IN INT32 m; /* Mantissa */
	IN INT16 e; /* Exponent */
} RT_CMD_STA_IOCTL_FREQ;

typedef struct __RT_CMD_STA_IOCTL_BSS {
	OUT UCHAR Bssid[6];
	OUT UCHAR ChannelQuality;
	OUT CHAR Rssi;
	OUT CHAR Noise;
} RT_CMD_STA_IOCTL_BSS;

typedef struct __RT_CMD_STA_IOCTL_BSS_LIST {
	IN UINT32 MaxNum;
	OUT UINT32 BssNum;
	OUT RT_CMD_STA_IOCTL_BSS *pList;
} RT_CMD_STA_IOCTL_BSS_LIST;

typedef struct __RT_CMD_STA_IOCTL_SCAN {
	IN UCHAR FlgScanThisSsid;
	IN UINT32 SsidLen;
	IN CHAR *pSsid;
	IN UINT ScanType;
	OUT INT32 Status;
} RT_CMD_STA_IOCTL_SCAN;

typedef struct __RT_CMD_STA_IOCTL_BSS_TABLE {
	UCHAR Bssid[6];
	UCHAR Channel;
	UCHAR BssType;
	UCHAR HtCapabilityLen;

	UCHAR SupRate[12];
	UCHAR SupRateLen;
	UCHAR ExtRate[12];
	UCHAR ExtRateLen;

	UCHAR SsidLen;
	CHAR Ssid[32];

	USHORT CapabilityInfo;
	UCHAR ChannelWidth, ShortGIfor40, ShortGIfor20, MCSSet;

	USHORT WpaIeLen;
	UCHAR *pWpaIe;

	USHORT RsnIeLen;
	UCHAR *pRsnIe;

	USHORT WpsIeLen;
	UCHAR *pWpsIe;

	UCHAR FlgIsPrivacyOn;

	RT_CMD_STA_IOCTL_BSS Signal;
} RT_CMD_STA_IOCTL_BSS_TABLE;

typedef struct __RT_CMD_STA_IOCTL_SCAN_TABLE {
	ULONG priv_flags;
	UINT32 BssNr;
	RT_CMD_STA_IOCTL_BSS_TABLE *pBssTable; /* must be freed by caller */
	UCHAR MainSharedKey[4][16];
} RT_CMD_STA_IOCTL_SCAN_TABLE;

typedef struct __RT_CMD_STA_IOCTL_SSID {
	UCHAR FlgAnySsid;
	UINT32 SsidLen;
	CHAR *pSsid;
	INT32 Status;
} RT_CMD_STA_IOCTL_SSID;

typedef struct __RT_CMD_STA_IOCTL_NICK_NAME {
	UINT NameLen;
	CHAR *pName;
} RT_CMD_STA_IOCTL_NICK_NAME;

typedef struct __RT_CMD_STA_IOCTL_SECURITY {
	CHAR *pData;
	UINT16 length;
	INT32 KeyIdx;
	INT32 MaxKeyLen;

#define RT_CMD_STA_IOCTL_SECURITY_ALG_NONE 0x01
#define RT_CMD_STA_IOCTL_SECURITY_ALG_WEP 0x02
#define RT_CMD_STA_IOCTL_SECURITY_ALG_TKIP 0x03
#define RT_CMD_STA_IOCTL_SECURITY_ALG_CCMP 0x04
	UINT32 Alg;

#define RT_CMD_STA_IOCTL_SECURTIY_EXT_SET_TX_KEY 0x01
#define RT_CMD_STA_IOCTL_SECURTIY_EXT_GROUP_KEY 0x02
	UINT16 ext_flags;

#define RT_CMD_STA_IOCTL_SECURITY_DISABLED 0x01
#define RT_CMD_STA_IOCTL_SECURITY_ENABLED 0x02
#define RT_CMD_STA_IOCTL_SECURITY_RESTRICTED 0x04
#define RT_CMD_STA_IOCTL_SECURITY_OPEN 0x08
#define RT_CMD_STA_IOCTL_SECURITY_NOKEY 0x10
#define RT_CMD_STA_IOCTL_SECURITY_MODE 0x20
	UINT16 flags;

	INT32 Status;
} RT_CMD_STA_IOCTL_SECURITY;

typedef struct __RT_CMD_STA_IOCTL_WSC_U32_ITEM {
	IN UINT32 *pUWrq;
	OUT INT32 Status;
} RT_CMD_STA_IOCTL_WSC_U32_ITEM;

typedef struct __RT_CMD_STA_IOCTL_WSC_STR_ITEM {
	IN UINT32 Subcmd;
	IN CHAR *pData;
	IN UINT32 length;

	OUT INT32 Status;
} RT_CMD_STA_IOCTL_WSC_STR_ITEM;

typedef struct __RT_CMD_STA_IOCTL_SHOW {
	IN CHAR *pData;
	IN UINT32 MaxSize;
	IN UINT32 InfType;
} RT_CMD_STA_IOCTL_SHOW;

#define RT_CMD_STA_IOCTL_IW_MLME_DEAUTH 0x01
#define RT_CMD_STA_IOCTL_IW_MLME_DISASSOC 0x02

typedef struct __RT_CMD_STA_IOCTL_SECURITY_ADV {
#define RT_CMD_STA_IOCTL_WPA_VERSION 0x10
#define RT_CMD_STA_IOCTL_WPA_VERSION1 0x11
#define RT_CMD_STA_IOCTL_WPA_VERSION2 0x12

#define RT_CMD_STA_IOCTL_WPA_PAIRWISE 0x20
#define RT_CMD_STA_IOCTL_WPA_PAIRWISE_NONE 0x21
#define RT_CMD_STA_IOCTL_WPA_PAIRWISE_WEP40 0x22
#define RT_CMD_STA_IOCTL_WPA_PAIRWISE_WEP104 0x23
#define RT_CMD_STA_IOCTL_WPA_PAIRWISE_TKIP 0x24
#define RT_CMD_STA_IOCTL_WPA_PAIRWISE_CCMP 0x25

#define RT_CMD_STA_IOCTL_WPA_GROUP 0x30
#define RT_CMD_STA_IOCTL_WPA_GROUP_NONE 0x31
#define RT_CMD_STA_IOCTL_WPA_GROUP_WEP40 0x32
#define RT_CMD_STA_IOCTL_WPA_GROUP_WEP104 0x33
#define RT_CMD_STA_IOCTL_WPA_GROUP_TKIP 0x34
#define RT_CMD_STA_IOCTL_WPA_GROUP_CCMP 0x35

#define RT_CMD_STA_IOCTL_WPA_KEY_MGMT 0x40
#define RT_CMD_STA_IOCTL_WPA_KEY_MGMT_1X 0x41
#define RT_CMD_STA_IOCTL_WPA_KEY_MGMT_WPS 0x42

#define RT_CMD_STA_IOCTL_WPA_AUTH_RX_UNENCRYPTED_EAPOL 0x50
#define RT_CMD_STA_IOCTL_WPA_AUTH_PRIVACY_INVOKED 0x60
#define RT_CMD_STA_IOCTL_WPA_AUTH_DROP_UNENCRYPTED 0x70

#define RT_CMD_STA_IOCTL_WPA_AUTH_80211_AUTH_ALG 0x80
#define RT_CMD_STA_IOCTL_WPA_AUTH_80211_AUTH_ALG_SHARED 0x81
#define RT_CMD_STA_IOCTL_WPA_AUTH_80211_AUTH_ALG_OPEN 0x82
#define RT_CMD_STA_IOCTL_WPA_AUTH_80211_AUTH_ALG_LEAP 0x83

#define RT_CMD_STA_IOCTL_WPA_AUTH_WPA_ENABLED 0x90

#define RT_CMD_STA_IOCTL_WPA_AUTH_COUNTERMEASURES 0xA0

	UINT32 flags;
	UINT32 value;
} RT_CMD_STA_IOCTL_SECURITY_ADV;

typedef struct __RT_CMD_STA_IOCTL_RSN_IE {
	UINT32 length;
	UCHAR *pRsnIe;
} RT_CMD_STA_IOCTL_RSN_IE;

typedef struct __RT_CMD_STA_IOCTL_PMA_SA {
#define RT_CMD_STA_IOCTL_PMA_SA_FLUSH 0x01
#define RT_CMD_STA_IOCTL_PMA_SA_REMOVE 0x02
#define RT_CMD_STA_IOCTL_PMA_SA_ADD 0x03
	UINT32 Cmd;
	UCHAR *pBssid;
	UCHAR *pPmkid;
} RT_CMD_STA_IOCTL_PMA_SA;

typedef struct __RT_CMD_USB_INIT {
	VOID *pUsbDev;
	UINT32 driver_info;
} RT_CMD_USB_INIT;

#endif /* __RTMP_CMD_H__ */
