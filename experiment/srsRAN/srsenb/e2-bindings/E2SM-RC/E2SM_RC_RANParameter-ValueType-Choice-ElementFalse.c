/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-RC-IEs"
 * 	found in "e2sm-rc-v01.03.asn1"
 * 	`asn1c -pdu=all -fcompound-names -gen-PER -no-gen-OER -no-gen-example -fno-include-deps -fincludes-quoted -D E2SM-RC/`
 */

#include "E2SM_RC_RANParameter-ValueType-Choice-ElementFalse.h"

#include "E2SM_RC_RANParameter-Value.h"
asn_TYPE_member_t asn_MBR_E2SM_RC_RANParameter_ValueType_Choice_ElementFalse_1[] = {
	{ ATF_POINTER, 1, offsetof(struct E2SM_RC_RANParameter_ValueType_Choice_ElementFalse, ranParameter_value),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_E2SM_RC_RANParameter_Value,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"ranParameter-value"
		},
};
static const int asn_MAP_E2SM_RC_RANParameter_ValueType_Choice_ElementFalse_oms_1[] = { 0 };
static const ber_tlv_tag_t asn_DEF_E2SM_RC_RANParameter_ValueType_Choice_ElementFalse_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_E2SM_RC_RANParameter_ValueType_Choice_ElementFalse_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 } /* ranParameter-value */
};
asn_SEQUENCE_specifics_t asn_SPC_E2SM_RC_RANParameter_ValueType_Choice_ElementFalse_specs_1 = {
	sizeof(struct E2SM_RC_RANParameter_ValueType_Choice_ElementFalse),
	offsetof(struct E2SM_RC_RANParameter_ValueType_Choice_ElementFalse, _asn_ctx),
	asn_MAP_E2SM_RC_RANParameter_ValueType_Choice_ElementFalse_tag2el_1,
	1,	/* Count of tags in the map */
	asn_MAP_E2SM_RC_RANParameter_ValueType_Choice_ElementFalse_oms_1,	/* Optional members */
	1, 0,	/* Root/Additions */
	1,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_E2SM_RC_RANParameter_ValueType_Choice_ElementFalse = {
	"RANParameter-ValueType-Choice-ElementFalse",
	"RANParameter-ValueType-Choice-ElementFalse",
	&asn_OP_SEQUENCE,
	asn_DEF_E2SM_RC_RANParameter_ValueType_Choice_ElementFalse_tags_1,
	sizeof(asn_DEF_E2SM_RC_RANParameter_ValueType_Choice_ElementFalse_tags_1)
		/sizeof(asn_DEF_E2SM_RC_RANParameter_ValueType_Choice_ElementFalse_tags_1[0]), /* 1 */
	asn_DEF_E2SM_RC_RANParameter_ValueType_Choice_ElementFalse_tags_1,	/* Same as above */
	sizeof(asn_DEF_E2SM_RC_RANParameter_ValueType_Choice_ElementFalse_tags_1)
		/sizeof(asn_DEF_E2SM_RC_RANParameter_ValueType_Choice_ElementFalse_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_E2SM_RC_RANParameter_ValueType_Choice_ElementFalse_1,
	1,	/* Elements count */
	&asn_SPC_E2SM_RC_RANParameter_ValueType_Choice_ElementFalse_specs_1	/* Additional specs */
};

