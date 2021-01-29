#ifndef RIC_E2SM_NEXRAN_H
#define RIC_E2SM_NEXRAN_H

#include <list>
#include <map>
#include <queue>

#include "pthread.h"

//#include "srslte/common/timeout.h"
#include "srsenb/hdr/stack/upper/common_enb.h"
#include "srslte/interfaces/enb_metrics_interface.h"
#include "srsenb/hdr/stack/rrc/rrc_metrics.h"

#include "srsenb/hdr/ric/e2ap.h"
#include "srsenb/hdr/ric/e2sm.h"
#include "srsenb/hdr/ric/timer_queue.h"

namespace ric {

class nexran_model : public service_model
{
public:

  nexran_model(ric::agent *agent_);
  int init();
  void stop();
  virtual ~nexran_model() { stop(); };
  int handle_subscription_add(ric::subscription_t *sub);
  int handle_subscription_del(ric::subscription_t *sub,int force,
			      long *cause,long *cause_detail);
  int handle_control(ric::control_t *control);

private:
  pthread_mutex_t lock;
  long serial_number;
};

}

#endif
