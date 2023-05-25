
#include <sys/time.h>

#include "srslte/interfaces/enb_metrics_interface.h"
#include "srsenb/hdr/stack/rrc/rrc_metrics.h"
#include "srsenb/hdr/stack/upper/common_enb.h"
#include "srsenb/hdr/ric/e2ap.h"
#include "srsenb/hdr/ric/e2sm.h"
#include "srsenb/hdr/ric/agent.h"
#include "srsenb/hdr/ric/agent_asn1.h"
#include "srsenb/hdr/ric/e2sm_rc.h"
#include "srsenb/hdr/ric/e2ap_encode.h"
#include "srsenb/hdr/ric/e2ap_decode.h"
#include "srsenb/hdr/ric/e2ap_generate.h"

#include "E2AP_Cause.h"
#include "E2AP_RICactionType.h"
#include "E2AP_RICindicationType.h"

#include "E2SM_RC_E2SM-RC-IndicationHeader.h"
#include "E2SM_RC_E2SM-RC-IndicationMessage.h"
#include "E2SM_RC_RIC-Format-Type.h"
#include "E2SM_RC_E2SM-RC-RANFunctionDefinition.h"
#include "E2SM_RC_RANFunctionDefinition-EventTrigger.h"
#include "E2SM_RC_RANFunctionDefinition-EventTrigger-Style-Item.h"
#include "E2SM_RC_RANFunctionDefinition-Insert.h"
#include "E2SM_RC_RANFunctionDefinition-Insert-Item.h"
#include "E2SM_RC_RANFunctionDefinition-Control.h"
#include "E2SM_RC_RANFunctionDefinition-Control-Item.h"
#include "E2SM_RC_E2SM-RC-IndicationMessage-Format5.h"
#include "E2SM_RC_E2SM-RC-IndicationMessage-Format5-Item.h"
#include "E2SM_RC_RANParameter-ValueType-Choice-Structure.h"
#include "E2SM_RC_RANParameter-STRUCTURE.h"
#include "E2SM_RC_RANParameter-STRUCTURE-Item.h"
#include "E2SM_RC_EUTRA-CGI.h"
#include "E2SM_RC_E2SM-RC-ControlOutcome.h"
#include "E2SM_RC_E2SM-RC-ControlOutcome-Format1.h"
#include "E2SM_RC_E2SM-RC-ControlOutcome-Format1-Item.h"
#include "E2SM_RC_RANParameter-ID.h"
#include "E2SM_RC_RANParameter-Value.h"

