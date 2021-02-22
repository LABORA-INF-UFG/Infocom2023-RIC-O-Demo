
#include <sys/time.h>

#include "srslte/interfaces/enb_metrics_interface.h"
#include "srsenb/hdr/stack/rrc/rrc_metrics.h"
#include "srsenb/hdr/stack/upper/common_enb.h"
#include "srsenb/hdr/ric/e2ap.h"
#include "srsenb/hdr/ric/e2sm.h"
#include "srsenb/hdr/ric/agent.h"
#include "srsenb/hdr/ric/agent_asn1.h"
#include "srsenb/hdr/ric/e2sm_nexran.h"
#include "srsenb/hdr/ric/e2ap_encode.h"
#include "srsenb/hdr/ric/e2ap_decode.h"
#include "srsenb/hdr/ric/e2ap_generate.h"

#include "E2AP_Cause.h"
#include "E2AP_RICactionType.h"
#include "E2AP_RICindicationType.h"
#include "E2AP_RICcontrolStatus.h"
#include "E2SM_NEXRAN_RANfunction-Description.h"
#include "E2SM_NEXRAN_E2SM-NexRAN-ControlHeader.h"
#include "E2SM_NEXRAN_E2SM-NexRAN-ControlMessage.h"
#include "E2SM_NEXRAN_SliceConfig.h"

