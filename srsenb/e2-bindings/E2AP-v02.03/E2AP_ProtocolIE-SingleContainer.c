/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2AP-Containers"
 * 	found in "../e2ap-v02.03.asn1"
 * 	`asn1c -pdu=all -fcompound-names -fincludes-quoted -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D EXACT/`
 */

#include "E2AP_ProtocolIE-SingleContainer.h"

/*
 * This type is implemented using E2AP_RICaction_ToBeSetup_ItemIEs,
 * so here we adjust the DEF accordingly.
 */
/*
 * This type is implemented using E2AP_RICaction_Admitted_ItemIEs,
 * so here we adjust the DEF accordingly.
 */
/*
 * This type is implemented using E2AP_RICaction_NotAdmitted_ItemIEs,
 * so here we adjust the DEF accordingly.
 */
/*
 * This type is implemented using E2AP_RICsubscription_withCause_ItemIEs,
 * so here we adjust the DEF accordingly.
 */
/*
 * This type is implemented using E2AP_E2connectionUpdate_ItemIEs,
 * so here we adjust the DEF accordingly.
 */
/*
 * This type is implemented using E2AP_E2connectionUpdateRemove_ItemIEs,
 * so here we adjust the DEF accordingly.
 */
/*
 * This type is implemented using E2AP_E2connectionSetupFailed_ItemIEs,
 * so here we adjust the DEF accordingly.
 */
/*
 * This type is implemented using E2AP_E2nodeComponentConfigAddition_ItemIEs,
 * so here we adjust the DEF accordingly.
 */
/*
 * This type is implemented using E2AP_E2nodeComponentConfigUpdate_ItemIEs,
 * so here we adjust the DEF accordingly.
 */
/*
 * This type is implemented using E2AP_E2nodeComponentConfigRemoval_ItemIEs,
 * so here we adjust the DEF accordingly.
 */
/*
 * This type is implemented using E2AP_E2nodeTNLassociationRemoval_ItemIEs,
 * so here we adjust the DEF accordingly.
 */
/*
 * This type is implemented using E2AP_E2nodeComponentConfigAdditionAck_ItemIEs,
 * so here we adjust the DEF accordingly.
 */
/*
 * This type is implemented using E2AP_E2nodeComponentConfigUpdateAck_ItemIEs,
 * so here we adjust the DEF accordingly.
 */
/*
 * This type is implemented using E2AP_E2nodeComponentConfigRemovalAck_ItemIEs,
 * so here we adjust the DEF accordingly.
 */
/*
 * This type is implemented using E2AP_RANfunction_ItemIEs,
 * so here we adjust the DEF accordingly.
 */
/*
 * This type is implemented using E2AP_RANfunctionID_ItemIEs,
 * so here we adjust the DEF accordingly.
 */
/*
 * This type is implemented using E2AP_RANfunctionIDcause_ItemIEs,
 * so here we adjust the DEF accordingly.
 */
