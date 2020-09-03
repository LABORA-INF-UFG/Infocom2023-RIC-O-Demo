#ifndef _RIC_E2AP_DECODE_H
#define _RIC_E2AP_DECODE_H

#include "E2AP_E2AP-PDU.h"

namespace ric {

class agent;

namespace e2ap {

int decode_pdu(ric::agent *agent,E2AP_E2AP_PDU_t *pdu,
	       const uint8_t * const buf,const uint32_t len);

}
}

#endif
