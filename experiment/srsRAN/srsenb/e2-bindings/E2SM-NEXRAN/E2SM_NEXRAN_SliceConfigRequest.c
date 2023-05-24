/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-NEXRAN-IEs"
 * 	found in "/home/vikas/srslte-ric/srsenb/src/ric/messages/asn1/e2sm-nexran-v01.00.asn1"
 * 	`asn1c -pdu=all -fcompound-names -gen-PER -no-gen-OER -no-gen-example -fno-include-deps -fincludes-quoted -D /home/vikas/srslte-ric/build/srsenb/src/ric/messages/E2SM-NEXRAN/`
 */

#include "E2SM_NEXRAN_SliceConfigRequest.h"

#include "E2SM_NEXRAN_SliceConfig.h"
static int
memb_E2SM_NEXRAN_sliceConfigList_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	size_t size;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	/* Determine the number of elements */
	size = _A_CSEQUENCE_FROM_VOID(sptr)->count;
	
	if((size >= 1 && size <= 16)) {
		/* Perform validation of the inner elements */
		return td->encoding_constraints.general_constraints(td, sptr, ctfailcb, app_key);
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static asn_per_constraints_t asn_PER_type_E2SM_NEXRAN_sliceConfigList_constr_2 CC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 4,  4,  1,  16 }	/* (SIZE(1..16)) */,
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_E2SM_NEXRAN_sliceConfigList_constr_2 CC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 4,  4,  1,  16 }	/* (SIZE(1..16)) */,
	0, 0	/* No PER value map */
};
static asn_TYPE_member_t asn_MBR_E2SM_NEXRAN_sliceConfigList_2[] = {
	{ ATF_POINTER, 0, 0,
		(ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
		0,
		&asn_DEF_E2SM_NEXRAN_SliceConfig,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		""
		},
};
static const ber_tlv_tag_t asn_DEF_E2SM_NEXRAN_sliceConfigList_tags_2[] = {
	(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_SET_OF_specifics_t asn_SPC_E2SM_NEXRAN_sliceConfigList_specs_2 = {
	sizeof(struct E2SM_NEXRAN_SliceConfigRequest__sliceConfigList),
	offsetof(struct E2SM_NEXRAN_SliceConfigRequest__sliceConfigList, _asn_ctx),
	0,	/* XER encoding is XMLDelimitedItemList */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_E2SM_NEXRAN_sliceConfigList_2 = {
	"sliceConfigList",
	"sliceConfigList",
	&asn_OP_SEQUENCE_OF,
	asn_DEF_E2SM_NEXRAN_sliceConfigList_tags_2,
	sizeof(asn_DEF_E2SM_NEXRAN_sliceConfigList_tags_2)
		/sizeof(asn_DEF_E2SM_NEXRAN_sliceConfigList_tags_2[0]) - 1, /* 1 */
	asn_DEF_E2SM_NEXRAN_sliceConfigList_tags_2,	/* Same as above */
	sizeof(asn_DEF_E2SM_NEXRAN_sliceConfigList_tags_2)
		/sizeof(asn_DEF_E2SM_NEXRAN_sliceConfigList_tags_2[0]), /* 2 */
	{ 0, &asn_PER_type_E2SM_NEXRAN_sliceConfigList_constr_2, SEQUENCE_OF_constraint },
	asn_MBR_E2SM_NEXRAN_sliceConfigList_2,
	1,	/* Single element */
	&asn_SPC_E2SM_NEXRAN_sliceConfigList_specs_2	/* Additional specs */
};

asn_TYPE_member_t asn_MBR_E2SM_NEXRAN_SliceConfigRequest_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct E2SM_NEXRAN_SliceConfigRequest, sliceConfigList),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		0,
		&asn_DEF_E2SM_NEXRAN_sliceConfigList_2,
		0,
		{ 0, &asn_PER_memb_E2SM_NEXRAN_sliceConfigList_constr_2,  memb_E2SM_NEXRAN_sliceConfigList_constraint_1 },
		0, 0, /* No default value */
		"sliceConfigList"
		},
};
static const ber_tlv_tag_t asn_DEF_E2SM_NEXRAN_SliceConfigRequest_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_E2SM_NEXRAN_SliceConfigRequest_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 } /* sliceConfigList */
};
asn_SEQUENCE_specifics_t asn_SPC_E2SM_NEXRAN_SliceConfigRequest_specs_1 = {
	sizeof(struct E2SM_NEXRAN_SliceConfigRequest),
	offsetof(struct E2SM_NEXRAN_SliceConfigRequest, _asn_ctx),
	asn_MAP_E2SM_NEXRAN_SliceConfigRequest_tag2el_1,
	1,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	1,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_E2SM_NEXRAN_SliceConfigRequest = {
	"SliceConfigRequest",
	"SliceConfigRequest",
	&asn_OP_SEQUENCE,
	asn_DEF_E2SM_NEXRAN_SliceConfigRequest_tags_1,
	sizeof(asn_DEF_E2SM_NEXRAN_SliceConfigRequest_tags_1)
		/sizeof(asn_DEF_E2SM_NEXRAN_SliceConfigRequest_tags_1[0]), /* 1 */
	asn_DEF_E2SM_NEXRAN_SliceConfigRequest_tags_1,	/* Same as above */
	sizeof(asn_DEF_E2SM_NEXRAN_SliceConfigRequest_tags_1)
		/sizeof(asn_DEF_E2SM_NEXRAN_SliceConfigRequest_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_E2SM_NEXRAN_SliceConfigRequest_1,
	1,	/* Elements count */
	&asn_SPC_E2SM_NEXRAN_SliceConfigRequest_specs_1	/* Additional specs */
};

