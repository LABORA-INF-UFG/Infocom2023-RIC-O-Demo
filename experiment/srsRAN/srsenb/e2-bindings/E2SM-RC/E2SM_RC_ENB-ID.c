/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-COMMON-IEs"
 * 	found in "../E2SM/e2sm-v02.01.asn1"
 * 	`asn1c -pdu=all -fcompound-names -gen-PER -no-gen-OER -no-gen-example -fno-include-deps -fincludes-quoted -D E2SM-RC/`
 */

#include "E2SM_RC_ENB-ID.h"

static int
memb_E2SM_RC_macro_eNB_ID_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	const BIT_STRING_t *st = (const BIT_STRING_t *)sptr;
	size_t size;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	if(st->size > 0) {
		/* Size in bits */
		size = 8 * st->size - (st->bits_unused & 0x07);
	} else {
		size = 0;
	}
	
	if((size == 20)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static int
memb_E2SM_RC_home_eNB_ID_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	const BIT_STRING_t *st = (const BIT_STRING_t *)sptr;
	size_t size;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	if(st->size > 0) {
		/* Size in bits */
		size = 8 * st->size - (st->bits_unused & 0x07);
	} else {
		size = 0;
	}
	
	if((size == 28)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static int
memb_E2SM_RC_short_Macro_eNB_ID_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	const BIT_STRING_t *st = (const BIT_STRING_t *)sptr;
	size_t size;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	if(st->size > 0) {
		/* Size in bits */
		size = 8 * st->size - (st->bits_unused & 0x07);
	} else {
		size = 0;
	}
	
	if((size == 18)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static int
memb_E2SM_RC_long_Macro_eNB_ID_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	const BIT_STRING_t *st = (const BIT_STRING_t *)sptr;
	size_t size;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	if(st->size > 0) {
		/* Size in bits */
		size = 8 * st->size - (st->bits_unused & 0x07);
	} else {
		size = 0;
	}
	
	if((size == 21)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static asn_per_constraints_t asn_PER_memb_E2SM_RC_macro_eNB_ID_constr_2 CC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 0,  0,  20,  20 }	/* (SIZE(20..20)) */,
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_E2SM_RC_home_eNB_ID_constr_3 CC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 0,  0,  28,  28 }	/* (SIZE(28..28)) */,
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_E2SM_RC_short_Macro_eNB_ID_constr_5 CC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 0,  0,  18,  18 }	/* (SIZE(18..18)) */,
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_E2SM_RC_long_Macro_eNB_ID_constr_6 CC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 0,  0,  21,  21 }	/* (SIZE(21..21)) */,
	0, 0	/* No PER value map */
};
asn_per_constraints_t asn_PER_type_E2SM_RC_ENB_ID_constr_1 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  1,  1,  0,  1 }	/* (0..1,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
asn_TYPE_member_t asn_MBR_E2SM_RC_ENB_ID_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct E2SM_RC_ENB_ID, choice.macro_eNB_ID),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_BIT_STRING,
		0,
		{ 0, &asn_PER_memb_E2SM_RC_macro_eNB_ID_constr_2,  memb_E2SM_RC_macro_eNB_ID_constraint_1 },
		0, 0, /* No default value */
		"macro-eNB-ID"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct E2SM_RC_ENB_ID, choice.home_eNB_ID),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_BIT_STRING,
		0,
		{ 0, &asn_PER_memb_E2SM_RC_home_eNB_ID_constr_3,  memb_E2SM_RC_home_eNB_ID_constraint_1 },
		0, 0, /* No default value */
		"home-eNB-ID"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct E2SM_RC_ENB_ID, choice.short_Macro_eNB_ID),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_BIT_STRING,
		0,
		{ 0, &asn_PER_memb_E2SM_RC_short_Macro_eNB_ID_constr_5,  memb_E2SM_RC_short_Macro_eNB_ID_constraint_1 },
		0, 0, /* No default value */
		"short-Macro-eNB-ID"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct E2SM_RC_ENB_ID, choice.long_Macro_eNB_ID),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_BIT_STRING,
		0,
		{ 0, &asn_PER_memb_E2SM_RC_long_Macro_eNB_ID_constr_6,  memb_E2SM_RC_long_Macro_eNB_ID_constraint_1 },
		0, 0, /* No default value */
		"long-Macro-eNB-ID"
		},
};
static const asn_TYPE_tag2member_t asn_MAP_E2SM_RC_ENB_ID_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* macro-eNB-ID */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* home-eNB-ID */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* short-Macro-eNB-ID */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 } /* long-Macro-eNB-ID */
};
asn_CHOICE_specifics_t asn_SPC_E2SM_RC_ENB_ID_specs_1 = {
	sizeof(struct E2SM_RC_ENB_ID),
	offsetof(struct E2SM_RC_ENB_ID, _asn_ctx),
	offsetof(struct E2SM_RC_ENB_ID, present),
	sizeof(((struct E2SM_RC_ENB_ID *)0)->present),
	asn_MAP_E2SM_RC_ENB_ID_tag2el_1,
	4,	/* Count of tags in the map */
	0, 0,
	2	/* Extensions start */
};
asn_TYPE_descriptor_t asn_DEF_E2SM_RC_ENB_ID = {
	"ENB-ID",
	"ENB-ID",
	&asn_OP_CHOICE,
	0,	/* No effective tags (pointer) */
	0,	/* No effective tags (count) */
	0,	/* No tags (pointer) */
	0,	/* No tags (count) */
	{ 0, &asn_PER_type_E2SM_RC_ENB_ID_constr_1, CHOICE_constraint },
	asn_MBR_E2SM_RC_ENB_ID_1,
	4,	/* Elements count */
	&asn_SPC_E2SM_RC_ENB_ID_specs_1	/* Additional specs */
};

