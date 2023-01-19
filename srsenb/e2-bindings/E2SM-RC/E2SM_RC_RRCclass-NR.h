/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-COMMON-IEs"
 * 	found in "../E2SM/e2sm-v02.01.asn1"
 * 	`asn1c -pdu=all -fcompound-names -gen-PER -no-gen-OER -no-gen-example -fno-include-deps -fincludes-quoted -D E2SM-RC/`
 */

#ifndef	_E2SM_RC_RRCclass_NR_H_
#define	_E2SM_RC_RRCclass_NR_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NativeEnumerated.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum E2SM_RC_RRCclass_NR {
	E2SM_RC_RRCclass_NR_bCCH_BCH	= 0,
	E2SM_RC_RRCclass_NR_bCCH_DL_SCH	= 1,
	E2SM_RC_RRCclass_NR_dL_CCCH	= 2,
	E2SM_RC_RRCclass_NR_dL_DCCH	= 3,
	E2SM_RC_RRCclass_NR_pCCH	= 4,
	E2SM_RC_RRCclass_NR_uL_CCCH	= 5,
	E2SM_RC_RRCclass_NR_uL_CCCH1	= 6,
	E2SM_RC_RRCclass_NR_uL_DCCH	= 7
	/*
	 * Enumeration is extensible
	 */
} e_E2SM_RC_RRCclass_NR;

/* E2SM_RC_RRCclass-NR */
typedef long	 E2SM_RC_RRCclass_NR_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_E2SM_RC_RRCclass_NR_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_E2SM_RC_RRCclass_NR;
extern const asn_INTEGER_specifics_t asn_SPC_RRCclass_NR_specs_1;
asn_struct_free_f RRCclass_NR_free;
asn_struct_print_f RRCclass_NR_print;
asn_constr_check_f RRCclass_NR_constraint;
ber_type_decoder_f RRCclass_NR_decode_ber;
der_type_encoder_f RRCclass_NR_encode_der;
xer_type_decoder_f RRCclass_NR_decode_xer;
xer_type_encoder_f RRCclass_NR_encode_xer;
per_type_decoder_f RRCclass_NR_decode_uper;
per_type_encoder_f RRCclass_NR_encode_uper;
per_type_decoder_f RRCclass_NR_decode_aper;
per_type_encoder_f RRCclass_NR_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _E2SM_RC_RRCclass_NR_H_ */
#include "asn_internal.h"
