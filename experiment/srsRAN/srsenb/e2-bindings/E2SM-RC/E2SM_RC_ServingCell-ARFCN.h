/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-COMMON-IEs"
 * 	found in "../E2SM/e2sm-v02.01.asn1"
 * 	`asn1c -pdu=all -fcompound-names -gen-PER -no-gen-OER -no-gen-example -fno-include-deps -fincludes-quoted -D E2SM-RC/`
 */

#ifndef	_E2SM_RC_ServingCell_ARFCN_H_
#define	_E2SM_RC_ServingCell_ARFCN_H_


#include "asn_application.h"

/* Including external dependencies */
#include "E2SM_RC_NR-ARFCN.h"
#include "E2SM_RC_E-UTRA-ARFCN.h"
#include "constr_CHOICE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum E2SM_RC_ServingCell_ARFCN_PR {
	E2SM_RC_ServingCell_ARFCN_PR_NOTHING,	/* No components present */
	E2SM_RC_ServingCell_ARFCN_PR_nR,
	E2SM_RC_ServingCell_ARFCN_PR_eUTRA
	/* Extensions may appear below */
	
} E2SM_RC_ServingCell_ARFCN_PR;

/* E2SM_RC_ServingCell-ARFCN */
typedef struct E2SM_RC_ServingCell_ARFCN {
	E2SM_RC_ServingCell_ARFCN_PR present;
	union E2SM_RC_ServingCell_ARFCN_u {
		E2SM_RC_NR_ARFCN_t	 nR;
		E2SM_RC_E_UTRA_ARFCN_t	 eUTRA;
		/*
		 * This type is extensible,
		 * possible extensions are below.
		 */
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} E2SM_RC_ServingCell_ARFCN_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_E2SM_RC_ServingCell_ARFCN;
extern asn_CHOICE_specifics_t asn_SPC_E2SM_RC_ServingCell_ARFCN_specs_1;
extern asn_TYPE_member_t asn_MBR_E2SM_RC_ServingCell_ARFCN_1[2];
extern asn_per_constraints_t asn_PER_type_E2SM_RC_ServingCell_ARFCN_constr_1;

#ifdef __cplusplus
}
#endif

#endif	/* _E2SM_RC_ServingCell_ARFCN_H_ */
#include "asn_internal.h"
