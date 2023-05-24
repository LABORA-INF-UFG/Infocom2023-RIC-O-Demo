/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-RC-IEs"
 * 	found in "e2sm-rc-v01.03.asn1"
 * 	`asn1c -pdu=all -fcompound-names -gen-PER -no-gen-OER -no-gen-example -fno-include-deps -fincludes-quoted -D E2SM-RC/`
 */

#ifndef	_E2SM_RC_CallProcessBreakpoint_RANParameter_Item_H_
#define	_E2SM_RC_CallProcessBreakpoint_RANParameter_Item_H_


#include "asn_application.h"

/* Including external dependencies */
#include "E2SM_RC_RANParameter-ID.h"
#include "E2SM_RC_RANParameter-Name.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct E2SM_RC_RANParameter_Definition;

/* E2SM_RC_CallProcessBreakpoint-RANParameter-Item */
typedef struct E2SM_RC_CallProcessBreakpoint_RANParameter_Item {
	E2SM_RC_RANParameter_ID_t	 ranParameter_ID;
	E2SM_RC_RANParameter_Name_t	 ranParameter_name;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	struct E2SM_RC_RANParameter_Definition	*ranParameter_Definition;	/* OPTIONAL */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} E2SM_RC_CallProcessBreakpoint_RANParameter_Item_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_E2SM_RC_CallProcessBreakpoint_RANParameter_Item;
extern asn_SEQUENCE_specifics_t asn_SPC_E2SM_RC_CallProcessBreakpoint_RANParameter_Item_specs_1;
extern asn_TYPE_member_t asn_MBR_E2SM_RC_CallProcessBreakpoint_RANParameter_Item_1[3];

#ifdef __cplusplus
}
#endif

#endif	/* _E2SM_RC_CallProcessBreakpoint_RANParameter_Item_H_ */
#include "asn_internal.h"
