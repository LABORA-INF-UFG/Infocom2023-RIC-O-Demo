/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-RC-IEs"
 * 	found in "e2sm-rc-v01.03.asn1"
 * 	`asn1c -pdu=all -fcompound-names -gen-PER -no-gen-OER -no-gen-example -fno-include-deps -fincludes-quoted -D E2SM-RC/`
 */

#include "E2SM_RC_E2SM-RC-IndicationMessage-Format4-ItemUE.h"

asn_TYPE_member_t asn_MBR_E2SM_RC_E2SM_RC_IndicationMessage_Format4_ItemUE_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct E2SM_RC_E2SM_RC_IndicationMessage_Format4_ItemUE, ueID),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_E2SM_RC_UEID,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"ueID"
		},
	{ ATF_POINTER, 1, offsetof(struct E2SM_RC_E2SM_RC_IndicationMessage_Format4_ItemUE, ueContextInfo),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_OCTET_STRING,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"ueContextInfo"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct E2SM_RC_E2SM_RC_IndicationMessage_Format4_ItemUE, cellGlobal_ID),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_E2SM_RC_CGI,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"cellGlobal-ID"
		},
};
static const int asn_MAP_E2SM_RC_E2SM_RC_IndicationMessage_Format4_ItemUE_oms_1[] = { 1 };
static const ber_tlv_tag_t asn_DEF_E2SM_RC_E2SM_RC_IndicationMessage_Format4_ItemUE_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_E2SM_RC_E2SM_RC_IndicationMessage_Format4_ItemUE_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* ueID */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* ueContextInfo */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 } /* cellGlobal-ID */
};
asn_SEQUENCE_specifics_t asn_SPC_E2SM_RC_E2SM_RC_IndicationMessage_Format4_ItemUE_specs_1 = {
	sizeof(struct E2SM_RC_E2SM_RC_IndicationMessage_Format4_ItemUE),
	offsetof(struct E2SM_RC_E2SM_RC_IndicationMessage_Format4_ItemUE, _asn_ctx),
	asn_MAP_E2SM_RC_E2SM_RC_IndicationMessage_Format4_ItemUE_tag2el_1,
	3,	/* Count of tags in the map */
	asn_MAP_E2SM_RC_E2SM_RC_IndicationMessage_Format4_ItemUE_oms_1,	/* Optional members */
	1, 0,	/* Root/Additions */
	3,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_E2SM_RC_E2SM_RC_IndicationMessage_Format4_ItemUE = {
	"E2SM-RC-IndicationMessage-Format4-ItemUE",
	"E2SM-RC-IndicationMessage-Format4-ItemUE",
	&asn_OP_SEQUENCE,
	asn_DEF_E2SM_RC_E2SM_RC_IndicationMessage_Format4_ItemUE_tags_1,
	sizeof(asn_DEF_E2SM_RC_E2SM_RC_IndicationMessage_Format4_ItemUE_tags_1)
		/sizeof(asn_DEF_E2SM_RC_E2SM_RC_IndicationMessage_Format4_ItemUE_tags_1[0]), /* 1 */
	asn_DEF_E2SM_RC_E2SM_RC_IndicationMessage_Format4_ItemUE_tags_1,	/* Same as above */
	sizeof(asn_DEF_E2SM_RC_E2SM_RC_IndicationMessage_Format4_ItemUE_tags_1)
		/sizeof(asn_DEF_E2SM_RC_E2SM_RC_IndicationMessage_Format4_ItemUE_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_E2SM_RC_E2SM_RC_IndicationMessage_Format4_ItemUE_1,
	3,	/* Elements count */
	&asn_SPC_E2SM_RC_E2SM_RC_IndicationMessage_Format4_ItemUE_specs_1	/* Additional specs */
};

