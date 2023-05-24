/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-COMMON-IEs"
 * 	found in "../E2SM/e2sm-v02.01.asn1"
 * 	`asn1c -pdu=all -fcompound-names -gen-PER -no-gen-OER -no-gen-example -fno-include-deps -fincludes-quoted -D E2SM-RC/`
 */

#include "E2SM_RC_UEID-NG-ENB.h"

#include "E2SM_RC_GlobalNgENB-ID.h"
#include "E2SM_RC_GlobalNGRANNodeID.h"
asn_TYPE_member_t asn_MBR_E2SM_RC_UEID_NG_ENB_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct E2SM_RC_UEID_NG_ENB, amf_UE_NGAP_ID),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_E2SM_RC_AMF_UE_NGAP_ID,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"amf-UE-NGAP-ID"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct E2SM_RC_UEID_NG_ENB, guami),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_E2SM_RC_GUAMI,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"guami"
		},
	{ ATF_POINTER, 3, offsetof(struct E2SM_RC_UEID_NG_ENB, ng_eNB_CU_UE_W1AP_ID),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_E2SM_RC_NGENB_CU_UE_W1AP_ID,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"ng-eNB-CU-UE-W1AP-ID"
		},
	{ ATF_POINTER, 2, offsetof(struct E2SM_RC_UEID_NG_ENB, globalNgENB_ID),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_E2SM_RC_GlobalNgENB_ID,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"globalNgENB-ID"
		},
	{ ATF_POINTER, 1, offsetof(struct E2SM_RC_UEID_NG_ENB, globalNG_RANNode_ID),
		(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_E2SM_RC_GlobalNGRANNodeID,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"globalNG-RANNode-ID"
		},
};
static const int asn_MAP_E2SM_RC_UEID_NG_ENB_oms_1[] = { 2, 3, 4 };
static const ber_tlv_tag_t asn_DEF_E2SM_RC_UEID_NG_ENB_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_E2SM_RC_UEID_NG_ENB_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* amf-UE-NGAP-ID */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* guami */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* ng-eNB-CU-UE-W1AP-ID */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 }, /* globalNgENB-ID */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0, 0 } /* globalNG-RANNode-ID */
};
asn_SEQUENCE_specifics_t asn_SPC_E2SM_RC_UEID_NG_ENB_specs_1 = {
	sizeof(struct E2SM_RC_UEID_NG_ENB),
	offsetof(struct E2SM_RC_UEID_NG_ENB, _asn_ctx),
	asn_MAP_E2SM_RC_UEID_NG_ENB_tag2el_1,
	5,	/* Count of tags in the map */
	asn_MAP_E2SM_RC_UEID_NG_ENB_oms_1,	/* Optional members */
	2, 1,	/* Root/Additions */
	4,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_E2SM_RC_UEID_NG_ENB = {
	"UEID-NG-ENB",
	"UEID-NG-ENB",
	&asn_OP_SEQUENCE,
	asn_DEF_E2SM_RC_UEID_NG_ENB_tags_1,
	sizeof(asn_DEF_E2SM_RC_UEID_NG_ENB_tags_1)
		/sizeof(asn_DEF_E2SM_RC_UEID_NG_ENB_tags_1[0]), /* 1 */
	asn_DEF_E2SM_RC_UEID_NG_ENB_tags_1,	/* Same as above */
	sizeof(asn_DEF_E2SM_RC_UEID_NG_ENB_tags_1)
		/sizeof(asn_DEF_E2SM_RC_UEID_NG_ENB_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_E2SM_RC_UEID_NG_ENB_1,
	5,	/* Elements count */
	&asn_SPC_E2SM_RC_UEID_NG_ENB_specs_1	/* Additional specs */
};