namespace ric {

rc_model::rc_model(ric::agent *agent_) :
  service_model(agent_,"ORAN-E2SM-RC","1.3.6.1.4.1.53148.1.1.2.3"),
  serial_number(1), cpid(1), lock(PTHREAD_MUTEX_INITIALIZER)
{
}

int rc_model::init()
{
  ric::ran_function_t *func;
  E2SM_RC_E2SM_RC_RANFunctionDefinition_t *func_def;
  E2SM_RC_RANFunctionDefinition_EventTrigger_Style_Item_t *ric_event_trigger_style_item;
  E2SM_RC_RANFunctionDefinition_Insert_Item_t *ric_insert_style_item;
  E2SM_RC_RANFunctionDefinition_Control_Item_t *ric_control_style_item;
    
  E2SM_INFO(agent,"RAN Control: building function list\n");

  /* Create and encode our function list. */
  func = (ric::ran_function_t *)calloc(1,sizeof(*func));
  func->function_id = get_next_ran_function_id();
  func->model = this;
  func->revision = 0;
  func->name = "ORAN-E2SM-RC";
  func->description = "RAN Control";
  func->ran_func_oid = (uint8_t *)"1.3.6.1.4.1.53148.1.1.2.3";
  func->ran_func_oid_len = strlen((char *)func->ran_func_oid);

  func_def = (E2SM_RC_E2SM_RC_RANFunctionDefinition_t *) \
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
  
  // Optional RAN function instance
  long* function_instance = (long *) malloc(sizeof(long));
  *function_instance = 1;
  func_def->ranFunction_Name.ranFunction_Instance = function_instance;

  func_def->ranFunctionDefinition_EventTrigger = (E2SM_RC_RANFunctionDefinition_EventTrigger_t *)
    calloc(1, sizeof(E2SM_RC_RANFunctionDefinition_EventTrigger_t));
  ric_event_trigger_style_item = (E2SM_RC_RANFunctionDefinition_EventTrigger_Style_Item_t *)
    calloc(1, sizeof(*ric_event_trigger_style_item));
  ric_event_trigger_style_item->ric_EventTriggerStyle_Type = 2;
  ric_event_trigger_style_item->ric_EventTriggerStyle_Name.buf = (uint8 *)strdup("Call Process Breakpoint Trigger");
  ric_event_trigger_style_item->ric_EventTriggerStyle_Name.size = strlen("Call Process Breakpoint Trigger");
  ric_event_trigger_style_item->ric_EventTriggerFormat_Type = 2;
  ASN_SEQUENCE_ADD(&func_def->ranFunctionDefinition_EventTrigger->ric_EventTriggerStyle_List.list, ric_event_trigger_style_item);

  func_def->ranFunctionDefinition_Insert = (E2SM_RC_RANFunctionDefinition_Insert_t *)
    calloc(1, sizeof(E2SM_RC_RANFunctionDefinition_Insert_t));
  ric_insert_style_item = (E2SM_RC_RANFunctionDefinition_Insert_Item_t *)
    calloc(1, sizeof(*ric_insert_style_item));
  ric_insert_style_item->ric_InsertStyle_Type = 4;
  ric_insert_style_item->ric_InsertStyle_Name.buf = (uint8 *)strdup("Radio Access Control Request");
  ric_insert_style_item->ric_InsertStyle_Name.size = strlen("Radio Access Control Request");
  ric_insert_style_item->ric_SupportedEventTriggerStyle_Type = 2;
  ric_insert_style_item->ric_ActionDefinitionFormat_Type = 3;
  ric_insert_style_item->ric_IndicationHeaderFormat_Type = 2;
  ric_insert_style_item->ric_IndicationMessageFormat_Type = 5;
  ric_insert_style_item->ric_CallProcessIDFormat_Type = 1;
  ASN_SEQUENCE_ADD(&func_def->ranFunctionDefinition_Insert->ric_InsertStyle_List.list, ric_insert_style_item);

  func_def->ranFunctionDefinition_Control = (E2SM_RC_RANFunctionDefinition_Control_t *)
    calloc(1, sizeof(E2SM_RC_RANFunctionDefinition_Control_t));
  ric_control_style_item = (E2SM_RC_RANFunctionDefinition_Control_Item_t *)
    calloc(1, sizeof(*ric_control_style_item));
  ric_control_style_item->ric_ControlStyle_Type = 4;
  ric_control_style_item->ric_ControlStyle_Name.buf = (uint8 *)strdup("Radio Access Control");
  ric_control_style_item->ric_ControlStyle_Name.size = strlen("Radio Access Control");
  ric_control_style_item->ric_ControlHeaderFormat_Type = 1;
  ric_control_style_item->ric_ControlMessageFormat_Type = 1;
  ric_control_style_item->ric_CallProcessIDFormat_Type = (E2SM_RC_RIC_Format_Type_t *)
    calloc(1, sizeof(E2SM_RC_RIC_Format_Type_t));
  *ric_control_style_item->ric_CallProcessIDFormat_Type = 1;
  ASN_SEQUENCE_ADD(&func_def->ranFunctionDefinition_Control->ric_ControlStyle_List.list, ric_control_style_item);

  char error_buf[300] = {0, };
  size_t errlen = 0;
  int ret;
  ret = asn_check_constraints(&asn_DEF_E2SM_RC_E2SM_RC_RANFunctionDefinition, func_def, error_buf, &errlen);
    if(ret != 0) {
        E2SM_ERROR(agent, "E2SM-RC RANFunctionDefinition check constraints failed. error length = %lu, error buf = %s\n", errlen, error_buf);
  }

  func->enc_definition_len = ric::e2ap::encode(
    &asn_DEF_E2SM_RC_E2SM_RC_RANFunctionDefinition,0,
    func_def,&func->enc_definition);
  if (func->enc_definition_len < 0) {
    E2SM_ERROR(agent,
      "failed to encode %s function %s!\n",
      name.c_str(),func->name.c_str());
    ASN_STRUCT_FREE_CONTENTS_ONLY(
      asn_DEF_E2SM_RC_E2SM_RC_RANFunctionDefinition,func_def);
    free(func_def);
    free(func);

    return -1;
  }

  func->enabled = 1;
  func->definition = func_def;

  functions.push_back(func);

  queue.start();

  return 0;
}

void rc_model::stop()
{
  pthread_mutex_lock(&lock);
  queue.stop();
  for (auto it = subscriptions.begin(); it != subscriptions.end(); ++it) {
    ric::subscription_t *sub = *it;
    subscription_model_data *md = (subscription_model_data *)sub->model_data;
    delete md;
    sub->model_data = NULL;
  }
  subscriptions.clear();
  pthread_mutex_unlock(&lock);
}

int rc_model::handle_subscription_add(ric::subscription_t *sub)
{
  ric::action_t *action;
  bool any_actions_enabled = false;
  subscription_model_data *md;
  struct timeval tv;

  if (sub->event_trigger.size < 1 || sub->event_trigger.buf == NULL) {
    E2SM_ERROR(agent,"e2sm-rc: no report event trigger\n");
    return -1;
  }

  md = new subscription_model_data_t{};
  
  // XXX: approximate events by 2pps stream
  md->period = 2000;
  md->on_events = false;

  for (std::list<ric::action_t *>::iterator it = sub->actions.begin(); it != sub->actions.end(); ++it) {
    action = *it;
    if (action->type != E2AP_RICactionType_insert) {
	E2SM_WARN(agent,"e2sm-rc: invalid actionType %ld; not enabling this action\n",
		  action->type);
      continue;
    }
    action->enabled = true;
    any_actions_enabled = true;
  }
  if (!any_actions_enabled) {
    E2SM_ERROR(agent,"e2sm-rc: no actions enabled; failing subscription\n");
    goto errout;
  }

  /* This is a valid subscription; add it. */
  pthread_mutex_lock(&lock);
  subscriptions.push_back(sub);

  tv = { md->period / 1000, (md->period % 1000) * 1000 };
  md->timer_id = queue.insert_periodic(tv,timer_callback,this);
  sub->model_data = md;

  pthread_mutex_unlock(&lock);

  return 0;

 errout:
  pthread_mutex_unlock(&lock);
  delete md;

  return -1;
}

int rc_model::handle_subscription_del(
  ric::subscription_t *sub,int force,long *cause,long *cause_detail)
{
  subscription_model_data_t *md = (subscription_model_data_t *)sub->model_data;

  pthread_mutex_lock(&lock);

  queue.cancel(md->timer_id);
  delete md;
  sub->model_data = NULL;
  subscriptions.remove(sub);

  pthread_mutex_unlock(&lock);

  return 0;
}

void *rc_model::timer_callback(int timer_id,void *arg)
{
  rc_model *model = (rc_model *)arg;
  model->agent->push_task([model,timer_id]() { model->send_indications(timer_id); });
  return NULL;
}

void rc_model::send_indications(int timer_id)
{
  uint8_t *buf = NULL;
  ssize_t buf_len = 0;
  ric::subscription_t *sub;
  subscription_model_data_t *md;
  std::list<ric::action_t *>::iterator it2;
  ric::action_t *action;
  E2SM_RC_E2SM_RC_IndicationHeader_t ih;
  E2SM_RC_E2SM_RC_IndicationMessage_t im;
  E2SM_RC_E2SM_RC_IndicationMessage_Format5_t *im_format5;
  E2SM_RC_E2SM_RC_IndicationMessage_Format5_Item_t *im_format5_item;
  E2SM_RC_RANParameter_STRUCTURE_t *ran_param_struct, * ran_param_choice_struct, *ran_param_cell_struct;
  E2SM_RC_RANParameter_STRUCTURE_Item_t *ran_param_struct_item, *ran_param_choice_struct_item, *ran_param_cell_struct_item;
  E2SM_RC_RANParameter_ValueType_Choice_ElementFalse_t *element_false;
  E2SM_RC_EUTRA_CGI_t *eutra_cgi;
  uint8_t eutra_cgi_buffer[8192] = {0, };
  size_t eutra_cgi_buffer_size = 8192;
  asn_codec_ctx_t *opt_cod;
  asn_enc_rval_t er;
  OCTET_STRING_t *octet_string;
  uint8_t *header_buf = NULL;
  ssize_t header_buf_len = 0;
  uint8_t *msg_buf = NULL;
  ssize_t msg_buf_len = 0;
  OCTET_STRING *cpid_ostr;

  pthread_mutex_lock(&lock);

  for (auto it = subscriptions.begin(); it != subscriptions.end(); ++it) {
    sub = (ric::subscription_t *)*it;
    md = (subscription_model_data_t *)sub->model_data;
    if (timer_id == md->timer_id)
      break;
    sub = NULL;
    md = NULL;
  }
  if (sub == NULL) {
    E2SM_ERROR(agent,"e2sm-rc: bogus timer_id %d; ignoring!\n",timer_id);
    pthread_mutex_unlock(&lock);
    return;
  }

  E2SM_INFO(agent,"e2sm-rc: sending INSERT indications for period %ld ms\n",
	    md->period);

  /*
   * NB: we really need this to be action-specific, because actions can
   * request a particular report style, but since we currently only
   * generate one report style, don't worry for now.
   */
  memset(&ih,0,sizeof(ih));
  ih.ric_indicationHeader_formats.present = 
    E2SM_RC_E2SM_RC_IndicationHeader__ric_indicationHeader_formats_PR_indicationHeader_Format2;
  ih.ric_indicationHeader_formats.choice.indicationHeader_Format2.ric_InsertStyle_Type = 4;
  ih.ric_indicationHeader_formats.choice.indicationHeader_Format2.ric_InsertIndication_ID = 1;
  ih.ric_indicationHeader_formats.choice.indicationHeader_Format2.ueID.present = E2SM_RC_UEID_PR_eNB_UEID;
  E2SM_RC_UEID_ENB_t* ueid_enb = &ih.ric_indicationHeader_formats.choice.indicationHeader_Format2.ueID.choice.eNB_UEID;
  ueid_enb->mME_UE_S1AP_ID = 1; // dummy value -> uniquely identifies a UE over the S1 interface within a MME
  ueid_enb->gUMMEI.mME_Code.buf = (uint8_t *) calloc(1,sizeof(uint8_t));
  ueid_enb->gUMMEI.mME_Code.buf[0] = (uint8_t) 26; // MME Code at srsEPC -> 0x1A
  ueid_enb->gUMMEI.mME_Code.size = (uint8_t) 1;
  ueid_enb->gUMMEI.mME_Group_ID.buf = (uint8_t *) calloc(1,sizeof(uint8_t));
  ueid_enb->gUMMEI.mME_Group_ID.buf[0] = (uint8_t) 1; // MME Group ID at srsEPC -> 0x0001
  ueid_enb->gUMMEI.mME_Group_ID.size = (uint8_t) 2;
  ASN1_MAKE_PLMNID(agent->args.stack.s1ap.mcc,agent->args.stack.s1ap.mnc,
    &ueid_enb->gUMMEI.pLMN_Identity);

  E2SM_DEBUG(agent,"e2sm-rc indication header:\n");
  E2SM_XER_PRINT(NULL,&asn_DEF_E2SM_RC_E2SM_RC_IndicationHeader,&ih);

  header_buf_len = ric::e2ap::encode(
    &asn_DEF_E2SM_RC_E2SM_RC_IndicationHeader,0,&ih,&header_buf);
  if (header_buf_len < 0) {
    E2SM_ERROR(agent,"failed to encode e2sm-rc indication header; aborting send_indication\n");
    ASN_STRUCT_FREE_CONTENTS_ONLY(
      asn_DEF_E2SM_RC_E2SM_RC_IndicationHeader,&ih);
    goto out;
  }

  memset(&im,0,sizeof(im));
  im.ric_indicationMessage_formats.present =
    E2SM_RC_E2SM_RC_IndicationMessage__ric_indicationMessage_formats_PR_indicationMessage_Format5;
  
  im_format5 = (E2SM_RC_E2SM_RC_IndicationMessage_Format5_t *) calloc(1, sizeof(*im_format5));
  im.ric_indicationMessage_formats.choice.indicationMessage_Format5 = *im_format5;
  
  im_format5_item = (E2SM_RC_E2SM_RC_IndicationMessage_Format5_Item_t *) calloc(1, sizeof(*im_format5_item));
  ASN_SEQUENCE_ADD(&im_format5->ranP_Requested_List.list, im_format5_item);
  im_format5_item->ranParameter_ID = 1;
  im_format5_item->ranParameter_valueType.present = E2SM_RC_RANParameter_ValueType_PR_ranP_Choice_Structure;
  im_format5_item->ranParameter_valueType.choice.ranP_Choice_Structure =
    (E2SM_RC_RANParameter_ValueType_Choice_Structure_t *)
    calloc(1, sizeof(E2SM_RC_RANParameter_ValueType_Choice_Structure_t));
  
  ran_param_struct = (E2SM_RC_RANParameter_STRUCTURE_t *) calloc(1, sizeof(*ran_param_struct));
  im_format5_item->ranParameter_valueType.choice.ranP_Choice_Structure->ranParameter_Structure = ran_param_struct;
  ran_param_struct->sequence_of_ranParameters =
    (struct E2SM_RC_RANParameter_STRUCTURE::E2SM_RC_RANParameter_STRUCTURE__sequence_of_ranParameters *)
    calloc(1, sizeof(struct E2SM_RC_RANParameter_STRUCTURE::E2SM_RC_RANParameter_STRUCTURE__sequence_of_ranParameters));

  ran_param_struct_item = (E2SM_RC_RANParameter_STRUCTURE_Item_t *) calloc(1, sizeof(*ran_param_struct_item));
  ASN_SEQUENCE_ADD(&ran_param_struct->sequence_of_ranParameters->list, ran_param_struct_item);
  ran_param_struct_item->ranParameter_ID = 2;
  ran_param_struct_item->ranParameter_valueType =
    (E2SM_RC_RANParameter_ValueType_t *) calloc(1, sizeof(E2SM_RC_RANParameter_ValueType));
  ran_param_struct_item->ranParameter_valueType->present = E2SM_RC_RANParameter_ValueType_PR_ranP_Choice_Structure;
  ran_param_struct_item->ranParameter_valueType->choice.ranP_Choice_Structure =
    (E2SM_RC_RANParameter_ValueType_Choice_Structure_t *)
    calloc(1, sizeof(E2SM_RC_RANParameter_ValueType_Choice_Structure_t));
 
  ran_param_choice_struct = (E2SM_RC_RANParameter_STRUCTURE_t *) calloc(1, sizeof(*ran_param_choice_struct));
  ran_param_struct_item->ranParameter_valueType->choice.ranP_Choice_Structure->ranParameter_Structure =
    ran_param_choice_struct;
  ran_param_choice_struct->sequence_of_ranParameters =
     (struct E2SM_RC_RANParameter_STRUCTURE::E2SM_RC_RANParameter_STRUCTURE__sequence_of_ranParameters *)
    calloc(1, sizeof(struct E2SM_RC_RANParameter_STRUCTURE::E2SM_RC_RANParameter_STRUCTURE__sequence_of_ranParameters));

  ran_param_choice_struct_item = (E2SM_RC_RANParameter_STRUCTURE_Item_t *) calloc(1, sizeof(*ran_param_struct_item));
  ASN_SEQUENCE_ADD(&ran_param_choice_struct->sequence_of_ranParameters->list, ran_param_choice_struct_item);
  ran_param_choice_struct_item->ranParameter_ID = 5;
  ran_param_choice_struct_item->ranParameter_valueType =
    (E2SM_RC_RANParameter_ValueType_t *) calloc(1, sizeof(E2SM_RC_RANParameter_ValueType));
  ran_param_choice_struct_item->ranParameter_valueType->present = E2SM_RC_RANParameter_ValueType_PR_ranP_Choice_Structure;
  ran_param_choice_struct_item->ranParameter_valueType->choice.ranP_Choice_Structure =
    (E2SM_RC_RANParameter_ValueType_Choice_Structure_t *)
    calloc(1, sizeof(E2SM_RC_RANParameter_ValueType_Choice_Structure_t));

  ran_param_cell_struct = (E2SM_RC_RANParameter_STRUCTURE_t *) calloc(1, sizeof(*ran_param_choice_struct));
  ran_param_choice_struct_item->ranParameter_valueType->choice.ranP_Choice_Structure->ranParameter_Structure =
    ran_param_cell_struct; 
  ran_param_cell_struct->sequence_of_ranParameters =
    (struct E2SM_RC_RANParameter_STRUCTURE::E2SM_RC_RANParameter_STRUCTURE__sequence_of_ranParameters *)
    calloc(1, sizeof(struct E2SM_RC_RANParameter_STRUCTURE::E2SM_RC_RANParameter_STRUCTURE__sequence_of_ranParameters));
  
  ran_param_cell_struct_item = (E2SM_RC_RANParameter_STRUCTURE_Item_t *) calloc(1, sizeof(*ran_param_cell_struct_item));
  ran_param_cell_struct_item->ranParameter_ID = 6;
  ran_param_cell_struct_item->ranParameter_valueType = (E2SM_RC_RANParameter_ValueType_t *)
    calloc(1, sizeof(E2SM_RC_RANParameter_ValueType_t));
  ran_param_cell_struct_item->ranParameter_valueType->present = E2SM_RC_RANParameter_ValueType_PR_ranP_Choice_ElementFalse;
  element_false = &ran_param_cell_struct_item->ranParameter_valueType->choice.ranP_Choice_ElementFalse;
  element_false->ranParameter_value = (E2SM_RC_RANParameter_Value_t *) calloc(1, sizeof(E2SM_RC_RANParameter_Value_t));
  element_false->ranParameter_value->present = E2SM_RC_RANParameter_Value_PR_valueOctS;
  octet_string = &element_false->ranParameter_value->choice.valueOctS;

  eutra_cgi = (E2SM_RC_EUTRA_CGI_t *) calloc(1, sizeof(E2SM_RC_EUTRA_CGI_t));
  ASN1_MAKE_MACRO_ENB_ID(
    agent->args.stack.s1ap.enb_id,
    &eutra_cgi->eUTRACellIdentity);
  ASN1_MAKE_PLMNID(agent->args.stack.s1ap.mcc,agent->args.stack.s1ap.mnc,
    &eutra_cgi->pLMNIdentity);
  
  er = asn_encode_to_buffer(opt_cod, ATS_ALIGNED_BASIC_PER, &asn_DEF_E2SM_RC_EUTRA_CGI,eutra_cgi,
    eutra_cgi_buffer, eutra_cgi_buffer_size);
  OCTET_STRING_fromBuf(octet_string, (char *) eutra_cgi_buffer, er.encoded);


  E2SM_DEBUG(agent,"indication message:\n");
  E2SM_XER_PRINT(NULL,&asn_DEF_E2SM_RC_E2SM_RC_IndicationMessage,&im);

  msg_buf_len = ric::e2ap::encode(
    &asn_DEF_E2SM_RC_E2SM_RC_IndicationMessage,0,&im,&msg_buf);
  if (msg_buf_len < 0) {
    E2SM_ERROR(agent,"failed to encode e2sm-rc indication msg; aborting send_indication\n");
    ASN_STRUCT_FREE_CONTENTS_ONLY(
      asn_DEF_E2SM_RC_E2SM_RC_IndicationMessage,&im);
    goto out;
  }
  cpid_ostr = (OCTET_STRING_t *) calloc(1,sizeof(OCTET_STRING_t));
  cpid_ostr->buf = (uint8_t *) calloc(1, sizeof(cpid));
  cpid_ostr->size = sizeof(cpid);
  memcpy(cpid_ostr->buf, &cpid, sizeof(cpid));

  for (it2 = sub->actions.begin(); it2 != sub->actions.end(); ++it2) {
    action = *it2;

    if (ric::e2ap::generate_indication(
          agent,sub->request_id,sub->instance_id,sub->function_id,
	  action->id,serial_number++,(int)E2AP_RICindicationType_insert,
	  header_buf,header_buf_len,msg_buf,msg_buf_len,cpid_ostr->buf,cpid_ostr->size,&buf,&buf_len)) {
      E2SM_ERROR(
        agent,"e2sm-rc: failed to generate indication (reqid=%ld,instid=%ld,funcid=%ld,actid=%ld)\n",
	sub->request_id,sub->instance_id,sub->function_id,action->id);
    }
    else {
      E2SM_DEBUG(
	agent,"e2sm-rc: sending indication (reqid=%ld,instid=%ld,funcid=%ld,actid=%ld)\n",
	sub->request_id,sub->instance_id,sub->function_id,action->id);
      agent->send_sctp_data(buf,buf_len);
        clock_gettime(CLOCK_REALTIME, &sent_time);
        sent_ts_map[cpid] = elapsed_nanoseconds(sent_time);
    }
    free(buf);
    buf = NULL;
    buf_len = 0;
    ASN_STRUCT_FREE(asn_DEF_OCTET_STRING, cpid_ostr);
  }

 out:
  pthread_mutex_unlock(&lock);
  return;
}

void rc_model::handle_control(ric::control_t *rc)
{
  E2SM_RC_E2SM_RC_ControlOutcome_Format1_t *outcome_format;
  E2SM_RC_E2SM_RC_ControlOutcome_Format1_Item_t *outcome_item;
  long cause = 0;
  long cause_detail = 0;
  uint8_t *buf;
  ssize_t len;
  int ret;

  E2SM_DEBUG(agent,"e2sm-rc: handle_control\n");

  unsigned long recv_ns = elapsed_nanoseconds(*rc->recv_ts);
  // E2SM_DEBUG(agent,"Received timestamp is %lu ns", recv_ns);
  unsigned long sent_ns{};
  try{
    sent_ns = sent_ts_map.at(cpid);
    // E2SM_DEBUG(agent,"Sent timestamp is %lu ns", sent_ns);
  } catch(std::out_of_range&) {
    E2SM_ERROR(agent,"sent timestamp for message cpid=%u not found\n", cpid);
  }
  E2SM_DEBUG(agent,"Latency of message cpid=%u is %.3fms", cpid, (recv_ns-sent_ns)/1000000.0);
  sent_ts_map.erase(cpid);
  recv_ts_map.erase(cpid);
  cpid++;

  if (!rc->header_buf || rc->header_len < 1
      || !rc->message_buf || rc->message_len < 1) {
    E2SM_ERROR(agent,"e2sm-rc missing control header or message\n");
    cause = 1;
    cause_detail = 8;
    goto errout;
  }

  if (rc->request_ack == CONTROL_REQUEST_ACK) {
    E2SM_DEBUG(agent,
	       "Control Request ACK requested:\n");
    E2SM_RC_E2SM_RC_ControlOutcome_t outcome;
    memset(&outcome,0,sizeof(outcome));
    outcome.ric_controlOutcome_formats.present =
      E2SM_RC_E2SM_RC_ControlOutcome__ric_controlOutcome_formats_PR_controlOutcome_Format1;
    outcome_format = &outcome.ric_controlOutcome_formats.choice.controlOutcome_Format1;
    outcome_item = (E2SM_RC_E2SM_RC_ControlOutcome_Format1_Item_t *)
      calloc(1, sizeof(*outcome_item));
    outcome_item->ranParameter_ID = 1; // Received Timestamp
    outcome_item->ranParameter_value.present = 
      E2SM_RC_RANParameter_Value_PR_valueOctS;
    OCTET_STRING_t *ran_param_value = &outcome_item->ranParameter_value.choice.valueOctS;
    ran_param_value->buf = (uint8_t *) calloc(1, sizeof(uint8_t));
    ran_param_value->buf[0] = (uint8_t)2; // Dummy value now, encode 64-bit NTP timestamp
    ran_param_value->size = 8;
    ASN_SEQUENCE_ADD(&outcome_format->ranP_List.list,outcome_item);
    E2SM_XER_PRINT(NULL,&asn_DEF_E2SM_RC_E2SM_RC_ControlOutcome,&outcome);
    uint8_t *enc_outcome = NULL;
    ssize_t enc_outcome_len = ric::e2ap::encode(
      &asn_DEF_E2SM_RC_E2SM_RC_ControlOutcome,0,
      &outcome,&enc_outcome);
    if (enc_outcome_len < 0 || !enc_outcome) {
      E2SM_WARN(agent,
		"failed to encode e2sm-rc control outcome!\n");
    }
    ASN_STRUCT_FREE_CONTENTS_ONLY(
      asn_DEF_E2SM_RC_E2SM_RC_ControlOutcome,&outcome);
    ret = ric::e2ap::generate_ric_control_acknowledge(
      agent,rc,enc_outcome,enc_outcome_len,&buf,&len);
    if (enc_outcome)
      free(enc_outcome);
    if (ret) {
      E2AP_ERROR(agent,"failed to generate RICcontrolAcknowledge\n");
    }
    else {
      agent->send_sctp_data(buf,len);
    }
  }

  delete rc;
  return;

 errout:
  ret = ric::e2ap::generate_ric_control_failure(
    agent,rc,cause,cause_detail,NULL,0,&buf,&len);
  if (ret) {
    E2AP_ERROR(agent,"failed to generate RICcontrolFailure\n");
  }
  else {
    agent->send_sctp_data(buf,len);
  }
  delete rc;
  return;
}

}
