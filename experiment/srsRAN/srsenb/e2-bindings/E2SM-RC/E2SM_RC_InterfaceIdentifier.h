/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-COMMON-IEs"
 * 	found in "../E2SM/e2sm-v02.01.asn1"
 * 	`asn1c -pdu=all -fcompound-names -gen-PER -no-gen-OER -no-gen-example -fno-include-deps -fincludes-quoted -D E2SM-RC/`
 */

#ifndef	_E2SM_RC_InterfaceIdentifier_H_
#define	_E2SM_RC_InterfaceIdentifier_H_


#include "asn_application.h"

/* Including external dependencies */
#include "E2SM_RC_InterfaceID-NG.h"
#include "E2SM_RC_InterfaceID-Xn.h"
#include "E2SM_RC_InterfaceID-F1.h"
#include "E2SM_RC_InterfaceID-E1.h"
#include "E2SM_RC_InterfaceID-S1.h"
#include "E2SM_RC_InterfaceID-X2.h"
#include "E2SM_RC_InterfaceID-W1.h"
#include "constr_CHOICE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum E2SM_RC_InterfaceIdentifier_PR {
	E2SM_RC_InterfaceIdentifier_PR_NOTHING,	/* No components present */
	E2SM_RC_InterfaceIdentifier_PR_nG,
	E2SM_RC_InterfaceIdentifier_PR_xN,
	E2SM_RC_InterfaceIdentifier_PR_f1,
	E2SM_RC_InterfaceIdentifier_PR_e1,
	E2SM_RC_InterfaceIdentifier_PR_s1,
	E2SM_RC_InterfaceIdentifier_PR_x2,
	E2SM_RC_InterfaceIdentifier_PR_w1
	/* Extensions may appear below */
	
} E2SM_RC_InterfaceIdentifier_PR;

/* E2SM_RC_InterfaceIdentifier */
typedef struct E2SM_RC_InterfaceIdentifier {
	E2SM_RC_InterfaceIdentifier_PR present;
	union E2SM_RC_InterfaceIdentifier_u {
		E2SM_RC_InterfaceID_NG_t	 nG;
		E2SM_RC_InterfaceID_Xn_t	 xN;
		E2SM_RC_InterfaceID_F1_t	 f1;
		E2SM_RC_InterfaceID_E1_t	 e1;
		E2SM_RC_InterfaceID_S1_t	 s1;
		E2SM_RC_InterfaceID_X2_t	 x2;
		E2SM_RC_InterfaceID_W1_t	 w1;
		/*
		 * This type is extensible,
		 * possible extensions are below.
		 */
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} E2SM_RC_InterfaceIdentifier_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_E2SM_RC_InterfaceIdentifier;
extern asn_CHOICE_specifics_t asn_SPC_E2SM_RC_InterfaceIdentifier_specs_1;
extern asn_TYPE_member_t asn_MBR_E2SM_RC_InterfaceIdentifier_1[7];
extern asn_per_constraints_t asn_PER_type_E2SM_RC_InterfaceIdentifier_constr_1;

#ifdef __cplusplus
}
#endif

#endif	/* _E2SM_RC_InterfaceIdentifier_H_ */
#include "asn_internal.h"