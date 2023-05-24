/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2AP-IEs"
 * 	found in "../e2ap-v02.03.asn1"
 * 	`asn1c -pdu=all -fcompound-names -fincludes-quoted -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D EXACT/`
 */

#ifndef	_E2AP_E2nodeComponentID_H_
#define	_E2AP_E2nodeComponentID_H_


#include "asn_application.h"

/* Including external dependencies */
#include "E2AP_E2nodeComponentInterfaceNG.h"
#include "E2AP_E2nodeComponentInterfaceXn.h"
#include "E2AP_E2nodeComponentInterfaceE1.h"
#include "E2AP_E2nodeComponentInterfaceF1.h"
#include "E2AP_E2nodeComponentInterfaceW1.h"
#include "E2AP_E2nodeComponentInterfaceS1.h"
#include "E2AP_E2nodeComponentInterfaceX2.h"
#include "constr_CHOICE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum E2AP_E2nodeComponentID_PR {
	E2AP_E2nodeComponentID_PR_NOTHING,	/* No components present */
	E2AP_E2nodeComponentID_PR_e2nodeComponentInterfaceTypeNG,
	E2AP_E2nodeComponentID_PR_e2nodeComponentInterfaceTypeXn,
	E2AP_E2nodeComponentID_PR_e2nodeComponentInterfaceTypeE1,
	E2AP_E2nodeComponentID_PR_e2nodeComponentInterfaceTypeF1,
	E2AP_E2nodeComponentID_PR_e2nodeComponentInterfaceTypeW1,
	E2AP_E2nodeComponentID_PR_e2nodeComponentInterfaceTypeS1,
	E2AP_E2nodeComponentID_PR_e2nodeComponentInterfaceTypeX2
	/* Extensions may appear below */
	
} E2AP_E2nodeComponentID_PR;

/* E2AP_E2nodeComponentID */
typedef struct E2AP_E2nodeComponentID {
	E2AP_E2nodeComponentID_PR present;
	union E2AP_E2nodeComponentID_u {
		E2AP_E2nodeComponentInterfaceNG_t	 e2nodeComponentInterfaceTypeNG;
		E2AP_E2nodeComponentInterfaceXn_t	 e2nodeComponentInterfaceTypeXn;
		E2AP_E2nodeComponentInterfaceE1_t	 e2nodeComponentInterfaceTypeE1;
		E2AP_E2nodeComponentInterfaceF1_t	 e2nodeComponentInterfaceTypeF1;
		E2AP_E2nodeComponentInterfaceW1_t	 e2nodeComponentInterfaceTypeW1;
		E2AP_E2nodeComponentInterfaceS1_t	 e2nodeComponentInterfaceTypeS1;
		E2AP_E2nodeComponentInterfaceX2_t	 e2nodeComponentInterfaceTypeX2;
		/*
		 * This type is extensible,
		 * possible extensions are below.
		 */
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} E2AP_E2nodeComponentID_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_E2AP_E2nodeComponentID;
extern asn_CHOICE_specifics_t asn_SPC_E2AP_E2nodeComponentID_specs_1;
extern asn_TYPE_member_t asn_MBR_E2AP_E2nodeComponentID_1[7];
extern asn_per_constraints_t asn_PER_type_E2AP_E2nodeComponentID_constr_1;

#ifdef __cplusplus
}
#endif

#endif	/* _E2AP_E2nodeComponentID_H_ */
#include "asn_internal.h"
