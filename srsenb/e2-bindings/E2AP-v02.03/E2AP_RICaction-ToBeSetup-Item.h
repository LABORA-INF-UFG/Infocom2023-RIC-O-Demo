/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2AP-PDU-Contents"
 * 	found in "../e2ap-v02.03.asn1"
 * 	`asn1c -pdu=all -fcompound-names -fincludes-quoted -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D EXACT/`
 */

#ifndef	_E2AP_RICaction_ToBeSetup_Item_H_
#define	_E2AP_RICaction_ToBeSetup_Item_H_


#include "asn_application.h"

/* Including external dependencies */
#include "E2AP_RICactionID.h"
#include "E2AP_RICactionType.h"
#include "E2AP_RICactionDefinition.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct E2AP_RICsubsequentAction;

/* E2AP_RICaction-ToBeSetup-Item */
typedef struct E2AP_RICaction_ToBeSetup_Item {
	E2AP_RICactionID_t	 ricActionID;
	E2AP_RICactionType_t	 ricActionType;
	E2AP_RICactionDefinition_t	*ricActionDefinition;	/* OPTIONAL */
	struct E2AP_RICsubsequentAction	*ricSubsequentAction;	/* OPTIONAL */
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} E2AP_RICaction_ToBeSetup_Item_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_E2AP_RICaction_ToBeSetup_Item;

#ifdef __cplusplus
}
#endif

#endif	/* _E2AP_RICaction_ToBeSetup_Item_H_ */
#include "asn_internal.h"
