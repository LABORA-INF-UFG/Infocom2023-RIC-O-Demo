#ifndef RIC_E2SM_KPM_H
#define RIC_E2SM_KPM_H

#include "srsenb/hdr/ric/e2ap.h"
#include "srsenb/hdr/ric/e2sm.h"

namespace ric {

class kpm_model : public service_model
{
public:
  kpm_model(ric::agent *agent_): service_model(agent) {};
  int init();
  virtual ~kpm_model() {};

  const std::string name = "ORAN-E2SM-KPM";
  const std::string oid = "1.3.6.1.4.1.1.1.2.2";

private:
  int handle_subscription_add(ric::subscription_t *sub);
  int handle_subscription_del(ric::subscription_t *sub,int force,
			      long *cause,long *cause_detail);
  int handle_control(ric::control_t *control);
  
  ric::agent *agent;
};

}

#endif
