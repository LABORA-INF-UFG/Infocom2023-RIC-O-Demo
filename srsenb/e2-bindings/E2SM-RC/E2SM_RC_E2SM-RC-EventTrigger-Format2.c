/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-RC-IEs"
 * 	found in "e2sm-rc-v01.03.asn1"
 * 	`asn1c -pdu=all -fcompound-names -gen-PER -no-gen-OER -no-gen-example -fno-include-deps -fincludes-quoted -D E2SM-RC/`
 */

#include "E2SM_RC_E2SM-RC-EventTrigger-Format2.h"

#include "E2SM_RC_RANParameter-Testing.h"
#include "E2SM_RC_EventTrigger-UE-Info.h"
asn_TYPE_member_t asn_MBR_E2SM_RC_E2SM_RC_EventTrigger_Format2_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct E2SM_RC_E2SM_RC_EventTrigger_Format2, ric_callProcessType_ID),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_E2SM_RC_RIC_CallProcessType_ID,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"ric-callProcessType-ID"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct E2SM_RC_E2SM_RC_EventTrigger_Format2, ric_callProcessBreakpoint_ID),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_E2SM_RC_RIC_CallProcessBreakpoint_ID,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"ric-callProcessBreakpoint-ID"
		},
	{ ATF_POINTER, 2, offsetof(struct E2SM_RC_E2SM_RC_EventTrigger_Format2, associatedE2NodeInfo),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_E2SM_RC_RANParameter_Testing,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"associatedE2NodeInfo"
		},
	{ ATF_POINTER, 1, offsetof(struct E2SM_RC_E2SM_RC_EventTrigger_Format2, associatedUEInfo),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_E2SM_RC_EventTrigger_UE_Info,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"associatedUEInfo"
		},
};
static const int asn_MAP_E2SM_RC_E2SM_RC_EventTrigger_Format2_oms_1[] = { 2, 3 };
static const ber_tlv_tag_t asn_DEF_E2SM_RC_E2SM_RC_EventTrigger_Format2_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_E2SM_RC_E2SM_RC_EventTrigger_Format2_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* ric-callProcessType-ID */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* ric-callProcessBreakpoint-ID */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* associatedE2NodeInfo */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 } /* associatedUEInfo */
};
asn_SEQUENCE_specifics_t asn_SPC_E2SM_RC_E2SM_RC_EventTrigger_Format2_specs_1 = {
	sizeof(struct E2SM_RC_E2SM_RC_EventTrigger_Format2),
	offsetof(struct E2SM_RC_E2SM_RC_EventTrigger_Format2, _asn_ctx),
	asn_MAP_E2SM_RC_E2SM_RC_EventTrigger_Format2_tag2el_1,
	4,	/* Count of tags in the map */
	asn_MAP_E2SM_RC_E2SM_RC_EventTrigger_Format2_oms_1,	/* Optional members */
	2, 0,	/* Root/Additions */
	4,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_E2SM_RC_E2SM_RC_EventTrigger_Format2 = {
	"E2SM-RC-EventTrigger-Format2",
	"E2SM-RC-EventTrigger-Format2",
	&asn_OP_SEQUENCE,
	asn_DEF_E2SM_RC_E2SM_RC_EventTrigger_Format2_tags_1,
	sizeof(asn_DEF_E2SM_RC_E2SM_RC_EventTrigger_Format2_tags_1)
		/sizeof(asn_DEF_E2SM_RC_E2SM_RC_EventTrigger_Format2_tags_1[0]), /* 1 */
	asn_DEF_E2SM_RC_E2SM_RC_EventTrigger_Format2_tags_1,	/* Same as above */
	sizeof(asn_DEF_E2SM_RC_E2SM_RC_EventTrigger_Format2_tags_1)
		/sizeof(asn_DEF_E2SM_RC_E2SM_RC_EventTrigger_Format2_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_E2SM_RC_E2SM_RC_EventTrigger_Format2_1,
	4,	/* Elements count */
	&asn_SPC_E2SM_RC_E2SM_RC_EventTrigger_Format2_specs_1	/* Additional specs */
};

