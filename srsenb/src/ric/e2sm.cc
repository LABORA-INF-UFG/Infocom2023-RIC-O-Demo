#include "srslte/common/common.h"

#include <srsenb/hdr/ric/e2sm.h>

namespace ric
{

ran_function_id_t next_ran_function_id = 0;

ran_function_id_t get_next_ran_function_id()
{
  return next_ran_function_id++;
}

int service_model::init()
{
  return SRSLTE_ERROR;
}

service_model::~service_model()
{
}

int service_model::handle_subscription_add(ric::subscription_t *sub)
{
  return SRSLTE_ERROR;
}

int service_model::handle_subscription_del(
  ric::subscription_t *sub,int force,long *cause,long *cause_detail)
{
  return SRSLTE_ERROR;
}

void service_model::handle_control(ric::control_t *control)
{
}

}
