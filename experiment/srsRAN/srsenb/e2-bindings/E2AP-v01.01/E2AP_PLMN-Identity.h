/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2AP-IEs"
 * 	found in "/local/mnt/openairinterface5g/openair2/RIC_AGENT/MESSAGES/ASN1/R01/e2ap-v01.00.asn1"
 * 	`asn1c -pdu=all -fcompound-names -gen-PER -no-gen-OER -no-gen-example -fno-include-deps -fincludes-quoted -D /local/mnt/openairinterface5g/cmake_targets/ran_build/build/CMakeFiles/E2AP/`
 */

#ifndef	_E2AP_PLMN_Identity_H_
#define	_E2AP_PLMN_Identity_H_


#include "asn_application.h"

/* Including external dependencies */
#include "OCTET_STRING.h"

#ifdef __cplusplus
extern "C" {
#endif

/* E2AP_PLMN-Identity */
typedef OCTET_STRING_t	 E2AP_PLMN_Identity_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_E2AP_PLMN_Identity_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_E2AP_PLMN_Identity;
asn_struct_free_f E2AP_PLMN_Identity_free;
asn_struct_print_f E2AP_PLMN_Identity_print;
asn_constr_check_f E2AP_PLMN_Identity_constraint;
ber_type_decoder_f E2AP_PLMN_Identity_decode_ber;
der_type_encoder_f E2AP_PLMN_Identity_encode_der;
xer_type_decoder_f E2AP_PLMN_Identity_decode_xer;
xer_type_encoder_f E2AP_PLMN_Identity_encode_xer;
per_type_decoder_f E2AP_PLMN_Identity_decode_uper;
per_type_encoder_f E2AP_PLMN_Identity_encode_uper;
per_type_decoder_f E2AP_PLMN_Identity_decode_aper;
per_type_encoder_f E2AP_PLMN_Identity_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _E2AP_PLMN_Identity_H_ */
#include "asn_internal.h"
