/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-NEXRAN-IEs"
 * 	found in "/home/cciadmin/Infocom2023-RIC-O-Demo/srsenb/src/ric/messages/asn1/e2sm-nexran-v01.00.asn1"
 * 	`asn1c -pdu=all -fcompound-names -gen-PER -no-gen-OER -no-gen-example -fno-include-deps -fincludes-quoted -D /home/cciadmin/Infocom2023-RIC-O-Demo/build/srsenb/src/ric/messages/E2SM-NEXRAN/`
 */

#include "E2SM_NEXRAN_E2SM-NexRAN-ControlMessage-Format1.h"

asn_per_constraints_t asn_PER_type_E2SM_NEXRAN_E2SM_NexRAN_ControlMessage_Format1_constr_1 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  3,  3,  0,  4 }	/* (0..4,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
asn_TYPE_member_t asn_MBR_E2SM_NEXRAN_E2SM_NexRAN_ControlMessage_Format1_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct E2SM_NEXRAN_E2SM_NexRAN_ControlMessage_Format1, choice.sliceConfigRequest),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_E2SM_NEXRAN_SliceConfigRequest,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"sliceConfigRequest"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct E2SM_NEXRAN_E2SM_NexRAN_ControlMessage_Format1, choice.sliceDeleteRequest),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_E2SM_NEXRAN_SliceDeleteRequest,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"sliceDeleteRequest"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct E2SM_NEXRAN_E2SM_NexRAN_ControlMessage_Format1, choice.sliceStatusRequest),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_E2SM_NEXRAN_SliceStatusRequest,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"sliceStatusRequest"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct E2SM_NEXRAN_E2SM_NexRAN_ControlMessage_Format1, choice.sliceUeBindRequest),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_E2SM_NEXRAN_SliceUeBindRequest,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"sliceUeBindRequest"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct E2SM_NEXRAN_E2SM_NexRAN_ControlMessage_Format1, choice.sliceUeUnbindRequest),
		(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_E2SM_NEXRAN_SliceUeUnbindRequest,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"sliceUeUnbindRequest"
		},
};
static const asn_TYPE_tag2member_t asn_MAP_E2SM_NEXRAN_E2SM_NexRAN_ControlMessage_Format1_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* sliceConfigRequest */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* sliceDeleteRequest */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* sliceStatusRequest */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 }, /* sliceUeBindRequest */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0, 0 } /* sliceUeUnbindRequest */
};
asn_CHOICE_specifics_t asn_SPC_E2SM_NEXRAN_E2SM_NexRAN_ControlMessage_Format1_specs_1 = {
	sizeof(struct E2SM_NEXRAN_E2SM_NexRAN_ControlMessage_Format1),
	offsetof(struct E2SM_NEXRAN_E2SM_NexRAN_ControlMessage_Format1, _asn_ctx),
	offsetof(struct E2SM_NEXRAN_E2SM_NexRAN_ControlMessage_Format1, present),
	sizeof(((struct E2SM_NEXRAN_E2SM_NexRAN_ControlMessage_Format1 *)0)->present),
	asn_MAP_E2SM_NEXRAN_E2SM_NexRAN_ControlMessage_Format1_tag2el_1,
	5,	/* Count of tags in the map */
	0, 0,
	5	/* Extensions start */
};
asn_TYPE_descriptor_t asn_DEF_E2SM_NEXRAN_E2SM_NexRAN_ControlMessage_Format1 = {
	"E2SM-NexRAN-ControlMessage-Format1",
	"E2SM-NexRAN-ControlMessage-Format1",
	&asn_OP_CHOICE,
	0,	/* No effective tags (pointer) */
	0,	/* No effective tags (count) */
	0,	/* No tags (pointer) */
	0,	/* No tags (count) */
	{ 0, &asn_PER_type_E2SM_NEXRAN_E2SM_NexRAN_ControlMessage_Format1_constr_1, CHOICE_constraint },
	asn_MBR_E2SM_NEXRAN_E2SM_NexRAN_ControlMessage_Format1_1,
	5,	/* Elements count */
	&asn_SPC_E2SM_NEXRAN_E2SM_NexRAN_ControlMessage_Format1_specs_1	/* Additional specs */
};

