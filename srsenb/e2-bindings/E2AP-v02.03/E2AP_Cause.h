/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2AP-IEs"
 * 	found in "../e2ap-v02.03.asn1"
 * 	`asn1c -pdu=all -fcompound-names -fincludes-quoted -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D EXACT/`
 */

#ifndef	_E2AP_Cause_H_
#define	_E2AP_Cause_H_


#include "asn_application.h"

/* Including external dependencies */
#include "E2AP_CauseRICrequest.h"
#include "E2AP_CauseRICservice.h"
#include "E2AP_CauseE2node.h"
#include "E2AP_CauseTransport.h"
#include "E2AP_CauseProtocol.h"
#include "E2AP_CauseMisc.h"
#include "constr_CHOICE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum E2AP_Cause_PR {
	E2AP_Cause_PR_NOTHING,	/* No components present */
	E2AP_Cause_PR_ricRequest,
	E2AP_Cause_PR_ricService,
	E2AP_Cause_PR_e2Node,
	E2AP_Cause_PR_transport,
	E2AP_Cause_PR_protocol,
	E2AP_Cause_PR_misc
	/* Extensions may appear below */
	
} E2AP_Cause_PR;

/* E2AP_Cause */
typedef struct E2AP_Cause {
	E2AP_Cause_PR present;
	union E2AP_Cause_u {
		E2AP_CauseRICrequest_t	 ricRequest;
		E2AP_CauseRICservice_t	 ricService;
		E2AP_CauseE2node_t	 e2Node;
		E2AP_CauseTransport_t	 transport;
		E2AP_CauseProtocol_t	 protocol;
		E2AP_CauseMisc_t	 misc;
		/*
		 * This type is extensible,
		 * possible extensions are below.
		 */
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} E2AP_Cause_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_E2AP_Cause;
extern asn_CHOICE_specifics_t asn_SPC_E2AP_Cause_specs_1;
extern asn_TYPE_member_t asn_MBR_E2AP_Cause_1[6];
extern asn_per_constraints_t asn_PER_type_E2AP_Cause_constr_1;

#ifdef __cplusplus
}
#endif

#endif	/* _E2AP_Cause_H_ */
#include "asn_internal.h"
