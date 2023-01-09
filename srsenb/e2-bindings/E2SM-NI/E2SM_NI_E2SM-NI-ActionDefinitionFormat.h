/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-NI-IEs"
 * 	found in "/local/mnt/openairinterface5g/openair2/RIC_AGENT/MESSAGES/ASN1/R01/e2sm-ni-v01.00.asn1"
 * 	`asn1c -pdu=all -fcompound-names -gen-PER -no-gen-OER -no-gen-example -fno-include-deps -fincludes-quoted -D /local/mnt/openairinterface5g/cmake_targets/ran_build/build/CMakeFiles/E2SM-NI/`
 */

#ifndef	_E2SM_NI_E2SM_NI_ActionDefinitionFormat_H_
#define	_E2SM_NI_E2SM_NI_ActionDefinitionFormat_H_


#include "asn_application.h"

/* Including external dependencies */
#include "E2SM_NI_E2SM-NI-ActionDefinition-Format1.h"
#include "E2SM_NI_E2SM-NI-ActionDefinition-Format2.h"
#include "constr_CHOICE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum E2SM_NI_E2SM_NI_ActionDefinitionFormat_PR {
	E2SM_NI_E2SM_NI_ActionDefinitionFormat_PR_NOTHING,	/* No components present */
	E2SM_NI_E2SM_NI_ActionDefinitionFormat_PR_actionDefinition_Format1,
	E2SM_NI_E2SM_NI_ActionDefinitionFormat_PR_actionDefinition_Format2
	/* Extensions may appear below */
	
} E2SM_NI_E2SM_NI_ActionDefinitionFormat_PR;

/* E2SM_NI_E2SM-NI-ActionDefinitionFormat */
typedef struct E2SM_NI_E2SM_NI_ActionDefinitionFormat {
	E2SM_NI_E2SM_NI_ActionDefinitionFormat_PR present;
	union E2SM_NI_E2SM_NI_ActionDefinitionFormat_u {
		E2SM_NI_E2SM_NI_ActionDefinition_Format1_t	 actionDefinition_Format1;
		E2SM_NI_E2SM_NI_ActionDefinition_Format2_t	 actionDefinition_Format2;
		/*
		 * This type is extensible,
		 * possible extensions are below.
		 */
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} E2SM_NI_E2SM_NI_ActionDefinitionFormat_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_E2SM_NI_E2SM_NI_ActionDefinitionFormat;
extern asn_CHOICE_specifics_t asn_SPC_E2SM_NI_E2SM_NI_ActionDefinitionFormat_specs_1;
extern asn_TYPE_member_t asn_MBR_E2SM_NI_E2SM_NI_ActionDefinitionFormat_1[2];
extern asn_per_constraints_t asn_PER_type_E2SM_NI_E2SM_NI_ActionDefinitionFormat_constr_1;

#ifdef __cplusplus
}
#endif

#endif	/* _E2SM_NI_E2SM_NI_ActionDefinitionFormat_H_ */
#include "asn_internal.h"