static const ber_tlv_tag_t asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P0_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
asn_TYPE_descriptor_t asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P0 = {
	"ProtocolIE-SingleContainer",
	"ProtocolIE-SingleContainer",
	&asn_OP_SEQUENCE,
	asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P0_tags_1,
	sizeof(asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P0_tags_1)
		/sizeof(asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P0_tags_1[0]), /* 1 */
	asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P0_tags_1,	/* Same as above */
	sizeof(asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P0_tags_1)
		/sizeof(asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P0_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_E2AP_RICaction_ToBeSetup_ItemIEs_1,
	3,	/* Elements count */
	&asn_SPC_E2AP_RICaction_ToBeSetup_ItemIEs_specs_1	/* Additional specs */
};

static const ber_tlv_tag_t asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P1_tags_2[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
asn_TYPE_descriptor_t asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P1 = {
	"ProtocolIE-SingleContainer",
	"ProtocolIE-SingleContainer",
	&asn_OP_SEQUENCE,
	asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P1_tags_2,
	sizeof(asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P1_tags_2)
		/sizeof(asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P1_tags_2[0]), /* 1 */
	asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P1_tags_2,	/* Same as above */
	sizeof(asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P1_tags_2)
		/sizeof(asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P1_tags_2[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_E2AP_RICaction_Admitted_ItemIEs_5,
	3,	/* Elements count */
	&asn_SPC_E2AP_RICaction_Admitted_ItemIEs_specs_5	/* Additional specs */
};

static const ber_tlv_tag_t asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P2_tags_3[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
asn_TYPE_descriptor_t asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P2 = {
	"ProtocolIE-SingleContainer",
	"ProtocolIE-SingleContainer",
	&asn_OP_SEQUENCE,
	asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P2_tags_3,
	sizeof(asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P2_tags_3)
		/sizeof(asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P2_tags_3[0]), /* 1 */
	asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P2_tags_3,	/* Same as above */
	sizeof(asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P2_tags_3)
		/sizeof(asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P2_tags_3[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_E2AP_RICaction_NotAdmitted_ItemIEs_9,
	3,	/* Elements count */
	&asn_SPC_E2AP_RICaction_NotAdmitted_ItemIEs_specs_9	/* Additional specs */
};

static const ber_tlv_tag_t asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P3_tags_4[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
asn_TYPE_descriptor_t asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P3 = {
	"ProtocolIE-SingleContainer",
	"ProtocolIE-SingleContainer",
	&asn_OP_SEQUENCE,
	asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P3_tags_4,
	sizeof(asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P3_tags_4)
		/sizeof(asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P3_tags_4[0]), /* 1 */
	asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P3_tags_4,	/* Same as above */
	sizeof(asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P3_tags_4)
		/sizeof(asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P3_tags_4[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_E2AP_RICsubscription_withCause_ItemIEs_13,
	3,	/* Elements count */
	&asn_SPC_E2AP_RICsubscription_withCause_ItemIEs_specs_13	/* Additional specs */
};

static const ber_tlv_tag_t asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P4_tags_5[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
asn_TYPE_descriptor_t asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P4 = {
	"ProtocolIE-SingleContainer",
	"ProtocolIE-SingleContainer",
	&asn_OP_SEQUENCE,
	asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P4_tags_5,
	sizeof(asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P4_tags_5)
		/sizeof(asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P4_tags_5[0]), /* 1 */
	asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P4_tags_5,	/* Same as above */
	sizeof(asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P4_tags_5)
		/sizeof(asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P4_tags_5[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_E2AP_E2connectionUpdate_ItemIEs_17,
	3,	/* Elements count */
	&asn_SPC_E2AP_E2connectionUpdate_ItemIEs_specs_17	/* Additional specs */
};

static const ber_tlv_tag_t asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P5_tags_6[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
asn_TYPE_descriptor_t asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P5 = {
	"ProtocolIE-SingleContainer",
	"ProtocolIE-SingleContainer",
	&asn_OP_SEQUENCE,
	asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P5_tags_6,
	sizeof(asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P5_tags_6)
		/sizeof(asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P5_tags_6[0]), /* 1 */
	asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P5_tags_6,	/* Same as above */
	sizeof(asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P5_tags_6)
		/sizeof(asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P5_tags_6[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_E2AP_E2connectionUpdateRemove_ItemIEs_21,
	3,	/* Elements count */
	&asn_SPC_E2AP_E2connectionUpdateRemove_ItemIEs_specs_21	/* Additional specs */
};

static const ber_tlv_tag_t asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P6_tags_7[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
asn_TYPE_descriptor_t asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P6 = {
	"ProtocolIE-SingleContainer",
	"ProtocolIE-SingleContainer",
	&asn_OP_SEQUENCE,
	asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P6_tags_7,
	sizeof(asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P6_tags_7)
		/sizeof(asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P6_tags_7[0]), /* 1 */
	asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P6_tags_7,	/* Same as above */
	sizeof(asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P6_tags_7)
		/sizeof(asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P6_tags_7[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_E2AP_E2connectionSetupFailed_ItemIEs_25,
	3,	/* Elements count */
	&asn_SPC_E2AP_E2connectionSetupFailed_ItemIEs_specs_25	/* Additional specs */
};

static const ber_tlv_tag_t asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P7_tags_8[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
asn_TYPE_descriptor_t asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P7 = {
	"ProtocolIE-SingleContainer",
	"ProtocolIE-SingleContainer",
	&asn_OP_SEQUENCE,
	asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P7_tags_8,
	sizeof(asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P7_tags_8)
		/sizeof(asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P7_tags_8[0]), /* 1 */
	asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P7_tags_8,	/* Same as above */
	sizeof(asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P7_tags_8)
		/sizeof(asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P7_tags_8[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_E2AP_E2nodeComponentConfigAddition_ItemIEs_29,
	3,	/* Elements count */
	&asn_SPC_E2AP_E2nodeComponentConfigAddition_ItemIEs_specs_29	/* Additional specs */
};

static const ber_tlv_tag_t asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P8_tags_9[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
asn_TYPE_descriptor_t asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P8 = {
	"ProtocolIE-SingleContainer",
	"ProtocolIE-SingleContainer",
	&asn_OP_SEQUENCE,
	asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P8_tags_9,
	sizeof(asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P8_tags_9)
		/sizeof(asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P8_tags_9[0]), /* 1 */
	asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P8_tags_9,	/* Same as above */
	sizeof(asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P8_tags_9)
		/sizeof(asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P8_tags_9[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_E2AP_E2nodeComponentConfigUpdate_ItemIEs_33,
	3,	/* Elements count */
	&asn_SPC_E2AP_E2nodeComponentConfigUpdate_ItemIEs_specs_33	/* Additional specs */
};

static const ber_tlv_tag_t asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P9_tags_10[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
asn_TYPE_descriptor_t asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P9 = {
	"ProtocolIE-SingleContainer",
	"ProtocolIE-SingleContainer",
	&asn_OP_SEQUENCE,
	asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P9_tags_10,
	sizeof(asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P9_tags_10)
		/sizeof(asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P9_tags_10[0]), /* 1 */
	asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P9_tags_10,	/* Same as above */
	sizeof(asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P9_tags_10)
		/sizeof(asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P9_tags_10[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_E2AP_E2nodeComponentConfigRemoval_ItemIEs_37,
	3,	/* Elements count */
	&asn_SPC_E2AP_E2nodeComponentConfigRemoval_ItemIEs_specs_37	/* Additional specs */
};

static const ber_tlv_tag_t asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P10_tags_11[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
asn_TYPE_descriptor_t asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P10 = {
	"ProtocolIE-SingleContainer",
	"ProtocolIE-SingleContainer",
	&asn_OP_SEQUENCE,
	asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P10_tags_11,
	sizeof(asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P10_tags_11)
		/sizeof(asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P10_tags_11[0]), /* 1 */
	asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P10_tags_11,	/* Same as above */
	sizeof(asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P10_tags_11)
		/sizeof(asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P10_tags_11[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_E2AP_E2nodeTNLassociationRemoval_ItemIEs_41,
	3,	/* Elements count */
	&asn_SPC_E2AP_E2nodeTNLassociationRemoval_ItemIEs_specs_41	/* Additional specs */
};

static const ber_tlv_tag_t asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P11_tags_12[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
asn_TYPE_descriptor_t asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P11 = {
	"ProtocolIE-SingleContainer",
	"ProtocolIE-SingleContainer",
	&asn_OP_SEQUENCE,
	asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P11_tags_12,
	sizeof(asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P11_tags_12)
		/sizeof(asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P11_tags_12[0]), /* 1 */
	asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P11_tags_12,	/* Same as above */
	sizeof(asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P11_tags_12)
		/sizeof(asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P11_tags_12[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_E2AP_E2nodeComponentConfigAdditionAck_ItemIEs_45,
	3,	/* Elements count */
	&asn_SPC_E2AP_E2nodeComponentConfigAdditionAck_ItemIEs_specs_45	/* Additional specs */
};

static const ber_tlv_tag_t asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P12_tags_13[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
asn_TYPE_descriptor_t asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P12 = {
	"ProtocolIE-SingleContainer",
	"ProtocolIE-SingleContainer",
	&asn_OP_SEQUENCE,
	asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P12_tags_13,
	sizeof(asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P12_tags_13)
		/sizeof(asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P12_tags_13[0]), /* 1 */
	asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P12_tags_13,	/* Same as above */
	sizeof(asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P12_tags_13)
		/sizeof(asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P12_tags_13[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_E2AP_E2nodeComponentConfigUpdateAck_ItemIEs_49,
	3,	/* Elements count */
	&asn_SPC_E2AP_E2nodeComponentConfigUpdateAck_ItemIEs_specs_49	/* Additional specs */
};

static const ber_tlv_tag_t asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P13_tags_14[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
asn_TYPE_descriptor_t asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P13 = {
	"ProtocolIE-SingleContainer",
	"ProtocolIE-SingleContainer",
	&asn_OP_SEQUENCE,
	asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P13_tags_14,
	sizeof(asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P13_tags_14)
		/sizeof(asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P13_tags_14[0]), /* 1 */
	asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P13_tags_14,	/* Same as above */
	sizeof(asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P13_tags_14)
		/sizeof(asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P13_tags_14[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_E2AP_E2nodeComponentConfigRemovalAck_ItemIEs_53,
	3,	/* Elements count */
	&asn_SPC_E2AP_E2nodeComponentConfigRemovalAck_ItemIEs_specs_53	/* Additional specs */
};

static const ber_tlv_tag_t asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P14_tags_15[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
asn_TYPE_descriptor_t asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P14 = {
	"ProtocolIE-SingleContainer",
	"ProtocolIE-SingleContainer",
	&asn_OP_SEQUENCE,
	asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P14_tags_15,
	sizeof(asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P14_tags_15)
		/sizeof(asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P14_tags_15[0]), /* 1 */
	asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P14_tags_15,	/* Same as above */
	sizeof(asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P14_tags_15)
		/sizeof(asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P14_tags_15[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_E2AP_RANfunction_ItemIEs_57,
	3,	/* Elements count */
	&asn_SPC_E2AP_RANfunction_ItemIEs_specs_57	/* Additional specs */
};

static const ber_tlv_tag_t asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P15_tags_16[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
asn_TYPE_descriptor_t asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P15 = {
	"ProtocolIE-SingleContainer",
	"ProtocolIE-SingleContainer",
	&asn_OP_SEQUENCE,
	asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P15_tags_16,
	sizeof(asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P15_tags_16)
		/sizeof(asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P15_tags_16[0]), /* 1 */
	asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P15_tags_16,	/* Same as above */
	sizeof(asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P15_tags_16)
		/sizeof(asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P15_tags_16[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_E2AP_RANfunctionID_ItemIEs_61,
	3,	/* Elements count */
	&asn_SPC_E2AP_RANfunctionID_ItemIEs_specs_61	/* Additional specs */
};

static const ber_tlv_tag_t asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P16_tags_17[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
asn_TYPE_descriptor_t asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P16 = {
	"ProtocolIE-SingleContainer",
	"ProtocolIE-SingleContainer",
	&asn_OP_SEQUENCE,
	asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P16_tags_17,
	sizeof(asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P16_tags_17)
		/sizeof(asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P16_tags_17[0]), /* 1 */
	asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P16_tags_17,	/* Same as above */
	sizeof(asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P16_tags_17)
		/sizeof(asn_DEF_E2AP_ProtocolIE_SingleContainer_1999P16_tags_17[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_E2AP_RANfunctionIDcause_ItemIEs_65,
	3,	/* Elements count */
	&asn_SPC_E2AP_RANfunctionIDcause_ItemIEs_specs_65	/* Additional specs */
};

