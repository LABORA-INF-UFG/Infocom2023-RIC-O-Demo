
#include "srsenb/hdr/ric/e2ap.h"
#include "srsenb/hdr/ric/e2sm.h"
#include "srsenb/hdr/ric/agent.h"
#include "srsenb/hdr/ric/agent_asn1.h"
#include "srsenb/hdr/ric/e2sm_kpm.h"
#include "srsenb/hdr/ric/e2ap_encode.h"
#include "srsenb/hdr/ric/e2ap_decode.h"
#include "srsenb/hdr/ric/e2ap_generate.h"

#include "E2AP_Cause.h"
#include "E2AP_RICactionType.h"
#include "E2AP_RICindicationType.h"
#include "E2SM_KPM_E2SM-KPM-RANfunction-Description.h"
#include "E2SM_KPM_RIC-ReportStyle-List.h"
#include "E2SM_KPM_RIC-EventTriggerStyle-List.h"
#include "E2SM_KPM_RT-Period-IE.h"
#include "E2SM_KPM_E2SM-KPM-EventTriggerDefinition.h"
#include "E2SM_KPM_Trigger-ConditionIE-Item.h"
#include "E2SM_KPM_E2SM-KPM-IndicationHeader.h"
#include "E2SM_KPM_E2SM-KPM-IndicationMessage.h"
#include "E2SM_KPM_PM-Containers-List.h"

