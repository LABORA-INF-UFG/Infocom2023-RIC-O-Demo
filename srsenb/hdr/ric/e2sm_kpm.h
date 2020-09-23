#ifndef RIC_E2SM_KPM_H
#define RIC_E2SM_KPM_H

#include <list>
#include <queue>

#include "pthread.h"

#include "srslte/common/timeout.h"

#include "srsenb/hdr/ric/e2ap.h"
#include "srsenb/hdr/ric/e2sm.h"

namespace ric {

    /*
class timer_queue_dispatcher : thread {
pthread_cond_timedwaits until next timeout, then callback sent to
task_queue for execution.
    
namespace e2sm {
namespace kpm {

typedef struct report_periods {
    std::list<long> periods;
} report_periods_t;

}
}
    */

class kpm_timeout_callback;

class kpm_model : public service_model
{
public:
  kpm_model(ric::agent *agent_):
    service_model(agent_,"ORAN-E2SM-KPM","1.3.6.1.4.1.1.1.2.2"),
    period_ms(-1), timeout(), callback(NULL), serial_number(1) {};
  int init();
  virtual ~kpm_model() {};
  void send_indication();
  int handle_subscription_add(ric::subscription_t *sub);
  int handle_subscription_del(ric::subscription_t *sub,int force,
			      long *cause,long *cause_detail);
  int handle_control(ric::control_t *control);

private:
  int period_ms;
  srslte::timeout timeout;
  kpm_timeout_callback *callback;
  std::list<ric::subscription_t *> subscriptions;
  long serial_number;
};

class kpm_timeout_callback : public srslte::timeout_callback
{
public:
  kpm_timeout_callback(kpm_model *model_) : model(model_) {};
  virtual ~kpm_timeout_callback() {};
  void timeout_expired(uint32_t timeout_id) {
      model->agent->push_task([this]() { model->send_indication(); });
  };
private:
  kpm_model *model;
};

}

#endif
