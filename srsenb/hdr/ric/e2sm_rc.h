#ifndef RIC_E2SM_RC_H
#define RIC_E2SM_RC_H

#include <list>
#include <map>
#include <unordered_map>
#include <queue>

#include "pthread.h"

//#include "srslte/common/timeout.h"
#include "srsenb/hdr/stack/upper/common_enb.h"
#include "srslte/interfaces/enb_metrics_interface.h"
#include "srsenb/hdr/stack/rrc/rrc_metrics.h"

#include "srsenb/hdr/ric/e2ap.h"
#include "srsenb/hdr/ric/e2sm.h"
#include "srsenb/hdr/ric/timer_queue.h"
#include "srsenb/hdr/stack/mac/slicer_defs.h"

namespace ric {

class rc_model : public service_model
{
public:

  typedef struct subscription_model_data {
    long period;
    bool on_events;
    int timer_id;
  } subscription_model_data_t;

  rc_model(ric::agent *agent_);
  int init();
  void stop();
  virtual ~rc_model() { stop(); };
  static void *timer_callback(int timer_id,void *arg);
  void send_indications(int timer_id);
  int handle_subscription_add(ric::subscription_t *sub);
  int handle_subscription_del(ric::subscription_t *sub,int force,
			      long *cause,long *cause_detail);
  void handle_control(ric::control_t *control);

private:
  std::map<std::string,slicer::slice_config_t *> slices;
  std::map<std::string,std::list<std::string>> ues;
  pthread_mutex_t lock;
  uint8_t cpid;
  long serial_number;
  std::list<ric::subscription_t *> subscriptions;
  timer_queue queue;
  struct timespec sent_time;
  std::unordered_map<unsigned int, unsigned long> sent_ts_map; // timestamp of sent messages (INSERT) in nanoseconds
  std::unordered_map<unsigned int, unsigned long> recv_ts_map; // timestamp of received messages (CONTROL) in nanoseconds
  static inline unsigned long elapsed_nanoseconds(struct timespec ts) {
    return ts.tv_sec * 1000000000 + ts.tv_nsec;
}
  static inline double elapsed_seconds(unsigned long sent_ns, unsigned long recv_ns) {
    return (recv_ns - sent_ns) / 1000000000.0;     // converting to seconds
}
};

}

#endif
