/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2AP-IEs"
 * 	found in "../e2ap-v02.03.asn1"
 * 	`asn1c -pdu=all -fcompound-names -fincludes-quoted -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D EXACT/`
 */

#ifndef	_E2AP_RICsubsequentAction_H_
#define	_E2AP_RICsubsequentAction_H_


#include "asn_application.h"

/* Including external dependencies */
#include "E2AP_RICsubsequentActionType.h"
#include "E2AP_RICtimeToWait.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* E2AP_RICsubsequentAction */
typedef struct E2AP_RICsubsequentAction {
	E2AP_RICsubsequentActionType_t	 ricSubsequentActionType;
	E2AP_RICtimeToWait_t	 ricTimeToWait;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} E2AP_RICsubsequentAction_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_E2AP_RICsubsequentAction;
extern asn_SEQUENCE_specifics_t asn_SPC_E2AP_RICsubsequentAction_specs_1;
extern asn_TYPE_member_t asn_MBR_E2AP_RICsubsequentAction_1[2];

#ifdef __cplusplus
}
#endif

#endif	/* _E2AP_RICsubsequentAction_H_ */
#include "asn_internal.h"