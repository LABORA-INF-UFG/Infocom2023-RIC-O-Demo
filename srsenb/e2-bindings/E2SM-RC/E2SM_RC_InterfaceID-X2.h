/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-COMMON-IEs"
 * 	found in "../E2SM/e2sm-v02.01.asn1"
 * 	`asn1c -pdu=all -fcompound-names -gen-PER -no-gen-OER -no-gen-example -fno-include-deps -fincludes-quoted -D E2SM-RC/`
 */

#ifndef	_E2SM_RC_InterfaceID_X2_H_
#define	_E2SM_RC_InterfaceID_X2_H_


#include "asn_application.h"

/* Including external dependencies */
#include "E2SM_RC_GlobalENB-ID.h"
#include "E2SM_RC_GlobalenGNB-ID.h"
#include "constr_CHOICE.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum E2SM_RC_InterfaceID_X2__nodeType_PR {
	E2SM_RC_InterfaceID_X2__nodeType_PR_NOTHING,	/* No components present */
	E2SM_RC_InterfaceID_X2__nodeType_PR_global_eNB_ID,
	E2SM_RC_InterfaceID_X2__nodeType_PR_global_en_gNB_ID
	/* Extensions may appear below */
	
} E2SM_RC_InterfaceID_X2__nodeType_PR;

/* E2SM_RC_InterfaceID-X2 */
typedef struct E2SM_RC_InterfaceID_X2 {
	struct E2SM_RC_InterfaceID_X2__nodeType {
		E2SM_RC_InterfaceID_X2__nodeType_PR present;
		union E2SM_RC_InterfaceID_X2__E2SM_RC_nodeType_u {
			E2SM_RC_GlobalENB_ID_t	 global_eNB_ID;
			E2SM_RC_GlobalenGNB_ID_t	 global_en_gNB_ID;
			/*
			 * This type is extensible,
			 * possible extensions are below.
			 */
		} choice;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} nodeType;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} E2SM_RC_InterfaceID_X2_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_E2SM_RC_InterfaceID_X2;
extern asn_SEQUENCE_specifics_t asn_SPC_E2SM_RC_InterfaceID_X2_specs_1;
extern asn_TYPE_member_t asn_MBR_E2SM_RC_InterfaceID_X2_1[1];

#ifdef __cplusplus
}
#endif

#endif	/* _E2SM_RC_InterfaceID_X2_H_ */
#include "asn_internal.h"
