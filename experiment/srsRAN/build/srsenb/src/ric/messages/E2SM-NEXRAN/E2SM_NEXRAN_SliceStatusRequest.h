/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-NEXRAN-IEs"
 * 	found in "/home/cciadmin/Infocom2023-RIC-O-Demo/srsenb/src/ric/messages/asn1/e2sm-nexran-v01.00.asn1"
 * 	`asn1c -pdu=all -fcompound-names -gen-PER -no-gen-OER -no-gen-example -fno-include-deps -fincludes-quoted -D /home/cciadmin/Infocom2023-RIC-O-Demo/build/srsenb/src/ric/messages/E2SM-NEXRAN/`
 */

#ifndef	_E2SM_NEXRAN_SliceStatusRequest_H_
#define	_E2SM_NEXRAN_SliceStatusRequest_H_


#include "asn_application.h"

/* Including external dependencies */
#include "E2SM_NEXRAN_SliceName.h"
#include "asn_SEQUENCE_OF.h"
#include "constr_SEQUENCE_OF.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* E2SM_NEXRAN_SliceStatusRequest */
typedef struct E2SM_NEXRAN_SliceStatusRequest {
	struct E2SM_NEXRAN_SliceStatusRequest__sliceNameList {
		A_SEQUENCE_OF(E2SM_NEXRAN_SliceName_t) list;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} sliceNameList;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} E2SM_NEXRAN_SliceStatusRequest_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_E2SM_NEXRAN_SliceStatusRequest;
extern asn_SEQUENCE_specifics_t asn_SPC_E2SM_NEXRAN_SliceStatusRequest_specs_1;
extern asn_TYPE_member_t asn_MBR_E2SM_NEXRAN_SliceStatusRequest_1[1];

#ifdef __cplusplus
}
#endif

#endif	/* _E2SM_NEXRAN_SliceStatusRequest_H_ */
#include "asn_internal.h"
