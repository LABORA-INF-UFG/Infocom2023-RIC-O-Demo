/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-COMMON-IEs"
 * 	found in "../E2SM/e2sm-v02.01.asn1"
 * 	`asn1c -pdu=all -fcompound-names -gen-PER -no-gen-OER -no-gen-example -fno-include-deps -fincludes-quoted -D E2SM-RC/`
 */

#ifndef	_E2SM_RC_UEID_ENB_H_
#define	_E2SM_RC_UEID_ENB_H_


#include "asn_application.h"

/* Including external dependencies */
#include "E2SM_RC_MME-UE-S1AP-ID.h"
#include "E2SM_RC_GUMMEI.h"
#include "E2SM_RC_ENB-UE-X2AP-ID.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct E2SM_RC_GlobalENB_ID;

/* E2SM_RC_UEID-ENB */
typedef struct E2SM_RC_UEID_ENB {
	E2SM_RC_MME_UE_S1AP_ID_t	 mME_UE_S1AP_ID;
	E2SM_RC_GUMMEI_t	 gUMMEI;
	E2SM_RC_ENB_UE_X2AP_ID_t	*m_eNB_UE_X2AP_ID;	/* OPTIONAL */
	struct E2SM_RC_GlobalENB_ID	*globalENB_ID;	/* OPTIONAL */
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} E2SM_RC_UEID_ENB_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_E2SM_RC_UEID_ENB;
extern asn_SEQUENCE_specifics_t asn_SPC_E2SM_RC_UEID_ENB_specs_1;
extern asn_TYPE_member_t asn_MBR_E2SM_RC_UEID_ENB_1[4];

#ifdef __cplusplus
}
#endif

#endif	/* _E2SM_RC_UEID_ENB_H_ */
#include "asn_internal.h"