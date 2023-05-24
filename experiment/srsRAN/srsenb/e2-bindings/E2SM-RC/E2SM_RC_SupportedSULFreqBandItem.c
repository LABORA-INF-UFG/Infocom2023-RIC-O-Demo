/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-COMMON-IEs"
 * 	found in "../E2SM/e2sm-v02.01.asn1"
 * 	`asn1c -pdu=all -fcompound-names -gen-PER -no-gen-OER -no-gen-example -fno-include-deps -fincludes-quoted -D E2SM-RC/`
 */

#include "E2SM_RC_SupportedSULFreqBandItem.h"

static int
memb_E2SM_RC_freqBandIndicatorNr_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 1 && value <= 1024)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static asn_per_constraints_t asn_PER_memb_E2SM_RC_freqBandIndicatorNr_constr_2 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  10,  10,  1,  1024 }	/* (1..1024,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
asn_TYPE_member_t asn_MBR_E2SM_RC_SupportedSULFreqBandItem_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct E2SM_RC_SupportedSULFreqBandItem, freqBandIndicatorNr),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,
		{ 0, &asn_PER_memb_E2SM_RC_freqBandIndicatorNr_constr_2,  memb_E2SM_RC_freqBandIndicatorNr_constraint_1 },
		0, 0, /* No default value */
		"freqBandIndicatorNr"
		},
};
static const ber_tlv_tag_t asn_DEF_E2SM_RC_SupportedSULFreqBandItem_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_E2SM_RC_SupportedSULFreqBandItem_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 } /* freqBandIndicatorNr */
};
asn_SEQUENCE_specifics_t asn_SPC_E2SM_RC_SupportedSULFreqBandItem_specs_1 = {
	sizeof(struct E2SM_RC_SupportedSULFreqBandItem),
	offsetof(struct E2SM_RC_SupportedSULFreqBandItem, _asn_ctx),
	asn_MAP_E2SM_RC_SupportedSULFreqBandItem_tag2el_1,
	1,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	1,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_E2SM_RC_SupportedSULFreqBandItem = {
	"SupportedSULFreqBandItem",
	"SupportedSULFreqBandItem",
	&asn_OP_SEQUENCE,
	asn_DEF_E2SM_RC_SupportedSULFreqBandItem_tags_1,
	sizeof(asn_DEF_E2SM_RC_SupportedSULFreqBandItem_tags_1)
		/sizeof(asn_DEF_E2SM_RC_SupportedSULFreqBandItem_tags_1[0]), /* 1 */
	asn_DEF_E2SM_RC_SupportedSULFreqBandItem_tags_1,	/* Same as above */
	sizeof(asn_DEF_E2SM_RC_SupportedSULFreqBandItem_tags_1)
		/sizeof(asn_DEF_E2SM_RC_SupportedSULFreqBandItem_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_E2SM_RC_SupportedSULFreqBandItem_1,
	1,	/* Elements count */
	&asn_SPC_E2SM_RC_SupportedSULFreqBandItem_specs_1	/* Additional specs */
};