namespace ric {

nexran_model::nexran_model(ric::agent *agent_) :
  service_model(agent_,"ORAN-E2SM-NEXRAN","1.3.6.1.4.1.1.1.2.100"),
  serial_number(1), lock(PTHREAD_MUTEX_INITIALIZER)
{
}

int nexran_model::init()
{
  ric::ran_function_t *func;
  E2SM_NEXRAN_RANfunction_Description_t *func_def;

  E2SM_INFO(agent,"nexran: building function list\n");

  /* Create and encode our function list. */
  func = (ric::ran_function_t *)calloc(1,sizeof(*func));
  func->function_id = get_next_ran_function_id();
  func->model = this;
  func->revision = 0;
  func->name = "ORAN-E2SM-NEXRAN";
  func->description = "NexRAN API";

  func_def = (E2SM_NEXRAN_RANfunction_Description_t *) \
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

  func->enc_definition_len = ric::e2ap::encode(
    &asn_DEF_E2SM_NEXRAN_RANfunction_Description,0,
    func_def,&func->enc_definition);
  if (func->enc_definition_len < 0) {
    E2SM_ERROR(agent,
      "failed to encode %s function %s!\n",
      name.c_str(),func->name.c_str());
    ASN_STRUCT_FREE_CONTENTS_ONLY(
      asn_DEF_E2SM_NEXRAN_RANfunction_Description,func_def);
    free(func_def);
    free(func);

    return -1;
  }

  func->enabled = 1;
  func->definition = func_def;

  functions.push_back(func);

  return 0;
}

void nexran_model::stop()
{
}

int nexran_model::handle_subscription_add(ric::subscription_t *sub)
{
  E2SM_ERROR(agent,"nexran: no controls supported\n");

  return -1;
}

int nexran_model::handle_subscription_del(
  ric::subscription_t *sub,int force,long *cause,long *cause_detail)
{
  E2SM_ERROR(agent,"nexran: no controls supported\n");

  return -1;
}

void nexran_model::handle_control(ric::control_t *rc)
{
  E2SM_NEXRAN_E2SM_NexRAN_ControlHeader_t ch;
  E2SM_NEXRAN_E2SM_NexRAN_ControlMessage_t cm;
  long cause = 0;
  long cause_detail = 0;
  uint8_t *buf;
  ssize_t len;
  int ret;

  E2SM_DEBUG(agent,"nexran: handle_control\n");

  if (!rc->header_buf || rc->header_len < 1
      || !rc->message_buf || rc->message_len < 1) {
    E2SM_ERROR(agent,"e2sm nexran missing control header or message\n");
    cause = 1;
    cause = 8;
    goto errout;
  }

  memset(&ch,0,sizeof(ch));
  if (ric::e2ap::decode(
	agent,&asn_DEF_E2SM_NEXRAN_E2SM_NexRAN_ControlHeader,&ch,
	rc->header_buf,rc->header_len)) {
    E2SM_ERROR(agent,"failed to decode e2sm nexran control header\n");
    cause = 1;
    cause_detail = 8;
    goto errout;
  }
  if (ch.present != E2SM_NEXRAN_E2SM_NexRAN_ControlHeader_PR_controlHeaderFormat1) {
    E2SM_ERROR(agent,"nexran only supports control header Format1\n");
    cause = 1;
    cause_detail = 8;
    goto errout;
  }

  E2SM_DEBUG(agent,"control header:\n");
  E2SM_XER_PRINT(NULL,&asn_DEF_E2SM_NEXRAN_E2SM_NexRAN_ControlHeader,&ch);

  memset(&cm,0,sizeof(cm));
  if (ric::e2ap::decode(
	agent,&asn_DEF_E2SM_NEXRAN_E2SM_NexRAN_ControlMessage,&cm,
	rc->message_buf,rc->message_len)) {
    E2SM_ERROR(agent,"failed to decode e2sm nexran control message\n");
    cause = 1;
    cause_detail = 8;
    goto errout;
  }
  if (cm.present != E2SM_NEXRAN_E2SM_NexRAN_ControlMessage_PR_controlMessageFormat1) {
    E2SM_ERROR(agent,"nexran only supports control message Format1\n");
    cause = 1;
    cause_detail = 8;
    goto errout;
  }
  if (cm.choice.controlMessageFormat1.present < E2SM_NEXRAN_E2SM_NexRAN_ControlMessage_Format1_PR_sliceConfigRequest
      || cm.choice.controlMessageFormat1.present > E2SM_NEXRAN_E2SM_NexRAN_ControlMessage_Format1_PR_sliceUeUnbindRequest) {
    E2SM_ERROR(agent,"unknown nexran control message\n");
    cause = 1;
    cause_detail = 8;
    goto errout;
  }

  E2SM_DEBUG(agent,"control message:\n");
  E2SM_XER_PRINT(NULL,&asn_DEF_E2SM_NEXRAN_E2SM_NexRAN_ControlMessage,&cm);

  ret = 0;
  switch (cm.choice.controlMessageFormat1.present) {
  case E2SM_NEXRAN_E2SM_NexRAN_ControlMessage_Format1_PR_sliceConfigRequest:
    {
      E2SM_NEXRAN_SliceConfigRequest_t *req = \
	  &cm.choice.controlMessageFormat1.choice.sliceConfigRequest;
      std::vector<slicer::slice_config_t> slice_configs;
      for (int i = 0; i < req->sliceConfigList.list.count; ++i) {
        E2SM_NEXRAN_SliceConfig_t *sc = (E2SM_NEXRAN_SliceConfig_t *) \
	    req->sliceConfigList.list.array[i];
	std::string slice_name((char *)sc->sliceName.buf,
			       sc->sliceName.size);
	long share = sc->schedPolicy.choice.proportionalAllocationPolicy.share;
	slices[slice_name] = new slicer::slice_config_t {
	    slice_name, { (uint32_t)share } };
	slice_configs.push_back(*slices[slice_name]);
	if (!ues.count(slice_name)) {
	    ues[slice_name] = std::list<std::string>();
	}
	E2SM_DEBUG(agent,"configured slice %s share %u\n",
		   slice_name.c_str(),(uint32_t)share);
      }
      agent->enb_slicer_interface->slice_config(slice_configs);
      ret = 0;
    }
    break;
  case E2SM_NEXRAN_E2SM_NexRAN_ControlMessage_Format1_PR_sliceDeleteRequest:
    {
      E2SM_NEXRAN_SliceDeleteRequest_t *req = \
	  &cm.choice.controlMessageFormat1.choice.sliceDeleteRequest;
      // We need to delete all or none, so check for existence first.
      std::vector<std::string> deletes;
      for (int i = 0; i < req->sliceNameList.list.count; ++i) {
        E2SM_NEXRAN_SliceName_t *sn = (E2SM_NEXRAN_SliceName_t *) \
	    req->sliceNameList.list.array[i];
	std::string slice_name((char *)sn->buf,sn->size);
	deletes.push_back(slice_name);
	if (!slices.count(slice_name)) {
	  ret = 1;
	  break;
	}
      }
      if (ret)
	  break;
      for (auto it = deletes.begin(); it != deletes.end(); ++it) {
	  slices.erase(*it);
	  ues.erase(*it);
	  E2SM_DEBUG(agent,"deleted slice %s\n",it->c_str());
      }
      agent->enb_slicer_interface->slice_delete(deletes);
      ret = 0;
    }
    break;
  case E2SM_NEXRAN_E2SM_NexRAN_ControlMessage_Format1_PR_sliceStatusRequest:
      ret = 1;
      break;
  case E2SM_NEXRAN_E2SM_NexRAN_ControlMessage_Format1_PR_sliceUeBindRequest:
    {
      E2SM_NEXRAN_SliceUeBindRequest_t *req = \
	  &cm.choice.controlMessageFormat1.choice.sliceUeBindRequest;
      std::string slice_name((char *)req->sliceName.buf,req->sliceName.size);
      if (!slices.count(slice_name)) {
	  ret = 1;
	  break;
      }
      std::vector<std::string> binds;
      std::vector<uint64_t> imsi_uints;
      for (int i = 0; i < req->imsiList.list.count; ++i) {
        E2SM_NEXRAN_IMSI_t *imsi = (E2SM_NEXRAN_IMSI_t *) \
	    req->imsiList.list.array[i];
	std::string imsi_str((char *)imsi->buf,imsi->size);
	if (std::find(ues[slice_name].begin(),ues[slice_name].end(),imsi_str) != ues[slice_name].end()) {
	    ret = 1;
	    break;
	}
	binds.push_back(imsi_str);
	imsi_uints.push_back(std::stoul(imsi_str));
      }
      if (ret)
	  break;
      for (auto it = binds.begin(); it != binds.end(); ++it) {
	  ues[slice_name].push_back(*it);
	  E2SM_DEBUG(agent,"bound slice %s to IMSI %s\n",
		     slice_name.c_str(),it->c_str());
      }
      agent->enb_slicer_interface->slice_ue_bind(slice_name,imsi_uints);
      ret = 0;
    }
    break;
  case E2SM_NEXRAN_E2SM_NexRAN_ControlMessage_Format1_PR_sliceUeUnbindRequest:
    {
      E2SM_NEXRAN_SliceUeUnbindRequest_t *req = \
	  &cm.choice.controlMessageFormat1.choice.sliceUeUnbindRequest;
      std::string slice_name((char *)req->sliceName.buf,req->sliceName.size);
      if (!slices.count(slice_name)) {
	  ret = 1;
	  break;
      }
      std::vector<std::string> unbinds;
      std::vector<uint64_t> imsi_uints;
      for (int i = 0; i < req->imsiList.list.count; ++i) {
        E2SM_NEXRAN_IMSI_t *imsi = (E2SM_NEXRAN_IMSI_t *) \
	    req->imsiList.list.array[i];
	std::string imsi_str((char *)imsi->buf,imsi->size);
	if (std::find(ues[slice_name].begin(),ues[slice_name].end(),imsi_str) == ues[slice_name].end()) {
	    ret = 1;
	    break;
	}
	unbinds.push_back(imsi_str);
	imsi_uints.push_back(std::stoul(imsi_str));
      }
      if (ret)
	  break;

      ues[slice_name].erase(ues[slice_name].begin());
      for (auto it = ues[slice_name].begin(); it != ues[slice_name].end(); ++it) {
	  if (std::find(unbinds.begin(),unbinds.end(),*it) != unbinds.end()) {
	      ues[slice_name].erase(it);
	      E2SM_DEBUG(agent,"unbound slice %s from IMSI %s\n",
			 slice_name.c_str(),it->c_str());
	  }
      }
      agent->enb_slicer_interface->slice_ue_unbind(slice_name,imsi_uints);
      ret = 0;
    }
    break;
  default:
    E2SM_ERROR(agent,"unknown nexran control message\n");
    ret = 1;
    cause = 1;
    cause_detail = 8;
  }

  if (ret) {
    E2SM_ERROR(agent,"error while handling nexran control request (%d)\n",ret);
    cause = 1;
    cause_detail = 8;
    goto errout;
  }

  if (rc->request_ack == CONTROL_REQUEST_ACK) {
    ret = ric::e2ap::generate_ric_control_acknowledge(
      agent,rc,E2AP_RICcontrolStatus_success,NULL,0,&buf,&len);
    if (ret) {
      E2AP_ERROR(agent,"failed to generate RICcontrolFailure\n");
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
