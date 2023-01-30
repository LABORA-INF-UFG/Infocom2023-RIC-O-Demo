#ifndef RIC_E2SM_KPM_H
#define RIC_E2SM_KPM_H

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

#include "E2SM_KPM_RT-Period-IE.h"

namespace ric {
namespace kpm {

#define NUM_PERIODS (E2SM_KPM_RT_Period_IE_ms10240 + 1)

typedef struct entity_metrics
{
  uint64_t dl_bytes;
  uint64_t ul_bytes;
  uint64_t dl_prbs;
  uint64_t ul_prbs;
  uint64_t dl_bytes_by_qci[MAX_NOF_QCI];
  uint64_t ul_bytes_by_qci[MAX_NOF_QCI];
  int64_t  tx_pkts;
  int64_t  tx_errors;
  int64_t  tx_brate;
  int64_t  rx_pkts;
  int64_t  rx_errors;
  int64_t  rx_brate;
  float    dl_cqi;
  float    dl_ri;
  float    dl_pmi;
  float    ul_phr;
  float    ul_sinr;
  float    ul_mcs;
  int64_t  ul_samples;
  float    dl_mcs;
  int64_t  dl_samples;
} entity_metrics_t;

class metrics;

#ifdef ENABLE_SLICER
class slice_metrics
{
public:

  slice_metrics() : slices() { };
  virtual ~slice_metrics() = default;
  void update(metrics *m,std::map<std::string,std::vector<uint16_t>> slice_map);
  void reset();

  std::map<std::string,entity_metrics_t> slices;
};
#endif

class metrics
{
public:

  metrics()
    : have_prbs(false),active_ue_count(0),ues(),total_ues(),
      dl_bytes_by_qci{0},ul_bytes_by_qci{0} {};
  virtual ~metrics() = default;
  void update(srsenb::enb_metrics_t *em);
  void reset();

  /* Current per-period deltas. */
  bool have_prbs;
  long active_ue_count;
  std::map<uint16_t,entity_metrics_t> ues;
  uint64_t dl_bytes_by_qci[MAX_NOF_QCI];
  uint64_t ul_bytes_by_qci[MAX_NOF_QCI];

  /* Current total counters. */
  std::map<uint16_t,entity_metrics_t> total_ues;
};

class kpm_model : public service_model
{
public:

  typedef struct subscription_model_data {
    std::list<int> periods;
  } subscription_model_data_t;

  typedef struct report_period {
    int ms;
    int timer_id;
    metrics last_metrics;
#ifdef ENABLE_SLICER
    slice_metrics last_slice_metrics;
#endif
    std::list<ric::subscription_t *> subscriptions;
  } report_period_t;

  kpm_model(ric::agent *agent_);
  int init();
  void stop();
  virtual ~kpm_model() { stop(); };
  static void *timer_callback(int timer_id,void *arg);
  void send_indications(int timer_id);
  int handle_subscription_add(ric::subscription_t *sub);
  int handle_subscription_del(ric::subscription_t *sub,int force,
			      long *cause,long *cause_detail);
  void handle_control(ric::control_t *control);

private:
  pthread_mutex_t lock;
  std::list<ric::subscription_t *> subscriptions;
  report_period_t periods[NUM_PERIODS];
  long serial_number;
  timer_queue queue;
};

}
}

#endif
