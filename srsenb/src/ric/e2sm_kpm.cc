
#include "srsenb/hdr/ric/e2ap.h"
#include "srsenb/hdr/ric/e2sm.h"
#include "srsenb/hdr/ric/agent.h"
#include "srsenb/hdr/ric/agent_asn1.h"
#include "srsenb/hdr/ric/e2sm_kpm.h"
#include "srsenb/hdr/ric/e2ap_encode.h"

#include "E2AP_Cause.h"
#include "E2SM_KPM_E2SM-KPM-RANfunction-Description.h"
#include "E2SM_KPM_RIC-ReportStyle-List.h"
#include "E2SM_KPM_RIC-EventTriggerStyle-List.h"

namespace ric {

int kpm_model::init()
{
  ric::ran_function_t *func;
  E2SM_KPM_E2SM_KPM_RANfunction_Description_t *func_def;
  E2SM_KPM_RIC_ReportStyle_List_t *ric_report_style_item;
  E2SM_KPM_RIC_EventTriggerStyle_List_t *ric_event_trigger_style_item;

  /* Create and encode our function list. */
  func = (ric::ran_function_t *)calloc(1,sizeof(*func));
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
    agent->log.e2sm.error(
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

int kpm_model::handle_subscription_add(ric::subscription_t *sub)
{
  return 0;
}

int kpm_model::handle_subscription_del(
  ric::subscription_t *sub,int force,long *cause,long *cause_detail)
{
  return 0;
}

int kpm_model::handle_control(ric::control_t *control)
{
  return 0;
}

}
