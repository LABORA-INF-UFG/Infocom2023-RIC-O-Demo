/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2AP-PDU-Contents"
 * 	found in "/local/mnt/openairinterface5g/openair2/RIC_AGENT/MESSAGES/ASN1/R01/e2ap-v01.00.asn1"
 * 	`asn1c -pdu=all -fcompound-names -gen-PER -no-gen-OER -no-gen-example -fno-include-deps -fincludes-quoted -D /local/mnt/openairinterface5g/cmake_targets/ran_build/build/CMakeFiles/E2AP/`
 */

#ifndef	_E2AP_RANfunctionIDcause_Item_H_
#define	_E2AP_RANfunctionIDcause_Item_H_


#include "asn_application.h"

/* Including external dependencies */
#include "E2AP_RANfunctionID.h"
#include "E2AP_Cause.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* E2AP_RANfunctionIDcause-Item */
typedef struct E2AP_RANfunctionIDcause_Item {
	E2AP_RANfunctionID_t	 ranFunctionID;
	E2AP_Cause_t	 cause;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} E2AP_RANfunctionIDcause_Item_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_E2AP_RANfunctionIDcause_Item;
extern asn_SEQUENCE_specifics_t asn_SPC_E2AP_RANfunctionIDcause_Item_specs_1;
extern asn_TYPE_member_t asn_MBR_E2AP_RANfunctionIDcause_Item_1[2];

#ifdef __cplusplus
}
#endif

#endif	/* _E2AP_RANfunctionIDcause_Item_H_ */
#include "asn_internal.h"
