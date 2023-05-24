/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-NEXRAN-IEs"
 * 	found in "/home/vikas/srslte-ric/srsenb/src/ric/messages/asn1/e2sm-nexran-v01.00.asn1"
 * 	`asn1c -pdu=all -fcompound-names -gen-PER -no-gen-OER -no-gen-example -fno-include-deps -fincludes-quoted -D /home/vikas/srslte-ric/build/srsenb/src/ric/messages/E2SM-NEXRAN/`
 */

#ifndef	_E2SM_NEXRAN_GUMMEI_H_
#define	_E2SM_NEXRAN_GUMMEI_H_


#include "asn_application.h"

/* Including external dependencies */
#include "BIT_STRING.h"

#ifdef __cplusplus
extern "C" {
#endif

/* E2SM_NEXRAN_GUMMEI */
typedef BIT_STRING_t	 E2SM_NEXRAN_GUMMEI_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_E2SM_NEXRAN_GUMMEI_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_E2SM_NEXRAN_GUMMEI;
asn_struct_free_f E2SM_NEXRAN_GUMMEI_free;
asn_struct_print_f E2SM_NEXRAN_GUMMEI_print;
asn_constr_check_f E2SM_NEXRAN_GUMMEI_constraint;
ber_type_decoder_f E2SM_NEXRAN_GUMMEI_decode_ber;
der_type_encoder_f E2SM_NEXRAN_GUMMEI_encode_der;
xer_type_decoder_f E2SM_NEXRAN_GUMMEI_decode_xer;
xer_type_encoder_f E2SM_NEXRAN_GUMMEI_encode_xer;
per_type_decoder_f E2SM_NEXRAN_GUMMEI_decode_uper;
per_type_encoder_f E2SM_NEXRAN_GUMMEI_encode_uper;
per_type_decoder_f E2SM_NEXRAN_GUMMEI_decode_aper;
per_type_encoder_f E2SM_NEXRAN_GUMMEI_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _E2SM_NEXRAN_GUMMEI_H_ */
#include "asn_internal.h"
