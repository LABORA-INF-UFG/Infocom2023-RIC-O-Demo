/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-COMMON-IEs"
 * 	found in "../E2SM/e2sm-v02.01.asn1"
 * 	`asn1c -pdu=all -fcompound-names -gen-PER -no-gen-OER -no-gen-example -fno-include-deps -fincludes-quoted -D E2SM-RC/`
 */

#include "E2SM_RC_RRC-MessageID.h"

static asn_per_constraints_t asn_PER_type_E2SM_RC_rrcType_constr_2 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  1,  1,  0,  1 }	/* (0..1,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_TYPE_member_t asn_MBR_E2SM_RC_rrcType_2[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct E2SM_RC_RRC_MessageID__rrcType, choice.lTE),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_E2SM_RC_RRCclass_LTE,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"lTE"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct E2SM_RC_RRC_MessageID__rrcType, choice.nR),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_E2SM_RC_RRCclass_NR,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"nR"
		},
};
static const asn_TYPE_tag2member_t asn_MAP_E2SM_RC_rrcType_tag2el_2[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* lTE */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* nR */
};
static asn_CHOICE_specifics_t asn_SPC_E2SM_RC_rrcType_specs_2 = {
	sizeof(struct E2SM_RC_RRC_MessageID__rrcType),
	offsetof(struct E2SM_RC_RRC_MessageID__rrcType, _asn_ctx),
	offsetof(struct E2SM_RC_RRC_MessageID__rrcType, present),
	sizeof(((struct E2SM_RC_RRC_MessageID__rrcType *)0)->present),
	asn_MAP_E2SM_RC_rrcType_tag2el_2,
	2,	/* Count of tags in the map */
	0, 0,
	2	/* Extensions start */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_E2SM_RC_rrcType_2 = {
	"rrcType",
	"rrcType",
	&asn_OP_CHOICE,
	0,	/* No effective tags (pointer) */
	0,	/* No effective tags (count) */
	0,	/* No tags (pointer) */
	0,	/* No tags (count) */
	{ 0, &asn_PER_type_E2SM_RC_rrcType_constr_2, CHOICE_constraint },
	asn_MBR_E2SM_RC_rrcType_2,
	2,	/* Elements count */
	&asn_SPC_E2SM_RC_rrcType_specs_2	/* Additional specs */
};

asn_TYPE_member_t asn_MBR_E2SM_RC_RRC_MessageID_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct E2SM_RC_RRC_MessageID, rrcType),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_E2SM_RC_rrcType_2,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"rrcType"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct E2SM_RC_RRC_MessageID, messageID),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"messageID"
		},
};
static const ber_tlv_tag_t asn_DEF_E2SM_RC_RRC_MessageID_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_E2SM_RC_RRC_MessageID_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* rrcType */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* messageID */
};
asn_SEQUENCE_specifics_t asn_SPC_E2SM_RC_RRC_MessageID_specs_1 = {
	sizeof(struct E2SM_RC_RRC_MessageID),
	offsetof(struct E2SM_RC_RRC_MessageID, _asn_ctx),
	asn_MAP_E2SM_RC_RRC_MessageID_tag2el_1,
	2,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	2,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_E2SM_RC_RRC_MessageID = {
	"RRC-MessageID",
	"RRC-MessageID",
	&asn_OP_SEQUENCE,
	asn_DEF_E2SM_RC_RRC_MessageID_tags_1,
	sizeof(asn_DEF_E2SM_RC_RRC_MessageID_tags_1)
		/sizeof(asn_DEF_E2SM_RC_RRC_MessageID_tags_1[0]), /* 1 */
	asn_DEF_E2SM_RC_RRC_MessageID_tags_1,	/* Same as above */
	sizeof(asn_DEF_E2SM_RC_RRC_MessageID_tags_1)
		/sizeof(asn_DEF_E2SM_RC_RRC_MessageID_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_E2SM_RC_RRC_MessageID_1,
	2,	/* Elements count */
	&asn_SPC_E2SM_RC_RRC_MessageID_specs_1	/* Additional specs */
};

