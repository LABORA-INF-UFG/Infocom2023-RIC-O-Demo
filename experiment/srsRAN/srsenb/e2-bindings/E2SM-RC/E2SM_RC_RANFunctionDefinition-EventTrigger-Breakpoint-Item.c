/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-RC-IEs"
 * 	found in "e2sm-rc-v01.03.asn1"
 * 	`asn1c -pdu=all -fcompound-names -gen-PER -no-gen-OER -no-gen-example -fno-include-deps -fincludes-quoted -D E2SM-RC/`
 */

#include "E2SM_RC_RANFunctionDefinition-EventTrigger-Breakpoint-Item.h"

#include "E2SM_RC_CallProcessBreakpoint-RANParameter-Item.h"
static int
memb_E2SM_RC_ran_CallProcessBreakpointParameters_List_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	size_t size;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	/* Determine the number of elements */
	size = _A_CSEQUENCE_FROM_VOID(sptr)->count;
	
	if((size >= 1 && size <= 65535)) {
		/* Perform validation of the inner elements */
		return td->encoding_constraints.general_constraints(td, sptr, ctfailcb, app_key);
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static asn_per_constraints_t asn_PER_type_E2SM_RC_ran_CallProcessBreakpointParameters_List_constr_4 CC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 16,  16,  1,  65535 }	/* (SIZE(1..65535)) */,
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_E2SM_RC_ran_CallProcessBreakpointParameters_List_constr_4 CC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 16,  16,  1,  65535 }	/* (SIZE(1..65535)) */,
	0, 0	/* No PER value map */
};
static asn_TYPE_member_t asn_MBR_E2SM_RC_ran_CallProcessBreakpointParameters_List_4[] = {
	{ ATF_POINTER, 0, 0,
		(ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
		0,
		&asn_DEF_E2SM_RC_CallProcessBreakpoint_RANParameter_Item,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		""
		},
};
static const ber_tlv_tag_t asn_DEF_E2SM_RC_ran_CallProcessBreakpointParameters_List_tags_4[] = {
	(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_SET_OF_specifics_t asn_SPC_E2SM_RC_ran_CallProcessBreakpointParameters_List_specs_4 = {
	sizeof(struct E2SM_RC_RANFunctionDefinition_EventTrigger_Breakpoint_Item__ran_CallProcessBreakpointParameters_List),
	offsetof(struct E2SM_RC_RANFunctionDefinition_EventTrigger_Breakpoint_Item__ran_CallProcessBreakpointParameters_List, _asn_ctx),
	0,	/* XER encoding is XMLDelimitedItemList */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_E2SM_RC_ran_CallProcessBreakpointParameters_List_4 = {
	"ran-CallProcessBreakpointParameters-List",
	"ran-CallProcessBreakpointParameters-List",
	&asn_OP_SEQUENCE_OF,
	asn_DEF_E2SM_RC_ran_CallProcessBreakpointParameters_List_tags_4,
	sizeof(asn_DEF_E2SM_RC_ran_CallProcessBreakpointParameters_List_tags_4)
		/sizeof(asn_DEF_E2SM_RC_ran_CallProcessBreakpointParameters_List_tags_4[0]) - 1, /* 1 */
	asn_DEF_E2SM_RC_ran_CallProcessBreakpointParameters_List_tags_4,	/* Same as above */
	sizeof(asn_DEF_E2SM_RC_ran_CallProcessBreakpointParameters_List_tags_4)
		/sizeof(asn_DEF_E2SM_RC_ran_CallProcessBreakpointParameters_List_tags_4[0]), /* 2 */
	{ 0, &asn_PER_type_E2SM_RC_ran_CallProcessBreakpointParameters_List_constr_4, SEQUENCE_OF_constraint },
	asn_MBR_E2SM_RC_ran_CallProcessBreakpointParameters_List_4,
	1,	/* Single element */
	&asn_SPC_E2SM_RC_ran_CallProcessBreakpointParameters_List_specs_4	/* Additional specs */
};

asn_TYPE_member_t asn_MBR_E2SM_RC_RANFunctionDefinition_EventTrigger_Breakpoint_Item_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct E2SM_RC_RANFunctionDefinition_EventTrigger_Breakpoint_Item, callProcessBreakpoint_ID),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_E2SM_RC_RIC_CallProcessBreakpoint_ID,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"callProcessBreakpoint-ID"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct E2SM_RC_RANFunctionDefinition_EventTrigger_Breakpoint_Item, callProcessBreakpoint_Name),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_E2SM_RC_RIC_CallProcessBreakpoint_Name,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"callProcessBreakpoint-Name"
		},
	{ ATF_POINTER, 1, offsetof(struct E2SM_RC_RANFunctionDefinition_EventTrigger_Breakpoint_Item, ran_CallProcessBreakpointParameters_List),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		0,
		&asn_DEF_E2SM_RC_ran_CallProcessBreakpointParameters_List_4,
		0,
		{ 0, &asn_PER_memb_E2SM_RC_ran_CallProcessBreakpointParameters_List_constr_4,  memb_E2SM_RC_ran_CallProcessBreakpointParameters_List_constraint_1 },
		0, 0, /* No default value */
		"ran-CallProcessBreakpointParameters-List"
		},
};
static const int asn_MAP_E2SM_RC_RANFunctionDefinition_EventTrigger_Breakpoint_Item_oms_1[] = { 2 };
static const ber_tlv_tag_t asn_DEF_E2SM_RC_RANFunctionDefinition_EventTrigger_Breakpoint_Item_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_E2SM_RC_RANFunctionDefinition_EventTrigger_Breakpoint_Item_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* callProcessBreakpoint-ID */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* callProcessBreakpoint-Name */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 } /* ran-CallProcessBreakpointParameters-List */
};
asn_SEQUENCE_specifics_t asn_SPC_E2SM_RC_RANFunctionDefinition_EventTrigger_Breakpoint_Item_specs_1 = {
	sizeof(struct E2SM_RC_RANFunctionDefinition_EventTrigger_Breakpoint_Item),
	offsetof(struct E2SM_RC_RANFunctionDefinition_EventTrigger_Breakpoint_Item, _asn_ctx),
	asn_MAP_E2SM_RC_RANFunctionDefinition_EventTrigger_Breakpoint_Item_tag2el_1,
	3,	/* Count of tags in the map */
	asn_MAP_E2SM_RC_RANFunctionDefinition_EventTrigger_Breakpoint_Item_oms_1,	/* Optional members */
	1, 0,	/* Root/Additions */
	3,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_E2SM_RC_RANFunctionDefinition_EventTrigger_Breakpoint_Item = {
	"RANFunctionDefinition-EventTrigger-Breakpoint-Item",
	"RANFunctionDefinition-EventTrigger-Breakpoint-Item",
	&asn_OP_SEQUENCE,
	asn_DEF_E2SM_RC_RANFunctionDefinition_EventTrigger_Breakpoint_Item_tags_1,
	sizeof(asn_DEF_E2SM_RC_RANFunctionDefinition_EventTrigger_Breakpoint_Item_tags_1)
		/sizeof(asn_DEF_E2SM_RC_RANFunctionDefinition_EventTrigger_Breakpoint_Item_tags_1[0]), /* 1 */
	asn_DEF_E2SM_RC_RANFunctionDefinition_EventTrigger_Breakpoint_Item_tags_1,	/* Same as above */
	sizeof(asn_DEF_E2SM_RC_RANFunctionDefinition_EventTrigger_Breakpoint_Item_tags_1)
		/sizeof(asn_DEF_E2SM_RC_RANFunctionDefinition_EventTrigger_Breakpoint_Item_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_E2SM_RC_RANFunctionDefinition_EventTrigger_Breakpoint_Item_1,
	3,	/* Elements count */
	&asn_SPC_E2SM_RC_RANFunctionDefinition_EventTrigger_Breakpoint_Item_specs_1	/* Additional specs */
};

