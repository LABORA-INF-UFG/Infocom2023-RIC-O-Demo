/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2AP-IEs"
 * 	found in "../e2ap-v02.03.asn1"
 * 	`asn1c -pdu=all -fcompound-names -fincludes-quoted -fno-include-deps -gen-PER -no-gen-OER -no-gen-example -D EXACT/`
 */

#ifndef	_E2AP_TimeToWait_H_
#define	_E2AP_TimeToWait_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NativeEnumerated.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum E2AP_TimeToWait {
	E2AP_TimeToWait_v1s	= 0,
	E2AP_TimeToWait_v2s	= 1,
	E2AP_TimeToWait_v5s	= 2,
	E2AP_TimeToWait_v10s	= 3,
	E2AP_TimeToWait_v20s	= 4,
	E2AP_TimeToWait_v60s	= 5
	/*
	 * Enumeration is extensible
	 */
} e_E2AP_TimeToWait;

/* E2AP_TimeToWait */
typedef long	 E2AP_TimeToWait_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_E2AP_TimeToWait;
asn_struct_free_f E2AP_TimeToWait_free;
asn_struct_print_f E2AP_TimeToWait_print;
asn_constr_check_f E2AP_TimeToWait_constraint;
ber_type_decoder_f E2AP_TimeToWait_decode_ber;
der_type_encoder_f E2AP_TimeToWait_encode_der;
xer_type_decoder_f E2AP_TimeToWait_decode_xer;
xer_type_encoder_f E2AP_TimeToWait_encode_xer;
per_type_decoder_f E2AP_TimeToWait_decode_uper;
per_type_encoder_f E2AP_TimeToWait_encode_uper;
per_type_decoder_f E2AP_TimeToWait_decode_aper;
per_type_encoder_f E2AP_TimeToWait_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _E2AP_TimeToWait_H_ */
#include "asn_internal.h"
