/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2AP-PDU-Contents"
 * 	found in "../e2ap-v02.03.asn1"
 * 	`asn1c -pdu=all -fcompound-names -fincludes-quoted -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D EXACT/`
 */

#ifndef	_E2AP_RICsubscription_List_withCause_H_
#define	_E2AP_RICsubscription_List_withCause_H_


#include "asn_application.h"

/* Including external dependencies */
#include "asn_SEQUENCE_OF.h"
#include "constr_SEQUENCE_OF.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct E2AP_ProtocolIE_SingleContainer;

/* E2AP_RICsubscription-List-withCause */
typedef struct E2AP_RICsubscription_List_withCause {
	A_SEQUENCE_OF(struct E2AP_ProtocolIE_SingleContainer) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} E2AP_RICsubscription_List_withCause_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_E2AP_RICsubscription_List_withCause;

#ifdef __cplusplus
}
#endif

#endif	/* _E2AP_RICsubscription_List_withCause_H_ */
#include "asn_internal.h"
