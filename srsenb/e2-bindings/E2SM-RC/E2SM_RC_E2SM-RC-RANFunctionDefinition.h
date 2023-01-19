/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-RC-IEs"
 * 	found in "e2sm-rc-v01.03.asn1"
 * 	`asn1c -pdu=all -fcompound-names -gen-PER -no-gen-OER -no-gen-example -fno-include-deps -fincludes-quoted -D E2SM-RC/`
 */

#ifndef	_E2SM_RC_E2SM_RC_RANFunctionDefinition_H_
#define	_E2SM_RC_E2SM_RC_RANFunctionDefinition_H_


#include "asn_application.h"

/* Including external dependencies */
#include "E2SM_RC_RANfunction-Name.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct E2SM_RC_RANFunctionDefinition_EventTrigger;
struct E2SM_RC_RANFunctionDefinition_Report;
struct E2SM_RC_RANFunctionDefinition_Insert;
struct E2SM_RC_RANFunctionDefinition_Control;
struct E2SM_RC_RANFunctionDefinition_Policy;

/* E2SM_RC_E2SM-RC-RANFunctionDefinition */
typedef struct E2SM_RC_E2SM_RC_RANFunctionDefinition {
	E2SM_RC_RANfunction_Name_t	 ranFunction_Name;
	struct E2SM_RC_RANFunctionDefinition_EventTrigger	*ranFunctionDefinition_EventTrigger;	/* OPTIONAL */
	struct E2SM_RC_RANFunctionDefinition_Report	*ranFunctionDefinition_Report;	/* OPTIONAL */
	struct E2SM_RC_RANFunctionDefinition_Insert	*ranFunctionDefinition_Insert;	/* OPTIONAL */
	struct E2SM_RC_RANFunctionDefinition_Control	*ranFunctionDefinition_Control;	/* OPTIONAL */
	struct E2SM_RC_RANFunctionDefinition_Policy	*ranFunctionDefinition_Policy;	/* OPTIONAL */
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} E2SM_RC_E2SM_RC_RANFunctionDefinition_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_E2SM_RC_E2SM_RC_RANFunctionDefinition;

#ifdef __cplusplus
}
#endif

#endif	/* _E2SM_RC_E2SM_RC_RANFunctionDefinition_H_ */
#include "asn_internal.h"
