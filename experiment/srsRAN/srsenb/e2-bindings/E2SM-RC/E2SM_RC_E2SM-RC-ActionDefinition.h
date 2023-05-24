/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-RC-IEs"
 * 	found in "e2sm-rc-v01.03.asn1"
 * 	`asn1c -pdu=all -fcompound-names -gen-PER -no-gen-OER -no-gen-example -fno-include-deps -fincludes-quoted -D E2SM-RC/`
 */

#ifndef	_E2SM_RC_E2SM_RC_ActionDefinition_H_
#define	_E2SM_RC_E2SM_RC_ActionDefinition_H_


#include "asn_application.h"

/* Including external dependencies */
#include "E2SM_RC_RIC-Style-Type.h"
#include "E2SM_RC_E2SM-RC-ActionDefinition-Format1.h"
#include "E2SM_RC_E2SM-RC-ActionDefinition-Format2.h"
#include "E2SM_RC_E2SM-RC-ActionDefinition-Format3.h"
#include "E2SM_RC_E2SM-RC-ActionDefinition-Format4.h"
#include "constr_CHOICE.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum E2SM_RC_E2SM_RC_ActionDefinition__ric_actionDefinition_formats_PR {
	E2SM_RC_E2SM_RC_ActionDefinition__ric_actionDefinition_formats_PR_NOTHING,	/* No components present */
	E2SM_RC_E2SM_RC_ActionDefinition__ric_actionDefinition_formats_PR_actionDefinition_Format1,
	E2SM_RC_E2SM_RC_ActionDefinition__ric_actionDefinition_formats_PR_actionDefinition_Format2,
	E2SM_RC_E2SM_RC_ActionDefinition__ric_actionDefinition_formats_PR_actionDefinition_Format3,
	/* Extensions may appear below */
	E2SM_RC_E2SM_RC_ActionDefinition__ric_actionDefinition_formats_PR_actionDefinition_Format4
} E2SM_RC_E2SM_RC_ActionDefinition__ric_actionDefinition_formats_PR;

/* E2SM_RC_E2SM-RC-ActionDefinition */
typedef struct E2SM_RC_E2SM_RC_ActionDefinition {
	E2SM_RC_RIC_Style_Type_t	 ric_Style_Type;
	struct E2SM_RC_E2SM_RC_ActionDefinition__ric_actionDefinition_formats {
		E2SM_RC_E2SM_RC_ActionDefinition__ric_actionDefinition_formats_PR present;
		union E2SM_RC_E2SM_RC_ActionDefinition__E2SM_RC_ric_actionDefinition_formats_u {
			E2SM_RC_E2SM_RC_ActionDefinition_Format1_t	 actionDefinition_Format1;
			E2SM_RC_E2SM_RC_ActionDefinition_Format2_t	 actionDefinition_Format2;
			E2SM_RC_E2SM_RC_ActionDefinition_Format3_t	 actionDefinition_Format3;
			/*
			 * This type is extensible,
			 * possible extensions are below.
			 */
			E2SM_RC_E2SM_RC_ActionDefinition_Format4_t	 actionDefinition_Format4;
		} choice;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} ric_actionDefinition_formats;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} E2SM_RC_E2SM_RC_ActionDefinition_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_E2SM_RC_E2SM_RC_ActionDefinition;

#ifdef __cplusplus
}
#endif

#endif	/* _E2SM_RC_E2SM_RC_ActionDefinition_H_ */
#include "asn_internal.h"