namespace ric {

int kpm_model::init()
{
  ric::ran_function_t *func;
  E2SM_KPM_E2SM_KPM_RANfunction_Description_t *func_def;
  E2SM_KPM_RIC_ReportStyle_List_t *ric_report_style_item;
  E2SM_KPM_RIC_EventTriggerStyle_List_t *ric_event_trigger_style_item;

  E2SM_INFO(agent,"kpm: building function list\n");

  /* Create and encode our function list. */
  func = (ric::ran_function_t *)calloc(1,sizeof(*func));
  func->function_id = get_next_ran_function_id();
  func->model = this;
  func->revision = 0;
  func->name = "ORAN-E2SM-KPM";
  func->description = "KPM monitor";

  func_def = (E2SM_KPM_E2SM_KPM_RANfunction_Description_t *) \
    calloc(1,sizeof(*func_def));

  func_def->ranFunction_Name.ranFunction_ShortName.buf = \
    (uint8_t *)strdup(func->name.c_str());
  func_def->ranFunction_Name.ranFunction_ShortName.size = \
    strlen(func->name.c_str());
  func_def->ranFunction_Name.ranFunction_E2SM_OID.buf = \
    (uint8_t *)strdup(func->model->oid.c_str());
  func_def->ranFunction_Name.ranFunction_E2SM_OID.size = \
    strlen(func->model->oid.c_str());
  func_def->ranFunction_Name.ranFunction_Description.buf = \
    (uint8_t *)strdup(func->description.c_str());
  func_def->ranFunction_Name.ranFunction_Description.size = \
    strlen(func->description.c_str());
  func_def->e2SM_KPM_RANfunction_Item.ric_EventTriggerStyle_List = \
      (struct E2SM_KPM_E2SM_KPM_RANfunction_Description::E2SM_KPM_E2SM_KPM_RANfunction_Description__e2SM_KPM_RANfunction_Item::E2SM_KPM_E2SM_KPM_RANfunction_Description__e2SM_KPM_RANfunction_Item__ric_EventTriggerStyle_List *)calloc(1,sizeof(*func_def->e2SM_KPM_RANfunction_Item.ric_EventTriggerStyle_List));
  ric_event_trigger_style_item = (E2SM_KPM_RIC_EventTriggerStyle_List_t *)calloc(1,sizeof(*ric_event_trigger_style_item));
  ric_event_trigger_style_item->ric_EventTriggerStyle_Type = 1;
  ric_event_trigger_style_item->ric_EventTriggerStyle_Name.buf = (uint8_t *)strdup("Trigger1");
  ric_event_trigger_style_item->ric_EventTriggerStyle_Name.size = strlen("Trigger1");
  ric_event_trigger_style_item->ric_EventTriggerFormat_Type = 1;
  ASN_SEQUENCE_ADD(
    &func_def->e2SM_KPM_RANfunction_Item.ric_EventTriggerStyle_List->list,
    ric_event_trigger_style_item);

  func_def->e2SM_KPM_RANfunction_Item.ric_ReportStyle_List = \
      (struct E2SM_KPM_E2SM_KPM_RANfunction_Description::E2SM_KPM_E2SM_KPM_RANfunction_Description__e2SM_KPM_RANfunction_Item::E2SM_KPM_E2SM_KPM_RANfunction_Description__e2SM_KPM_RANfunction_Item__ric_ReportStyle_List *)calloc(1,sizeof(*func_def->e2SM_KPM_RANfunction_Item.ric_ReportStyle_List));
  ric_report_style_item = (E2SM_KPM_RIC_ReportStyle_List_t *)calloc(1,sizeof(*ric_report_style_item));
  ric_report_style_item->ric_ReportStyle_Type = 6;
  ric_report_style_item->ric_ReportStyle_Name.buf = (uint8_t *)strdup("O-CU-UP Measurement Container for the EPC connected deployment");
  ric_report_style_item->ric_ReportStyle_Name.size = strlen("O-CU-UP Measurement Container for the EPC connected deployment");
  ric_report_style_item->ric_IndicationHeaderFormat_Type = 1;
  ric_report_style_item->ric_IndicationMessageFormat_Type = 1;
  ASN_SEQUENCE_ADD(&func_def->e2SM_KPM_RANfunction_Item.ric_ReportStyle_List->list,
  		   ric_report_style_item);
  
  func->enc_definition_len = ric::e2ap::encode(
    &asn_DEF_E2SM_KPM_E2SM_KPM_RANfunction_Description,0,
    func_def,&func->enc_definition);
  if (func->enc_definition_len < 0) {
    E2SM_ERROR(agent,
      "failed to encode %s function %s!\n",
      name.c_str(),func->name.c_str());
    ASN_STRUCT_FREE_CONTENTS_ONLY(
      asn_DEF_E2SM_KPM_E2SM_KPM_RANfunction_Description,func_def);
    free(func_def);
    free(func);

    return -1;
  }

  func->enabled = 1;
  func->definition = func_def;

  functions.push_back(func);

  return 0;
}

int e2sm_kpm_period_ie_to_ms(E2SM_KPM_RT_Period_IE_t ie)
{
  switch(ie) {
  case E2SM_KPM_RT_Period_IE_ms10:
    return 10;
  case E2SM_KPM_RT_Period_IE_ms20:
    return 20;
  case E2SM_KPM_RT_Period_IE_ms32:
    return 32;
  case E2SM_KPM_RT_Period_IE_ms40:
    return 40;
  case E2SM_KPM_RT_Period_IE_ms60:
    return 60;
  case E2SM_KPM_RT_Period_IE_ms64:
    return 64;
  case E2SM_KPM_RT_Period_IE_ms70:
    return 70;
  case E2SM_KPM_RT_Period_IE_ms80:
    return 80;
  case E2SM_KPM_RT_Period_IE_ms128:
    return 128;
  case E2SM_KPM_RT_Period_IE_ms160:
    return 160;
  case E2SM_KPM_RT_Period_IE_ms256:
    return 256;
  case E2SM_KPM_RT_Period_IE_ms320:
    return 320;
  case E2SM_KPM_RT_Period_IE_ms512:
    return 512;
  case E2SM_KPM_RT_Period_IE_ms640:
    return 640;
  case E2SM_KPM_RT_Period_IE_ms1024:
    return 1024;
  case E2SM_KPM_RT_Period_IE_ms1280:
    return 1280;
  case E2SM_KPM_RT_Period_IE_ms2048:
    return 2048;
  case E2SM_KPM_RT_Period_IE_ms2560:
    return 2560;
  case E2SM_KPM_RT_Period_IE_ms5120:
    return 5120;
  case E2SM_KPM_RT_Period_IE_ms10240:
    return 10240;
  default:
    break;
  }

  return -1;
}

int kpm_model::handle_subscription_add(ric::subscription_t *sub)
{
  E2SM_KPM_E2SM_KPM_EventTriggerDefinition_t etdef;
  E2SM_KPM_Trigger_ConditionIE_Item *ie,**ptr;
  std::list<long> periods;
  int sub_period_ms;
  std::list<ric::action_t *>::iterator it;
  ric::action_t *action;
  bool any_actions_enabled = false;

  if (sub->event_trigger.size < 1 || sub->event_trigger.buf == NULL) {
    E2SM_ERROR(agent,"kpm: no report event trigger; no periods\n");
    return -1;
  }

  memset(&etdef,0,sizeof(etdef));
  if (ric::e2ap::decode(
	agent,&asn_DEF_E2SM_KPM_E2SM_KPM_EventTriggerDefinition,&etdef,
	sub->event_trigger.buf,sub->event_trigger.size)) {
    E2SM_ERROR(agent,"failed to decode e2sm kpm event trigger definition\n");
    goto errout;
  }
  if (etdef.present != E2SM_KPM_E2SM_KPM_EventTriggerDefinition_PR_eventDefinition_Format1) {
    E2SM_ERROR(agent,"kpm only supports eventDefinition_Format1\n");
    goto errout;
  }
  if (etdef.choice.eventDefinition_Format1.policyTest_List) {
    for (ptr = etdef.choice.eventDefinition_Format1.policyTest_List->list.array;
	 ptr < &etdef.choice.eventDefinition_Format1.policyTest_List->list.array[etdef.choice.eventDefinition_Format1.policyTest_List->list.count];
	 ptr++) {
      ie = (E2SM_KPM_Trigger_ConditionIE_Item *)*ptr;
      sub_period_ms = ric::e2sm_kpm_period_ie_to_ms(ie->report_Period_IE);
      if (sub_period_ms < -1) {
        E2SM_ERROR(agent,"kpm: invalid report period %d\n",sub_period_ms);
	goto errout;
      }
      periods.push_back(sub_period_ms);
    }
  }
  if (periods.empty()) {
    E2SM_ERROR(agent,"kpm: invalid report trigger; no periods\n");
    goto errout;
  }

  for (it = sub->actions.begin(); it != sub->actions.end(); ++it) {
    action = *it;
    if (action->type != E2AP_RICactionType_report) {
	E2SM_WARN(agent,"kpm: invalid actionType %ld; not enabling this action\n",
		  action->type);
      continue;
    }
    action->enabled = true;
    any_actions_enabled = true;
  }
  if (!any_actions_enabled) {
    E2SM_ERROR(agent,"kpm: no actions enabled; failing subscription\n");
    goto errout;
  }

  subscriptions.push_back(sub);

  if (period_ms < 0) {
    period_ms = 1000;
    callback = new ric::kpm_timeout_callback(this);
    timeout.start(period_ms,0,callback);
  }

  return 0;

 errout:
  ASN_STRUCT_FREE_CONTENTS_ONLY(
    asn_DEF_E2SM_KPM_E2SM_KPM_EventTriggerDefinition,(&etdef));

  return -1;
}

int kpm_model::handle_subscription_del(
  ric::subscription_t *sub,int force,long *cause,long *cause_detail)
{
  return 0;
}

int kpm_model::handle_control(ric::control_t *control)
{
  E2SM_ERROR(agent,"kpm: no controls supported\n");

  return -1;
}

void kpm_model::send_indication()
{
  uint8_t *buf = NULL;
  ssize_t buf_len = 0;
  std::list<ric::subscription_t *>::iterator it;
  ric::subscription_t *sub;
  std::list<ric::action_t *>::iterator it2;
  ric::action_t *action;
  E2SM_KPM_E2SM_KPM_IndicationHeader_t ih;
  E2SM_KPM_E2SM_KPM_IndicationMessage_t im;
  uint8_t *header_buf = NULL;
  ssize_t header_buf_len = 0;
  uint8_t *msg_buf = NULL;
  ssize_t msg_buf_len = 0;
  E2SM_KPM_PM_Containers_List_t *pmc_item;

  /* Schedule the next callback immediately. */
  timeout.start(period_ms,0,callback);

  E2SM_INFO(agent,"kpm: sending indications\n");

  /* First, we grab all the RF data. */
  long qci = 0;

  /*
   * Second, we generate the e2sm-specific stuff.
   *
   * NB: we really need this to be action-specific, because actions can
   * request a particular report style, but since we currently only
   * generate one report style, don't worry for now.
   */
  memset(&ih,0,sizeof(ih));
  ih.present = E2SM_KPM_E2SM_KPM_IndicationHeader_PR_indicationHeader_Format1;
  ih.choice.indicationHeader_Format1.pLMN_Identity = \
    (E2SM_KPM_PLMN_Identity_t *)calloc(1,sizeof(E2SM_KPM_PLMN_Identity_t));
  ASN1_MAKE_PLMNID(
    agent->args.stack.s1ap.mcc,agent->args.stack.s1ap.mnc,
    ih.choice.indicationHeader_Format1.pLMN_Identity);
  ih.choice.indicationHeader_Format1.qci = (long *)calloc(1,sizeof(long));
  memcpy(ih.choice.indicationHeader_Format1.qci,&qci,sizeof(qci));

  header_buf_len = ric::e2ap::encode(
    &asn_DEF_E2SM_KPM_E2SM_KPM_IndicationHeader,0,&ih,&header_buf);
  if (header_buf_len < 0) {
    E2SM_ERROR(agent,"failed to encode indication header; aborting send_indication\n");
    ASN_STRUCT_FREE_CONTENTS_ONLY(
      asn_DEF_E2SM_KPM_E2SM_KPM_IndicationHeader,&ih);
    goto out;
  }

  memset(&im,0,sizeof(im));
  im.ric_Style_Type = (long)4;
  im.indicationMessage.present = \
    E2SM_KPM_E2SM_KPM_IndicationMessage__indicationMessage_PR_indicationMessage_Format1;
  pmc_item = (E2SM_KPM_PM_Containers_List_t *)calloc(1,sizeof(*pmc_item));
  memset(pmc_item,0,sizeof(*pmc_item));
  ASN_SEQUENCE_ADD(
    &im.indicationMessage.choice.indicationMessage_Format1.pm_Containers.list,
    pmc_item);

  msg_buf_len = ric::e2ap::encode(
    &asn_DEF_E2SM_KPM_E2SM_KPM_IndicationMessage,0,&im,&msg_buf);
  if (msg_buf_len < 0) {
    E2SM_ERROR(agent,"failed to encode indication msg; aborting send_indication\n");
    ASN_STRUCT_FREE_CONTENTS_ONLY(
      asn_DEF_E2SM_KPM_E2SM_KPM_IndicationMessage,&im);
    goto out;
  }

  /*
   * Finally, for each subscription and its actions, generate and send
   * an indication.  We could only do this more efficiently if we did
   * all the PDU generation here, because the subscription and action
   * IDs are built into the RICindication message, so we have to
   * generate a new one for each.  This means we are less efficient due
   * to all the memcpys to create the IEs; and the memcpys into temp
   * buffers for the SM-specific octet strings.  Ah well.
   */
  for (it = subscriptions.begin(); it != subscriptions.end(); ++it) {
    sub = *it;
    for (it2 = sub->actions.begin(); it2 != sub->actions.end(); ++it2) {
      action = *it2;

      if (ric::e2ap::generate_indication(
	    agent,sub->request_id,sub->instance_id,sub->function_id,
	    action->id,serial_number++,(int)E2AP_RICindicationType_report,
	    header_buf,header_buf_len,msg_buf,msg_buf_len,NULL,0,&buf,&buf_len)) {
	E2SM_ERROR(
	  agent,"kpm: failed to generate indication (reqid=%ld,instid=%ld,funcid=%ld,actid=%ld)\n",
	  sub->request_id,sub->instance_id,sub->function_id,action->id);
      }
      else {
	E2SM_DEBUG(
	  agent,"kpm: sending indication (reqid=%ld,instid=%ld,funcid=%ld,actid=%ld)\n",
	  sub->request_id,sub->instance_id,sub->function_id,action->id);
	agent->send_sctp_data(buf,buf_len);
      }
      free(buf);
      buf = NULL;
      buf_len = 0;
    }
  }

 out:
  return;
}

}
