/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-NI-IEs"
 * 	found in "/local/mnt/openairinterface5g/openair2/RIC_AGENT/MESSAGES/ASN1/R01/e2sm-ni-v01.00.asn1"
 * 	`asn1c -pdu=all -fcompound-names -gen-PER -no-gen-OER -no-gen-example -fno-include-deps -fincludes-quoted -D /local/mnt/openairinterface5g/cmake_targets/ran_build/build/CMakeFiles/E2SM-NI/`
 */

#include "E2SM_NI_TypeOfMessage.h"

/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
asn_per_constraints_t asn_PER_type_E2SM_NI_TypeOfMessage_constr_1 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 2,  2,  0,  3 }	/* (0..3) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static const asn_INTEGER_enum_map_t asn_MAP_E2SM_NI_TypeOfMessage_value2enum_1[] = {
	{ 0,	7,	"nothing" },
	{ 1,	18,	"initiating-message" },
	{ 2,	18,	"successful-outcome" },
	{ 3,	20,	"unsuccessful-outcome" }
};
static const unsigned int asn_MAP_E2SM_NI_TypeOfMessage_enum2value_1[] = {
	1,	/* initiating-message(1) */
	0,	/* nothing(0) */
	2,	/* successful-outcome(2) */
	3	/* unsuccessful-outcome(3) */
};
const asn_INTEGER_specifics_t asn_SPC_E2SM_NI_TypeOfMessage_specs_1 = {
	asn_MAP_E2SM_NI_TypeOfMessage_value2enum_1,	/* "tag" => N; sorted by tag */
	asn_MAP_E2SM_NI_TypeOfMessage_enum2value_1,	/* N => "tag"; sorted by N */
	4,	/* Number of elements in the maps */
	0,	/* Enumeration is not extensible */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static const ber_tlv_tag_t asn_DEF_E2SM_NI_TypeOfMessage_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
asn_TYPE_descriptor_t asn_DEF_E2SM_NI_TypeOfMessage = {
	"TypeOfMessage",
	"TypeOfMessage",
	&asn_OP_NativeEnumerated,
	asn_DEF_E2SM_NI_TypeOfMessage_tags_1,
	sizeof(asn_DEF_E2SM_NI_TypeOfMessage_tags_1)
		/sizeof(asn_DEF_E2SM_NI_TypeOfMessage_tags_1[0]), /* 1 */
	asn_DEF_E2SM_NI_TypeOfMessage_tags_1,	/* Same as above */
	sizeof(asn_DEF_E2SM_NI_TypeOfMessage_tags_1)
		/sizeof(asn_DEF_E2SM_NI_TypeOfMessage_tags_1[0]), /* 1 */
	{ 0, &asn_PER_type_E2SM_NI_TypeOfMessage_constr_1, NativeEnumerated_constraint },
	0, 0,	/* Defined elsewhere */
	&asn_SPC_E2SM_NI_TypeOfMessage_specs_1	/* Additional specs */
};

