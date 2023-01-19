/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-RC-IEs"
 * 	found in "e2sm-rc-v01.03.asn1"
 * 	`asn1c -pdu=all -fcompound-names -gen-PER -no-gen-OER -no-gen-example -fno-include-deps -fincludes-quoted -D E2SM-RC/`
 */

#include "E2SM_RC_RANParameter-Definition-Choice.h"

#include "E2SM_RC_RANParameter-Definition-Choice-LIST.h"
#include "E2SM_RC_RANParameter-Definition-Choice-STRUCTURE.h"
asn_per_constraints_t asn_PER_type_E2SM_RC_RANParameter_Definition_Choice_constr_1 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  1,  1,  0,  1 }	/* (0..1,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
asn_TYPE_member_t asn_MBR_E2SM_RC_RANParameter_Definition_Choice_1[] = {
	{ ATF_POINTER, 0, offsetof(struct E2SM_RC_RANParameter_Definition_Choice, choice.choiceLIST),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_E2SM_RC_RANParameter_Definition_Choice_LIST,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"choiceLIST"
		},
	{ ATF_POINTER, 0, offsetof(struct E2SM_RC_RANParameter_Definition_Choice, choice.choiceSTRUCTURE),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_E2SM_RC_RANParameter_Definition_Choice_STRUCTURE,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"choiceSTRUCTURE"
		},
};
static const asn_TYPE_tag2member_t asn_MAP_E2SM_RC_RANParameter_Definition_Choice_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* choiceLIST */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* choiceSTRUCTURE */
};
asn_CHOICE_specifics_t asn_SPC_E2SM_RC_RANParameter_Definition_Choice_specs_1 = {
	sizeof(struct E2SM_RC_RANParameter_Definition_Choice),
	offsetof(struct E2SM_RC_RANParameter_Definition_Choice, _asn_ctx),
	offsetof(struct E2SM_RC_RANParameter_Definition_Choice, present),
	sizeof(((struct E2SM_RC_RANParameter_Definition_Choice *)0)->present),
	asn_MAP_E2SM_RC_RANParameter_Definition_Choice_tag2el_1,
	2,	/* Count of tags in the map */
	0, 0,
	2	/* Extensions start */
};
asn_TYPE_descriptor_t asn_DEF_E2SM_RC_RANParameter_Definition_Choice = {
	"RANParameter-Definition-Choice",
	"RANParameter-Definition-Choice",
	&asn_OP_CHOICE,
	0,	/* No effective tags (pointer) */
	0,	/* No effective tags (count) */
	0,	/* No tags (pointer) */
	0,	/* No tags (count) */
	{ 0, &asn_PER_type_E2SM_RC_RANParameter_Definition_Choice_constr_1, CHOICE_constraint },
	asn_MBR_E2SM_RC_RANParameter_Definition_Choice_1,
	2,	/* Elements count */
	&asn_SPC_E2SM_RC_RANParameter_Definition_Choice_specs_1	/* Additional specs */
};

