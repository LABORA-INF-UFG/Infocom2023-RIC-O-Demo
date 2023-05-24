/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-COMMON-IEs"
 * 	found in "../E2SM/e2sm-v02.01.asn1"
 * 	`asn1c -pdu=all -fcompound-names -gen-PER -no-gen-OER -no-gen-example -fno-include-deps -fincludes-quoted -D E2SM-RC/`
 */

#include "E2SM_RC_InterfaceID-W1.h"

asn_TYPE_member_t asn_MBR_E2SM_RC_InterfaceID_W1_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct E2SM_RC_InterfaceID_W1, global_ng_eNB_ID),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_E2SM_RC_GlobalNgENB_ID,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"global-ng-eNB-ID"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct E2SM_RC_InterfaceID_W1, ng_eNB_DU_ID),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_E2SM_RC_NGENB_DU_ID,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"ng-eNB-DU-ID"
		},
};
static const ber_tlv_tag_t asn_DEF_E2SM_RC_InterfaceID_W1_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_E2SM_RC_InterfaceID_W1_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* global-ng-eNB-ID */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* ng-eNB-DU-ID */
};
asn_SEQUENCE_specifics_t asn_SPC_E2SM_RC_InterfaceID_W1_specs_1 = {
	sizeof(struct E2SM_RC_InterfaceID_W1),
	offsetof(struct E2SM_RC_InterfaceID_W1, _asn_ctx),
	asn_MAP_E2SM_RC_InterfaceID_W1_tag2el_1,
	2,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	2,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_E2SM_RC_InterfaceID_W1 = {
	"InterfaceID-W1",
	"InterfaceID-W1",
	&asn_OP_SEQUENCE,
	asn_DEF_E2SM_RC_InterfaceID_W1_tags_1,
	sizeof(asn_DEF_E2SM_RC_InterfaceID_W1_tags_1)
		/sizeof(asn_DEF_E2SM_RC_InterfaceID_W1_tags_1[0]), /* 1 */
	asn_DEF_E2SM_RC_InterfaceID_W1_tags_1,	/* Same as above */
	sizeof(asn_DEF_E2SM_RC_InterfaceID_W1_tags_1)
		/sizeof(asn_DEF_E2SM_RC_InterfaceID_W1_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_E2SM_RC_InterfaceID_W1_1,
	2,	/* Elements count */
	&asn_SPC_E2SM_RC_InterfaceID_W1_specs_1	/* Additional specs */
};

