
/*
 ***************************************************************************
 * Ralink Tech Inc.
 * 4F, No. 2 Technology 5th Rd.
 * Science-based Industrial Park
 * Hsin-chu, Taiwan, R.O.C.
 *
 * (c) Copyright 2002-2006, Ralink Technology, Inc.
 *
 * All rights reserved.	Ralink's source	code is	an unpublished work	and	the
 * use of a	copyright notice does not imply	otherwise. This	source code
 * contains	confidential trade secret material of Ralink Tech. Any attemp
 * or participation	in deciphering,	decoding, reverse engineering or in	any
 * way altering	the	source code	is stricitly prohibited, unless	the	prior
 * written consent of Ralink Technology, Inc. is obtained.
 ***************************************************************************/

/****************************************************************************
	Abstract:

***************************************************************************/

#ifdef DOT11K_RRM_SUPPORT

#include "rt_config.h"

/*
	==========================================================================
	Description:

	Parametrs:

	Return	: None.
	==========================================================================
 */
BOOLEAN RRM_PeerNeighborReqSanity(IN PRTMP_ADAPTER pAd, IN VOID *pMsg,
				  IN ULONG MsgLen, OUT PUINT8 pDialogToken,
				  OUT PCHAR *pSsid, OUT PUINT8 pSsidLen)
{
	PFRAME_802_11 Fr = (PFRAME_802_11)pMsg;
	PUCHAR pFramePtr;
	BOOLEAN result = FALSE;
	PEID_STRUCT eid_ptr;
	PMAC_TABLE_ENTRY pEntry;
	PRRM_CONFIG pRrmCfg;
	UINT8 PeerMeasurementType;

	if ((Fr == NULL) || (pDialogToken == NULL))
		return result;

	MsgLen -= sizeof(HEADER_802_11);
	/* skip category and action code. */
	pFramePtr = Fr->Octet;
	pFramePtr += 2;
	MsgLen -= 2;

	pEntry = MacTableLookup(pAd, Fr->Hdr.Addr2);
	if ((pEntry == NULL) || (pEntry->func_tb_idx > pAd->ApCfg.BssidNum))
		return result;

	pRrmCfg = &pAd->ApCfg.MBSSID[pEntry->func_tb_idx].wdev.RrmCfg;
	*pSsid = pAd->ApCfg.MBSSID[pEntry->func_tb_idx].Ssid;
	*pSsidLen = pAd->ApCfg.MBSSID[pEntry->func_tb_idx].SsidLen;
	result = TRUE;
	NdisMoveMemory(pDialogToken, pFramePtr, 1);
	pFramePtr += 1;
	MsgLen -= 1;
	eid_ptr = (PEID_STRUCT)pFramePtr;

	while (((UCHAR *)eid_ptr + eid_ptr->Len + 1) <
	       ((PUCHAR)pFramePtr + MsgLen)) {
		switch (eid_ptr->Eid) {
		case RRM_NEIGHBOR_REQ_SSID_SUB_ID:
			*pSsid = (PCHAR)eid_ptr->Octet;
			*pSsidLen = eid_ptr->Len;
			break;
		case RRM_NEIGHBOR_REQ_MEASUREMENT_REQUEST_SUB_ID:
			MTWF_LOG(DBG_CAT_ALL, DBG_SUBCAT_ALL, DBG_LVL_TRACE,
				 ("%s - Got STA Measurement Request\n",
				  __func__));
			pRrmCfg->PeerMeasurementToken = eid_ptr->Octet[0];
			PeerMeasurementType = eid_ptr->Octet[2];
			switch (PeerMeasurementType) {
			case RRM_MEASURE_SUBTYPE_LCI:
				pRrmCfg->bPeerReqLCI = TRUE;
				MTWF_LOG(
					DBG_CAT_ALL, DBG_SUBCAT_ALL,
					DBG_LVL_TRACE,
					("%s - STA Request LCI Measurement Report\n",
					 __func__));
				break;
			case RRM_MEASURE_SUBTYPE_LOCATION_CIVIC:
				pRrmCfg->bPeerReqCIVIC = TRUE;
				MTWF_LOG(
					DBG_CAT_ALL, DBG_SUBCAT_ALL,
					DBG_LVL_TRACE,
					("%s - STA Request CIVIC Measurement Report\n",
					 __func__));
				break;
			default:
				MTWF_LOG(DBG_CAT_ALL, DBG_SUBCAT_ALL,
					 DBG_LVL_TRACE,
					 ("unknown PeerMeasurementType: %d\n",
					  PeerMeasurementType));
			}
			break;

		case RRM_NEIGHBOR_REQ_VENDOR_SUB_ID:
			break;

		default:
			MTWF_LOG(DBG_CAT_ALL, DBG_SUBCAT_ALL, DBG_LVL_ERROR,
				 ("unknown Eid: %d\n", eid_ptr->Eid));
			break;
		}

		eid_ptr = (PEID_STRUCT)((UCHAR *)eid_ptr + 2 + eid_ptr->Len);
	}

	return result;
}

BOOLEAN RRM_PeerMeasureReportSanity(IN PRTMP_ADAPTER pAd, IN VOID *pMsg,
				    IN ULONG MsgLen, OUT PUINT8 pDialogToken,
				    OUT PMEASURE_REPORT_INFO pMeasureReportInfo,
				    OUT PVOID *pMeasureRep)
{
	PFRAME_802_11 Fr = (PFRAME_802_11)pMsg;
	PUCHAR pFramePtr = Fr->Octet;
	BOOLEAN result = FALSE;
	PEID_STRUCT eid_ptr;
	/* skip 802.11 header. */
	MsgLen -= sizeof(HEADER_802_11);
	/* skip category and action code. */
	pFramePtr += 2;
	MsgLen -= 2;

	if (pMeasureReportInfo == NULL)
		return result;

	NdisMoveMemory(pDialogToken, pFramePtr, 1);
	pFramePtr += 1;
	MsgLen -= 1;
	eid_ptr = (PEID_STRUCT)pFramePtr;

	while (((UCHAR *)eid_ptr + eid_ptr->Len + 1) <
	       ((PUCHAR)pFramePtr + MsgLen)) {
		switch (eid_ptr->Eid) {
		case IE_MEASUREMENT_REPORT:
			NdisMoveMemory(&pMeasureReportInfo->Token,
				       eid_ptr->Octet, 1);
			NdisMoveMemory(&pMeasureReportInfo->ReportMode,
				       eid_ptr->Octet + 1, 1);
			NdisMoveMemory(&pMeasureReportInfo->ReportType,
				       eid_ptr->Octet + 2, 1);
			*pMeasureRep = (PVOID)(eid_ptr->Octet + 3);
			result = TRUE;
			break;

		default:
			break;
		}

		eid_ptr = (PEID_STRUCT)((UCHAR *)eid_ptr + 2 + eid_ptr->Len);
	}

	return result;
}

#endif /* DOT11K_RRM_SUPPORT */
