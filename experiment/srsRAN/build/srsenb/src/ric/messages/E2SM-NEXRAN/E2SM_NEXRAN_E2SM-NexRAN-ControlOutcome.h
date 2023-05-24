/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-NEXRAN-IEs"
 * 	found in "/home/cciadmin/Infocom2023-RIC-O-Demo/srsenb/src/ric/messages/asn1/e2sm-nexran-v01.00.asn1"
 * 	`asn1c -pdu=all -fcompound-names -gen-PER -no-gen-OER -no-gen-example -fno-include-deps -fincludes-quoted -D /home/cciadmin/Infocom2023-RIC-O-Demo/build/srsenb/src/ric/messages/E2SM-NEXRAN/`
 */

#ifndef	_E2SM_NEXRAN_E2SM_NexRAN_ControlOutcome_H_
#define	_E2SM_NEXRAN_E2SM_NexRAN_ControlOutcome_H_


#include "asn_application.h"

/* Including external dependencies */
#include "E2SM_NEXRAN_E2SM-NexRAN-ControlOutcome-Format1.h"
#include "constr_CHOICE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum E2SM_NEXRAN_E2SM_NexRAN_ControlOutcome_PR {
	E2SM_NEXRAN_E2SM_NexRAN_ControlOutcome_PR_NOTHING,	/* No components present */
	E2SM_NEXRAN_E2SM_NexRAN_ControlOutcome_PR_controlOutcomeFormat1
	/* Extensions may appear below */
	
} E2SM_NEXRAN_E2SM_NexRAN_ControlOutcome_PR;

/* E2SM_NEXRAN_E2SM-NexRAN-ControlOutcome */
typedef struct E2SM_NEXRAN_E2SM_NexRAN_ControlOutcome {
	E2SM_NEXRAN_E2SM_NexRAN_ControlOutcome_PR present;
	union E2SM_NEXRAN_E2SM_NexRAN_ControlOutcome_u {
		E2SM_NEXRAN_E2SM_NexRAN_ControlOutcome_Format1_t	 controlOutcomeFormat1;
		/*
		 * This type is extensible,
		 * possible extensions are below.
		 */
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} E2SM_NEXRAN_E2SM_NexRAN_ControlOutcome_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_E2SM_NEXRAN_E2SM_NexRAN_ControlOutcome;

#ifdef __cplusplus
}
#endif

#endif	/* _E2SM_NEXRAN_E2SM_NexRAN_ControlOutcome_H_ */
#include "asn_internal.h"
