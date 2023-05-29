/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-COMMON-IEs"
 * 	found in "../E2SM/e2sm-v02.01.asn1"
 * 	`asn1c -pdu=all -fcompound-names -gen-PER -no-gen-OER -no-gen-example -fno-include-deps -fincludes-quoted -D E2SM-RC/`
 */

#ifndef	_E2SM_RC_RRC_MessageID_H_
#define	_E2SM_RC_RRC_MessageID_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NativeInteger.h"
#include "E2SM_RC_RRCclass-LTE.h"
#include "E2SM_RC_RRCclass-NR.h"
#include "constr_CHOICE.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum E2SM_RC_RRC_MessageID__rrcType_PR {
	E2SM_RC_RRC_MessageID__rrcType_PR_NOTHING,	/* No components present */
	E2SM_RC_RRC_MessageID__rrcType_PR_lTE,
	E2SM_RC_RRC_MessageID__rrcType_PR_nR
	/* Extensions may appear below */
	
} E2SM_RC_RRC_MessageID__rrcType_PR;

/* E2SM_RC_RRC-MessageID */
typedef struct E2SM_RC_RRC_MessageID {
	struct E2SM_RC_RRC_MessageID__rrcType {
		E2SM_RC_RRC_MessageID__rrcType_PR present;
		union E2SM_RC_RRC_MessageID__E2SM_RC_rrcType_u {
			E2SM_RC_RRCclass_LTE_t	 lTE;
			E2SM_RC_RRCclass_NR_t	 nR;
			/*
			 * This type is extensible,
			 * possible extensions are below.
			 */
		} choice;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} rrcType;
	long	 messageID;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} E2SM_RC_RRC_MessageID_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_E2SM_RC_RRC_MessageID;
extern asn_SEQUENCE_specifics_t asn_SPC_E2SM_RC_RRC_MessageID_specs_1;
extern asn_TYPE_member_t asn_MBR_E2SM_RC_RRC_MessageID_1[2];

#ifdef __cplusplus
}
#endif

#endif	/* _E2SM_RC_RRC_MessageID_H_ */
#include "asn_internal.h"