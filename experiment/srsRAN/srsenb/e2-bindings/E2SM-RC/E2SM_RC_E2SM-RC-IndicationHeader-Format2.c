/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-RC-IEs"
 * 	found in "e2sm-rc-v01.03.asn1"
 * 	`asn1c -pdu=all -fcompound-names -gen-PER -no-gen-OER -no-gen-example -fno-include-deps -fincludes-quoted -D E2SM-RC/`
 */

#include "E2SM_RC_E2SM-RC-IndicationHeader-Format2.h"

asn_TYPE_member_t asn_MBR_E2SM_RC_E2SM_RC_IndicationHeader_Format2_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct E2SM_RC_E2SM_RC_IndicationHeader_Format2, ueID),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_E2SM_RC_UEID,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"ueID"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct E2SM_RC_E2SM_RC_IndicationHeader_Format2, ric_InsertStyle_Type),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_E2SM_RC_RIC_Style_Type,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"ric-InsertStyle-Type"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct E2SM_RC_E2SM_RC_IndicationHeader_Format2, ric_InsertIndication_ID),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_E2SM_RC_RIC_InsertIndication_ID,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"ric-InsertIndication-ID"
		},
};
static const ber_tlv_tag_t asn_DEF_E2SM_RC_E2SM_RC_IndicationHeader_Format2_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_E2SM_RC_E2SM_RC_IndicationHeader_Format2_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* ueID */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* ric-InsertStyle-Type */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 } /* ric-InsertIndication-ID */
};
asn_SEQUENCE_specifics_t asn_SPC_E2SM_RC_E2SM_RC_IndicationHeader_Format2_specs_1 = {
	sizeof(struct E2SM_RC_E2SM_RC_IndicationHeader_Format2),
	offsetof(struct E2SM_RC_E2SM_RC_IndicationHeader_Format2, _asn_ctx),
	asn_MAP_E2SM_RC_E2SM_RC_IndicationHeader_Format2_tag2el_1,
	3,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	3,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_E2SM_RC_E2SM_RC_IndicationHeader_Format2 = {
	"E2SM-RC-IndicationHeader-Format2",
	"E2SM-RC-IndicationHeader-Format2",
	&asn_OP_SEQUENCE,
	asn_DEF_E2SM_RC_E2SM_RC_IndicationHeader_Format2_tags_1,
	sizeof(asn_DEF_E2SM_RC_E2SM_RC_IndicationHeader_Format2_tags_1)
		/sizeof(asn_DEF_E2SM_RC_E2SM_RC_IndicationHeader_Format2_tags_1[0]), /* 1 */
	asn_DEF_E2SM_RC_E2SM_RC_IndicationHeader_Format2_tags_1,	/* Same as above */
	sizeof(asn_DEF_E2SM_RC_E2SM_RC_IndicationHeader_Format2_tags_1)
		/sizeof(asn_DEF_E2SM_RC_E2SM_RC_IndicationHeader_Format2_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_E2SM_RC_E2SM_RC_IndicationHeader_Format2_1,
	3,	/* Elements count */
	&asn_SPC_E2SM_RC_E2SM_RC_IndicationHeader_Format2_specs_1	/* Additional specs */
};

