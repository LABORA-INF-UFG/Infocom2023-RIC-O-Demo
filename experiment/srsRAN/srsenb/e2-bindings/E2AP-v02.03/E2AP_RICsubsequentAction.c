/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2AP-IEs"
 * 	found in "../e2ap-v02.03.asn1"
 * 	`asn1c -pdu=all -fcompound-names -fincludes-quoted -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D EXACT/`
 */

#include "E2AP_RICsubsequentAction.h"

asn_TYPE_member_t asn_MBR_E2AP_RICsubsequentAction_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct E2AP_RICsubsequentAction, ricSubsequentActionType),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_E2AP_RICsubsequentActionType,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"ricSubsequentActionType"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct E2AP_RICsubsequentAction, ricTimeToWait),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_E2AP_RICtimeToWait,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"ricTimeToWait"
		},
};
static const ber_tlv_tag_t asn_DEF_E2AP_RICsubsequentAction_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_E2AP_RICsubsequentAction_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* ricSubsequentActionType */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* ricTimeToWait */
};
asn_SEQUENCE_specifics_t asn_SPC_E2AP_RICsubsequentAction_specs_1 = {
	sizeof(struct E2AP_RICsubsequentAction),
	offsetof(struct E2AP_RICsubsequentAction, _asn_ctx),
	asn_MAP_E2AP_RICsubsequentAction_tag2el_1,
	2,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	2,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_E2AP_RICsubsequentAction = {
	"RICsubsequentAction",
	"RICsubsequentAction",
	&asn_OP_SEQUENCE,
	asn_DEF_E2AP_RICsubsequentAction_tags_1,
	sizeof(asn_DEF_E2AP_RICsubsequentAction_tags_1)
		/sizeof(asn_DEF_E2AP_RICsubsequentAction_tags_1[0]), /* 1 */
	asn_DEF_E2AP_RICsubsequentAction_tags_1,	/* Same as above */
	sizeof(asn_DEF_E2AP_RICsubsequentAction_tags_1)
		/sizeof(asn_DEF_E2AP_RICsubsequentAction_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_E2AP_RICsubsequentAction_1,
	2,	/* Elements count */
	&asn_SPC_E2AP_RICsubsequentAction_specs_1	/* Additional specs */
};

