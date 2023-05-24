/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-NEXRAN-IEs"
 * 	found in "/home/cciadmin/Infocom2023-RIC-O-Demo/srsenb/src/ric/messages/asn1/e2sm-nexran-v01.00.asn1"
 * 	`asn1c -pdu=all -fcompound-names -gen-PER -no-gen-OER -no-gen-example -fno-include-deps -fincludes-quoted -D /home/cciadmin/Infocom2023-RIC-O-Demo/build/srsenb/src/ric/messages/E2SM-NEXRAN/`
 */

#include "E2SM_NEXRAN_E2SM-NexRAN-ControlHeader-Format1.h"

asn_TYPE_member_t asn_MBR_E2SM_NEXRAN_E2SM_NexRAN_ControlHeader_Format1_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct E2SM_NEXRAN_E2SM_NexRAN_ControlHeader_Format1, controlMessageId),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_E2SM_NEXRAN_E2SM_NexRAN_ControlMessage_Id,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"controlMessageId"
		},
};
static const ber_tlv_tag_t asn_DEF_E2SM_NEXRAN_E2SM_NexRAN_ControlHeader_Format1_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_E2SM_NEXRAN_E2SM_NexRAN_ControlHeader_Format1_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 } /* controlMessageId */
};
asn_SEQUENCE_specifics_t asn_SPC_E2SM_NEXRAN_E2SM_NexRAN_ControlHeader_Format1_specs_1 = {
	sizeof(struct E2SM_NEXRAN_E2SM_NexRAN_ControlHeader_Format1),
	offsetof(struct E2SM_NEXRAN_E2SM_NexRAN_ControlHeader_Format1, _asn_ctx),
	asn_MAP_E2SM_NEXRAN_E2SM_NexRAN_ControlHeader_Format1_tag2el_1,
	1,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	1,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_E2SM_NEXRAN_E2SM_NexRAN_ControlHeader_Format1 = {
	"E2SM-NexRAN-ControlHeader-Format1",
	"E2SM-NexRAN-ControlHeader-Format1",
	&asn_OP_SEQUENCE,
	asn_DEF_E2SM_NEXRAN_E2SM_NexRAN_ControlHeader_Format1_tags_1,
	sizeof(asn_DEF_E2SM_NEXRAN_E2SM_NexRAN_ControlHeader_Format1_tags_1)
		/sizeof(asn_DEF_E2SM_NEXRAN_E2SM_NexRAN_ControlHeader_Format1_tags_1[0]), /* 1 */
	asn_DEF_E2SM_NEXRAN_E2SM_NexRAN_ControlHeader_Format1_tags_1,	/* Same as above */
	sizeof(asn_DEF_E2SM_NEXRAN_E2SM_NexRAN_ControlHeader_Format1_tags_1)
		/sizeof(asn_DEF_E2SM_NEXRAN_E2SM_NexRAN_ControlHeader_Format1_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_E2SM_NEXRAN_E2SM_NexRAN_ControlHeader_Format1_1,
	1,	/* Elements count */
	&asn_SPC_E2SM_NEXRAN_E2SM_NexRAN_ControlHeader_Format1_specs_1	/* Additional specs */
};

