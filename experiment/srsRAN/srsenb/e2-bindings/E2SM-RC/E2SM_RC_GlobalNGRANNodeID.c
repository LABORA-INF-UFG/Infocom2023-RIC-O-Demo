/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-COMMON-IEs"
 * 	found in "../E2SM/e2sm-v02.01.asn1"
 * 	`asn1c -pdu=all -fcompound-names -gen-PER -no-gen-OER -no-gen-example -fno-include-deps -fincludes-quoted -D E2SM-RC/`
 */

#include "E2SM_RC_GlobalNGRANNodeID.h"

asn_per_constraints_t asn_PER_type_E2SM_RC_GlobalNGRANNodeID_constr_1 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  1,  1,  0,  1 }	/* (0..1,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
asn_TYPE_member_t asn_MBR_E2SM_RC_GlobalNGRANNodeID_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct E2SM_RC_GlobalNGRANNodeID, choice.gNB),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_E2SM_RC_GlobalGNB_ID,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"gNB"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct E2SM_RC_GlobalNGRANNodeID, choice.ng_eNB),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_E2SM_RC_GlobalNgENB_ID,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"ng-eNB"
		},
};
static const asn_TYPE_tag2member_t asn_MAP_E2SM_RC_GlobalNGRANNodeID_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* gNB */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* ng-eNB */
};
asn_CHOICE_specifics_t asn_SPC_E2SM_RC_GlobalNGRANNodeID_specs_1 = {
	sizeof(struct E2SM_RC_GlobalNGRANNodeID),
	offsetof(struct E2SM_RC_GlobalNGRANNodeID, _asn_ctx),
	offsetof(struct E2SM_RC_GlobalNGRANNodeID, present),
	sizeof(((struct E2SM_RC_GlobalNGRANNodeID *)0)->present),
	asn_MAP_E2SM_RC_GlobalNGRANNodeID_tag2el_1,
	2,	/* Count of tags in the map */
	0, 0,
	2	/* Extensions start */
};
asn_TYPE_descriptor_t asn_DEF_E2SM_RC_GlobalNGRANNodeID = {
	"GlobalNGRANNodeID",
	"GlobalNGRANNodeID",
	&asn_OP_CHOICE,
	0,	/* No effective tags (pointer) */
	0,	/* No effective tags (count) */
	0,	/* No tags (pointer) */
	0,	/* No tags (count) */
	{ 0, &asn_PER_type_E2SM_RC_GlobalNGRANNodeID_constr_1, CHOICE_constraint },
	asn_MBR_E2SM_RC_GlobalNGRANNodeID_1,
	2,	/* Elements count */
	&asn_SPC_E2SM_RC_GlobalNGRANNodeID_specs_1	/* Additional specs */
};

