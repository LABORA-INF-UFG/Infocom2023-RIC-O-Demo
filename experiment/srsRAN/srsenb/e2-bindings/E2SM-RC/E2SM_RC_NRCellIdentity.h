/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-COMMON-IEs"
 * 	found in "../E2SM/e2sm-v02.01.asn1"
 * 	`asn1c -pdu=all -fcompound-names -gen-PER -no-gen-OER -no-gen-example -fno-include-deps -fincludes-quoted -D E2SM-RC/`
 */

#ifndef	_E2SM_RC_NRCellIdentity_H_
#define	_E2SM_RC_NRCellIdentity_H_


#include "asn_application.h"

/* Including external dependencies */
#include "BIT_STRING.h"

#ifdef __cplusplus
extern "C" {
#endif

/* E2SM_RC_NRCellIdentity */
typedef BIT_STRING_t	 E2SM_RC_NRCellIdentity_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_E2SM_RC_NRCellIdentity_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_E2SM_RC_NRCellIdentity;
asn_struct_free_f E2SM_RC_NRCellIdentity_free;
asn_struct_print_f E2SM_RC_NRCellIdentity_print;
asn_constr_check_f E2SM_RC_NRCellIdentity_constraint;
ber_type_decoder_f E2SM_RC_NRCellIdentity_decode_ber;
der_type_encoder_f E2SM_RC_NRCellIdentity_encode_der;
xer_type_decoder_f E2SM_RC_NRCellIdentity_decode_xer;
xer_type_encoder_f E2SM_RC_NRCellIdentity_encode_xer;
per_type_decoder_f E2SM_RC_NRCellIdentity_decode_uper;
per_type_encoder_f E2SM_RC_NRCellIdentity_encode_uper;
per_type_decoder_f E2SM_RC_NRCellIdentity_decode_aper;
per_type_encoder_f E2SM_RC_NRCellIdentity_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _E2SM_RC_NRCellIdentity_H_ */
#include "asn_internal.h"
