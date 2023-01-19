/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-RC-IEs"
 * 	found in "e2sm-rc-v01.03.asn1"
 * 	`asn1c -pdu=all -fcompound-names -gen-PER -no-gen-OER -no-gen-example -fno-include-deps -fincludes-quoted -D E2SM-RC/`
 */

#include "E2SM_RC_E2SM-RC-EventTrigger.h"

static asn_per_constraints_t asn_PER_type_E2SM_RC_ric_eventTrigger_formats_constr_2 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  3,  3,  0,  4 }	/* (0..4,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_TYPE_member_t asn_MBR_E2SM_RC_ric_eventTrigger_formats_2[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct E2SM_RC_E2SM_RC_EventTrigger__ric_eventTrigger_formats, choice.eventTrigger_Format1),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_E2SM_RC_E2SM_RC_EventTrigger_Format1,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"eventTrigger-Format1"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct E2SM_RC_E2SM_RC_EventTrigger__ric_eventTrigger_formats, choice.eventTrigger_Format2),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_E2SM_RC_E2SM_RC_EventTrigger_Format2,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"eventTrigger-Format2"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct E2SM_RC_E2SM_RC_EventTrigger__ric_eventTrigger_formats, choice.eventTrigger_Format3),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_E2SM_RC_E2SM_RC_EventTrigger_Format3,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"eventTrigger-Format3"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct E2SM_RC_E2SM_RC_EventTrigger__ric_eventTrigger_formats, choice.eventTrigger_Format4),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_E2SM_RC_E2SM_RC_EventTrigger_Format4,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"eventTrigger-Format4"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct E2SM_RC_E2SM_RC_EventTrigger__ric_eventTrigger_formats, choice.eventTrigger_Format5),
		(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_E2SM_RC_E2SM_RC_EventTrigger_Format5,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"eventTrigger-Format5"
		},
};
static const asn_TYPE_tag2member_t asn_MAP_E2SM_RC_ric_eventTrigger_formats_tag2el_2[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* eventTrigger-Format1 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* eventTrigger-Format2 */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* eventTrigger-Format3 */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 }, /* eventTrigger-Format4 */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0, 0 } /* eventTrigger-Format5 */
};
static asn_CHOICE_specifics_t asn_SPC_E2SM_RC_ric_eventTrigger_formats_specs_2 = {
	sizeof(struct E2SM_RC_E2SM_RC_EventTrigger__ric_eventTrigger_formats),
	offsetof(struct E2SM_RC_E2SM_RC_EventTrigger__ric_eventTrigger_formats, _asn_ctx),
	offsetof(struct E2SM_RC_E2SM_RC_EventTrigger__ric_eventTrigger_formats, present),
	sizeof(((struct E2SM_RC_E2SM_RC_EventTrigger__ric_eventTrigger_formats *)0)->present),
	asn_MAP_E2SM_RC_ric_eventTrigger_formats_tag2el_2,
	5,	/* Count of tags in the map */
	0, 0,
	5	/* Extensions start */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_E2SM_RC_ric_eventTrigger_formats_2 = {
	"ric-eventTrigger-formats",
	"ric-eventTrigger-formats",
	&asn_OP_CHOICE,
	0,	/* No effective tags (pointer) */
	0,	/* No effective tags (count) */
	0,	/* No tags (pointer) */
	0,	/* No tags (count) */
	{ 0, &asn_PER_type_E2SM_RC_ric_eventTrigger_formats_constr_2, CHOICE_constraint },
	asn_MBR_E2SM_RC_ric_eventTrigger_formats_2,
	5,	/* Elements count */
	&asn_SPC_E2SM_RC_ric_eventTrigger_formats_specs_2	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_E2SM_RC_E2SM_RC_EventTrigger_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct E2SM_RC_E2SM_RC_EventTrigger, ric_eventTrigger_formats),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_E2SM_RC_ric_eventTrigger_formats_2,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"ric-eventTrigger-formats"
		},
};
static const ber_tlv_tag_t asn_DEF_E2SM_RC_E2SM_RC_EventTrigger_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_E2SM_RC_E2SM_RC_EventTrigger_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 } /* ric-eventTrigger-formats */
};
static asn_SEQUENCE_specifics_t asn_SPC_E2SM_RC_E2SM_RC_EventTrigger_specs_1 = {
	sizeof(struct E2SM_RC_E2SM_RC_EventTrigger),
	offsetof(struct E2SM_RC_E2SM_RC_EventTrigger, _asn_ctx),
	asn_MAP_E2SM_RC_E2SM_RC_EventTrigger_tag2el_1,
	1,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	1,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_E2SM_RC_E2SM_RC_EventTrigger = {
	"E2SM-RC-EventTrigger",
	"E2SM-RC-EventTrigger",
	&asn_OP_SEQUENCE,
	asn_DEF_E2SM_RC_E2SM_RC_EventTrigger_tags_1,
	sizeof(asn_DEF_E2SM_RC_E2SM_RC_EventTrigger_tags_1)
		/sizeof(asn_DEF_E2SM_RC_E2SM_RC_EventTrigger_tags_1[0]), /* 1 */
	asn_DEF_E2SM_RC_E2SM_RC_EventTrigger_tags_1,	/* Same as above */
	sizeof(asn_DEF_E2SM_RC_E2SM_RC_EventTrigger_tags_1)
		/sizeof(asn_DEF_E2SM_RC_E2SM_RC_EventTrigger_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_E2SM_RC_E2SM_RC_EventTrigger_1,
	1,	/* Elements count */
	&asn_SPC_E2SM_RC_E2SM_RC_EventTrigger_specs_1	/* Additional specs */
};

