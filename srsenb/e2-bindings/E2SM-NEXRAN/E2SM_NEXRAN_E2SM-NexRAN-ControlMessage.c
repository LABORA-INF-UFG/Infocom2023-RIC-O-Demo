/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-NEXRAN-IEs"
 * 	found in "/home/vikas/srslte-ric/srsenb/src/ric/messages/asn1/e2sm-nexran-v01.00.asn1"
 * 	`asn1c -pdu=all -fcompound-names -gen-PER -no-gen-OER -no-gen-example -fno-include-deps -fincludes-quoted -D /home/vikas/srslte-ric/build/srsenb/src/ric/messages/E2SM-NEXRAN/`
 */

#include "E2SM_NEXRAN_E2SM-NexRAN-ControlMessage.h"

static asn_per_constraints_t asn_PER_type_E2SM_NEXRAN_E2SM_NexRAN_ControlMessage_constr_1 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  0,  0,  0,  0 }	/* (0..0,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_TYPE_member_t asn_MBR_E2SM_NEXRAN_E2SM_NexRAN_ControlMessage_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct E2SM_NEXRAN_E2SM_NexRAN_ControlMessage, choice.controlMessageFormat1),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_E2SM_NEXRAN_E2SM_NexRAN_ControlMessage_Format1,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"controlMessageFormat1"
		},
};
static const asn_TYPE_tag2member_t asn_MAP_E2SM_NEXRAN_E2SM_NexRAN_ControlMessage_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 } /* controlMessageFormat1 */
};
static asn_CHOICE_specifics_t asn_SPC_E2SM_NEXRAN_E2SM_NexRAN_ControlMessage_specs_1 = {
	sizeof(struct E2SM_NEXRAN_E2SM_NexRAN_ControlMessage),
	offsetof(struct E2SM_NEXRAN_E2SM_NexRAN_ControlMessage, _asn_ctx),
	offsetof(struct E2SM_NEXRAN_E2SM_NexRAN_ControlMessage, present),
	sizeof(((struct E2SM_NEXRAN_E2SM_NexRAN_ControlMessage *)0)->present),
	asn_MAP_E2SM_NEXRAN_E2SM_NexRAN_ControlMessage_tag2el_1,
	1,	/* Count of tags in the map */
	0, 0,
	1	/* Extensions start */
};
asn_TYPE_descriptor_t asn_DEF_E2SM_NEXRAN_E2SM_NexRAN_ControlMessage = {
	"E2SM-NexRAN-ControlMessage",
	"E2SM-NexRAN-ControlMessage",
	&asn_OP_CHOICE,
	0,	/* No effective tags (pointer) */
	0,	/* No effective tags (count) */
	0,	/* No tags (pointer) */
	0,	/* No tags (count) */
	{ 0, &asn_PER_type_E2SM_NEXRAN_E2SM_NexRAN_ControlMessage_constr_1, CHOICE_constraint },
	asn_MBR_E2SM_NEXRAN_E2SM_NexRAN_ControlMessage_1,
	1,	/* Elements count */
	&asn_SPC_E2SM_NEXRAN_E2SM_NexRAN_ControlMessage_specs_1	/* Additional specs */
};

