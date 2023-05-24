/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-COMMON-IEs"
 * 	found in "../E2SM/e2sm-v02.01.asn1"
 * 	`asn1c -pdu=all -fcompound-names -gen-PER -no-gen-OER -no-gen-example -fno-include-deps -fincludes-quoted -D E2SM-RC/`
 */

#ifndef	_E2SM_RC_GlobalNgENB_ID_H_
#define	_E2SM_RC_GlobalNgENB_ID_H_


#include "asn_application.h"

/* Including external dependencies */
#include "E2SM_RC_PLMNIdentity.h"
#include "E2SM_RC_NgENB-ID.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* E2SM_RC_GlobalNgENB-ID */
typedef struct E2SM_RC_GlobalNgENB_ID {
	E2SM_RC_PLMNIdentity_t	 pLMNIdentity;
	E2SM_RC_NgENB_ID_t	 ngENB_ID;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} E2SM_RC_GlobalNgENB_ID_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_E2SM_RC_GlobalNgENB_ID;
extern asn_SEQUENCE_specifics_t asn_SPC_E2SM_RC_GlobalNgENB_ID_specs_1;
extern asn_TYPE_member_t asn_MBR_E2SM_RC_GlobalNgENB_ID_1[2];

#ifdef __cplusplus
}
#endif

#endif	/* _E2SM_RC_GlobalNgENB_ID_H_ */
#include "asn_internal.h"
