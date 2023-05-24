/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-NEXRAN-IEs"
 * 	found in "/home/cciadmin/Infocom2023-RIC-O-Demo/srsenb/src/ric/messages/asn1/e2sm-nexran-v01.00.asn1"
 * 	`asn1c -pdu=all -fcompound-names -gen-PER -no-gen-OER -no-gen-example -fno-include-deps -fincludes-quoted -D /home/cciadmin/Infocom2023-RIC-O-Demo/build/srsenb/src/ric/messages/E2SM-NEXRAN/`
 */

#include "E2SM_NEXRAN_ProportionalAllocationPolicy.h"

static int
memb_E2SM_NEXRAN_share_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 0 && value <= 1024)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static asn_per_constraints_t asn_PER_memb_E2SM_NEXRAN_share_constr_2 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 11,  11,  0,  1024 }	/* (0..1024) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
asn_TYPE_member_t asn_MBR_E2SM_NEXRAN_ProportionalAllocationPolicy_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct E2SM_NEXRAN_ProportionalAllocationPolicy, share),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,
		{ 0, &asn_PER_memb_E2SM_NEXRAN_share_constr_2,  memb_E2SM_NEXRAN_share_constraint_1 },
		0, 0, /* No default value */
		"share"
		},
};
static const ber_tlv_tag_t asn_DEF_E2SM_NEXRAN_ProportionalAllocationPolicy_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_E2SM_NEXRAN_ProportionalAllocationPolicy_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 } /* share */
};
asn_SEQUENCE_specifics_t asn_SPC_E2SM_NEXRAN_ProportionalAllocationPolicy_specs_1 = {
	sizeof(struct E2SM_NEXRAN_ProportionalAllocationPolicy),
	offsetof(struct E2SM_NEXRAN_ProportionalAllocationPolicy, _asn_ctx),
	asn_MAP_E2SM_NEXRAN_ProportionalAllocationPolicy_tag2el_1,
	1,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	-1,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_E2SM_NEXRAN_ProportionalAllocationPolicy = {
	"ProportionalAllocationPolicy",
	"ProportionalAllocationPolicy",
	&asn_OP_SEQUENCE,
	asn_DEF_E2SM_NEXRAN_ProportionalAllocationPolicy_tags_1,
	sizeof(asn_DEF_E2SM_NEXRAN_ProportionalAllocationPolicy_tags_1)
		/sizeof(asn_DEF_E2SM_NEXRAN_ProportionalAllocationPolicy_tags_1[0]), /* 1 */
	asn_DEF_E2SM_NEXRAN_ProportionalAllocationPolicy_tags_1,	/* Same as above */
	sizeof(asn_DEF_E2SM_NEXRAN_ProportionalAllocationPolicy_tags_1)
		/sizeof(asn_DEF_E2SM_NEXRAN_ProportionalAllocationPolicy_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_E2SM_NEXRAN_ProportionalAllocationPolicy_1,
	1,	/* Elements count */
	&asn_SPC_E2SM_NEXRAN_ProportionalAllocationPolicy_specs_1	/* Additional specs */
};

