#include <list>

#include "srslte/common/common.h"
#include "srslte/common/logger.h"
#include "srslte/common/log_filter.h"
#include "srslte/common/logmap.h"
#include "srslte/common/network_utils.h"

#include <sys/socket.h>
#include <netinet/sctp.h>

#include "srsenb/hdr/enb.h"
#include "srsenb/hdr/ric/agent_defs.h"
#include "srsenb/hdr/ric/agent.h"
#include "srsenb/hdr/ric/agent_asn1.h"
#include "srsenb/hdr/ric/e2ap.h"
#include "srsenb/hdr/ric/e2ap_handle.h"
#include "srsenb/hdr/ric/e2ap_encode.h"
#include "srsenb/hdr/ric/e2ap_generate.h"
#include "srsenb/hdr/ric/e2sm.h"
#include "srsenb/hdr/ric/e2sm_gnb_nrt.h"
#ifdef ENABLE_RIC_AGENT_KPM
#include "srsenb/hdr/ric/e2sm_kpm.h"
#endif
#ifdef ENABLE_SLICER
#include "srsenb/hdr/ric/e2sm_nexran.h"
#endif
#ifdef ENABLE_SLICER
#include "srsenb/hdr/stack/mac/slicer_test_utils.h"
#endif
#ifdef ENABLE_RIC_AGENT_RC
#include "srsenb/hdr/ric/e2sm_rc.h"
#endif

namespace ric {

bool e2ap_xer_print;
bool e2sm_xer_print;

agent::agent(srslte::logger* logger_,
	     srsenb::enb_metrics_interface *enb_metrics_interface_
#ifdef ENABLE_SLICER
	     ,
	     srsenb::enb_slicer_interface *enb_slicer_interface_
#endif
  )
  : logger(logger_),
    enb_metrics_interface(enb_metrics_interface_),
#ifdef ENABLE_SLICER
    enb_slicer_interface(enb_slicer_interface_),
#endif
    thread("RIC")
{
  agent_queue_id = pending_tasks.add_queue();
};

agent::~agent()
{
  stop();
}

int agent::init(const srsenb::all_args_t& args_,
	   srsenb::phy_cfg_t& phy_cfg_,
	   srsenb::rrc_cfg_t rrc_cfg_)
{
  service_model *model;
  std::list<ric::service_model *>::iterator it;
  std::list<ric::ran_function_t *>::iterator it2;
  ric::ran_function_t *func;
  std::string ric_level_copy;

  args = args_;
  phy_cfg = phy_cfg_;
  rrc_cfg = rrc_cfg_;

  ric_level_copy = std::string(args.ric_agent.log_level);
  log.ric_level = log.e2ap_level = log.e2sm_level = \
    srslte::log::get_level_from_string(std::move(ric_level_copy));
  log.ric.init("RIC",logger);
  log.ric.set_level(log.ric_level);
  log.ric.set_hex_limit(args.ric_agent.log_hex_limit);
  RIC_DEBUG("log_level = %s\n",args.ric_agent.log_level.c_str());

  log.e2ap.init("E2AP",logger);
  log.e2ap.set_level(log.e2ap_level);
  log.e2ap.set_hex_limit(args.ric_agent.log_hex_limit);
  e2ap_xer_print = (log.ric_level >= srslte::LOG_LEVEL_DEBUG);

  log.e2sm.init("E2SM",logger);
  log.e2sm.set_level(log.e2sm_level);
  log.e2sm.set_hex_limit(args.ric_agent.log_hex_limit);
  e2sm_xer_print = (log.e2sm_level >= srslte::LOG_LEVEL_DEBUG);

  if (args.ric_agent.disabled) {
    set_state(RIC_DISABLED);
    return SRSLTE_SUCCESS;
  }

  /* Handle disabled functions. */
  if (!args.ric_agent.functions_disabled.empty()) {
    int i = 0,spos = -1,sslen = 0;
    int len = (int)args.ric_agent.functions_disabled.size();
    for (int i = 0; i < len ; ++i) {
      if (spos < 0
	  && (args.ric_agent.functions_disabled[i] == ','
	      || args.ric_agent.functions_disabled[i] == ' '
	      || args.ric_agent.functions_disabled[i] == '\t'))
	continue;
      else if (spos < 0) {
	spos = i;
	continue;
      }
      if (args.ric_agent.functions_disabled[i] == ',' || (i + 1) == len) {
	sslen = i - spos;
	if ((i + 1) == len && !(args.ric_agent.functions_disabled[i] == ','))
	  ++sslen;
	std::string ds = \
	  args.ric_agent.functions_disabled.substr(spos,sslen);
	functions_disabled.push_back(ds);
	RIC_DEBUG("disabled function: %s\n",ds.c_str());
	spos = -1;
      }
    }
  }

  /* Add E2SM service models. */
#ifdef ENABLE_RIC_AGENT_KPM
  model = new kpm_model(this);
  if (model->init()) {
    RIC_ERROR("failed to add E2SM-KPM model; aborting!\n");
    delete model;
    return SRSLTE_ERROR;
  }
  service_models.push_back(model);
  RIC_INFO("added model %s\n",model->name.c_str());
#endif

#ifdef ENABLE_SLICER
  model = new nexran_model(this);
  if (model->init()) {
    RIC_ERROR("failed to add E2SM-NEXRAN model; aborting!\n");
    delete model;
    return SRSLTE_ERROR;
  }
  service_models.push_back(model);
  RIC_INFO("added model %s\n",model->name.c_str());
#endif

#ifdef ENABLE_RIC_AGENT_RC
  model = new rc_model(this);
  if (model->init()) {
    RIC_ERROR("failed to add E2SM-RC model; aborting!\n");
    delete model;
    return SRSLTE_ERROR;
  }
  service_models.push_back(model);
  RIC_INFO("added model %s\n",model->name.c_str());
#endif

  model = new gnb_nrt_model(this);
  if (model->init()) {
    RIC_ERROR("failed to add E2SM-gNB-NRT model; aborting!\n");
    delete model;
    return SRSLTE_ERROR;
  }
  service_models.push_back(model);
  RIC_INFO("added model %s\n",model->name.c_str());

  /* Construct a simple function_id->function lookup table. */
  for (it = service_models.begin(); it != service_models.end(); ++it) {
    for (it2 = (*it)->functions.begin(); it2 != (*it)->functions.end(); ++it2) {
      func = *it2;
      if (!(func->enabled)) {
	RIC_DEBUG("model %s function %s not enabled; not registering\n",
		  (*it)->name.c_str(),func->name.c_str());
	continue;
      }
      if (!is_function_enabled(func->name)) {
	RIC_DEBUG("model %s function %s administratively disabled; not registering\n",
		  (*it)->name.c_str(),func->name.c_str());
	func->enabled = false;
        continue;
      }
      function_id_map.insert(std::make_pair(func->function_id,func));
      RIC_DEBUG("model %s function %s (function_id %ld) enabled and registered\n",
		(*it)->name.c_str(),func->name.c_str(),func->function_id);

    }
  }

  set_state(RIC_INITIALIZED);

  /* Start up our recv socket thread and agent thread. */
  rx_sockets.reset(new srslte::rx_multisocket_handler("RICSOCKET",
						      srslte::logmap::get("RIC")));

  /* Enqueue a connect task for our thread.  This will run due to start() below. */
  pending_tasks.push(agent_queue_id,[this]() { connect(); });

  /* Use the default high-priority level, below UDH, same as enb. */
  agent_thread_started = true;
  start(-1);

  return SRSLTE_SUCCESS;
}

#ifdef ENABLE_SLICER
void agent::test_slicer_interface()
{
  srslte::console("[agent] testing slicer interface...\n");
  std::vector<std::string> slice_names;

  srslte::console("[agent] configuring slices...\n");
  std::vector<slicer::slice_config_t> s_configs;
  for (auto it = slicer_test::slices.begin(); it != slicer_test::slices.end(); ++it) {
    slicer_test::print_slice(*it);
    s_configs.push_back(it->config);
  }
  enb_slicer_interface->slice_config(s_configs);

  srslte::console("[agent] checking all single slice status'...\n");
  std::vector<slicer::slice_status_t> s_status = enb_slicer_interface->slice_status({});
  for (auto it = s_status.begin(); it != s_status.end(); ++it) {
    slicer_test::print_slice_status(*it);
  }

  auto slice_name = slicer_test::slices[0].config.name;
  srslte::console("[agent] checking slice status for slice %s...\n", slice_name.c_str());
  s_status = enb_slicer_interface->slice_status({slice_name});
  for (auto it = s_status.begin(); it != s_status.end(); ++it) {
    slicer_test::print_slice_status(*it);
  }

  for (auto it = slicer_test::slices.begin(); it != slicer_test::slices.end(); ++it) {
    srslte::console("[agent] binding UEs for slice %s...\n", it->config.name.c_str());
    enb_slicer_interface->slice_ue_bind(it->config.name, it->imsi_list);
  }

  srslte::console("[agent] checking all slice status' after binding UEs...\n");
  s_status = enb_slicer_interface->slice_status({});
  for (auto it = s_status.begin(); it != s_status.end(); ++it) {
    slicer_test::print_slice_status(*it);
  }

  for (auto it = slicer_test::imsis_to_unbind.begin(); it != slicer_test::imsis_to_unbind.end(); ++it) {
    srslte::console("[agent] unbinding these UEs for slice %s ", it->name.c_str());
    slicer_test::print_imsis(it->imsi_list);
    enb_slicer_interface->slice_ue_unbind(it->name, it->imsi_list);
  }

  srslte::console("[agent] checking all slice status' after unbinding UEs...\n");
  s_status = enb_slicer_interface->slice_status({});
  for (auto it = s_status.begin(); it != s_status.end(); ++it) {
    slicer_test::print_slice_status(*it);
  }

  srslte::console("[agent] deleting slices ");
  for (auto it = slicer_test::slices_to_delete.begin(); it != slicer_test::slices_to_delete.end(); ++it) {
    srslte::console("%s ", (*it).c_str());
  }
  srslte::console("\n");
  enb_slicer_interface->slice_delete(slicer_test::slices_to_delete);

  srslte::console("[agent] checking all slice status' after unbinding UEs...\n");
  s_status = enb_slicer_interface->slice_status({});
  for (auto it = s_status.begin(); it != s_status.end(); ++it) {
    slicer_test::print_slice_status(*it);
  }
}
#endif

void agent::run_thread()
{
  while (agent_thread_started) {
    srslte::move_task_t task{};
    if (pending_tasks.wait_pop(&task) >= 0)
      task();
  }
  RIC_INFO("exiting agent thread\n");
}

bool agent::is_function_enabled(std::string &function_name)
{
  std::list<std::string>::iterator it; 

  for (it = functions_disabled.begin(); it != functions_disabled.end(); ++it) {
    if (function_name.compare(*it) == 0)
      return false;
  }

  return true;
}

void agent::set_ric_id(uint32_t id,uint16_t mcc,uint16_t mnc)
{
  ric_id = id;
  ric_mcc = mcc;
  ric_mnc = mnc;
}

ric::ran_function_t *agent::lookup_ran_function(
  ran_function_id_t function_id)
{
  if (function_id_map.find(function_id) == function_id_map.end())
    return nullptr;
  else
    return function_id_map[function_id];
}

ric::subscription_t *agent::lookup_subscription(
  long request_id,long instance_id,ric::ran_function_id_t function_id)
{
  ric::subscription_t *sub;
  std::list<ric::subscription_t *>::iterator it; 

  for (it = subscriptions.begin(); it != subscriptions.end(); ++it) {
    sub = *it;
    if (sub->request_id == request_id
	&& sub->instance_id == instance_id
	&& sub->function_id == function_id)
      return sub;
  }

  return nullptr;
}

/**
 * Handle an error or closure of the RIC socket connection.  The goal
 * here was to allow users to specify that the agent shouldn't always,
 * infinitely attempt to reconnect, and should actually stop both its rx
 * and agent threads here, but that isn't supported by srsenb.
 *
 * (We cannot call stop() from within our rx thread nor our agent
 * thread: if the former, we deadlock on cleanup within the rx thread;
 * if the latter, we try to pthread_join ourself from ourself, after
 * adding a stop_impl task for ourself :).  What we need to implement
 * this is help from the enb stack itself (e.g. a daemon thread that
 * just waits for component threads to exit and joins them), but it
 * doesn't have any support to do this, presumably because none of its
 * radio threads would ever exit without taking the whole enb with it;
 * and because none of the upper layers should ever not reconnect.  So
 * we just stop reconnection attempts, and let our threads sleep forever
 * (until the enb main actually does stop them at enb termination).)
 */
void agent::handle_connection_error()
{
  if (args.ric_agent.no_reconnect) {
    RIC_INFO("disabling further RIC reconnects\n");
    /* stop(); */
    set_state(RIC_DISABLED);
    pending_tasks.push(agent_queue_id,[this]() {
      disconnect();
    });
  }
  else {
    RIC_INFO("resetting agent connection (reconnect enabled)\n");
    RIC_INFO("pushing connection_reset (%lu)\n",pending_tasks.size(agent_queue_id));
    pending_tasks.push(agent_queue_id,[this]() {
      connection_reset();
    });
    RIC_INFO("pushed connection_reset (%lu)\n",pending_tasks.size(agent_queue_id));
  }
}

int agent::connect()
{
  int ret;
  uint8_t *buf = NULL;
  ssize_t len;

  if (state == RIC_DISABLED || state == RIC_UNINITIALIZED)
    return SRSLTE_SUCCESS;
  else if (state == RIC_CONNECTED || state == RIC_ESTABLISHED)
    return SRSLTE_ERROR;

  /* Open a connection to the RIC. */
  if (ric_socket.is_init())
      ric_socket.close();
  if (!ric_socket.open_socket(srslte::net_utils::addr_family::ipv4,
			      srslte::net_utils::socket_type::stream,
			      srslte::net_utils::protocol_type::SCTP)) {
    RIC_ERROR("failed to open an SCTP socket to RIC; stopping agent\n");
    /* Cannot recover from this error, so stop the agent. */
    stop();
    set_state(RIC_DISABLED);
    return SRSLTE_ERROR;
  }

  if (strlen(args.ric_agent.local_ipv4_addr.c_str()) > 0
      || args.ric_agent.local_port) {
    if (!ric_socket.bind_addr(args.ric_agent.local_ipv4_addr.c_str(),
			      args.ric_agent.local_port)) {
      RIC_ERROR("failed to bind local SCTP address/port (%s,%d)\n",
		args.ric_agent.local_ipv4_addr.c_str(),
		args.ric_agent.local_port);
      stop();
      set_state(RIC_DISABLED);
      return SRSLTE_ERROR;
    }
  }

  /* Set specific stream options for this socket. */
  struct sctp_initmsg initmsg = { 1,1,3,5 };
  if (setsockopt(ric_socket.fd(),IPPROTO_SCTP,SCTP_INITMSG,
		 &initmsg,sizeof(initmsg)) < 0) {
    RIC_ERROR("failed to set sctp socket stream options (%s); stopping agent\n",
	      strerror(errno));
    ric_socket.reset();
    /* Cannot recover from this error, so stop the agent. */
    stop();
    set_state(RIC_DISABLED);
    return SRSLTE_ERROR;
  }
  int reuse = 1;
  if (setsockopt(ric_socket.fd(),SOL_SOCKET,SO_REUSEADDR,
		 &reuse,sizeof(reuse)) < 0) {
    RIC_WARN("failed to set sctp socket reuseaddr: %s\n",strerror(errno));
  }

  if (!ric_socket.connect_to(args.ric_agent.remote_ipv4_addr.c_str(),
				args.ric_agent.remote_port,
				&ric_sockaddr)) {
    RIC_ERROR("failed to connect to %s",
	      args.ric_agent.remote_ipv4_addr.c_str());
    ric_socket.reset();
    /* Might be recoverable; don't stop the agent. */
    handle_connection_error();
    return SRSLTE_ERROR;
  }

  /* Add an rx handler for the RIC socket. */
  auto ric_socket_handler =
    [this](srslte::unique_byte_buffer_t pdu,
	   const sockaddr_in& from,const sctp_sndrcvinfo& sri,int flags) {
      handle_message(std::move(pdu),from,sri,flags);
  };
  rx_sockets->add_socket_sctp_pdu_handler(ric_socket.fd(),ric_socket_handler);

  set_state(RIC_CONNECTED);
  RIC_INFO("connected to RIC on %s",
	   args.ric_agent.remote_ipv4_addr.c_str());

  /* Send an E2Setup request to RIC. */
  ret = ric::e2ap::generate_e2_setup_request(this,&buf,&len);
  if (ret) {
    RIC_ERROR("failed to generate E2setupRequest; disabling RIC agent!\n");
    stop();
    set_state(RIC_DISABLED);
    if (buf)
      free(buf);
    return 1;
  }
  if (!send_sctp_data(buf,len)) {
    RIC_ERROR("failed to send E2setupRequest; aborting connect\n");
    if (buf)
      free(buf);
    handle_connection_error();
    return 1;
  }
  RIC_INFO("sent E2setupRequest to RIC\n");
  free(buf);

  /*
   * Wait for E2setupResponse or Failure.  For now, it's ok to busy-wait
   * in this thread since it's dedicated to the connection.  Later, we
   * need to be more careful.
   */
  while (state == RIC_CONNECTED && !is_state_stale(6)) {
    RIC_DEBUG("waiting for E2setupResponse...\n");
    sleep(2);
  }
  if (state != RIC_ESTABLISHED) {
    RIC_ERROR("did not receive successful E2setupResponse; aborting connect\n");
    set_state(RIC_FAILURE);
    handle_connection_error();
    return 1;
  }

  return 0;
}

bool agent::handle_message(srslte::unique_byte_buffer_t pdu,
			   const sockaddr_in &from,const sctp_sndrcvinfo &sri,
			   int flags)
{
  int ret;

  /* If this "message" is an SCTP notification/event, handle it. */
  if (flags & MSG_NOTIFICATION) {
    union sctp_notification *n = (union sctp_notification *)pdu->msg;
    switch (n->sn_header.sn_type) {
    case SCTP_SHUTDOWN_EVENT:
      struct sctp_shutdown_event *shut; 
      shut = (struct sctp_shutdown_event *)pdu->msg; 
      RIC_DEBUG("recv SCTP_SHUTDOWN (assoc %d)\n",shut->sse_assoc_id);
      handle_connection_error();
      break;
    default:
      RIC_DEBUG("received sctp event %d; ignoring\n",n->sn_header.sn_type);
      break;
    }
    return true;
  }

  /* Otherwise, handle the message. */
  ret = ric::e2ap::handle_message(this,0,pdu->msg,pdu->N_bytes);
  if (ret == SRSLTE_SUCCESS)
    return true;
  else {
    RIC_ERROR("failed to handle incoming message (%d)\n",ret);
    return false;
  }
}

bool agent::send_sctp_data(uint8_t *buf,ssize_t len)
{
  ssize_t ret;

  ret = sctp_sendmsg(ric_socket.fd(),(const void *)buf,len,
		     (struct sockaddr *)&ric_sockaddr,sizeof(ric_sockaddr),
		     htonl(E2AP_SCTP_PPID),0,0,0,0);
  if (ret == -1) {
    RIC_ERROR("failed to send %ld bytes\n",len);
    return false;
  }

  return true;
}

void agent::disconnect(bool use_shutdown)
{
  if (!(state == RIC_CONNECTED || state == RIC_ESTABLISHED))
    return;

  RIC_INFO("disconnecting from RIC\n");
  if (use_shutdown) {
      struct sctp_sndrcvinfo sri = { 0 };
      sri.sinfo_flags = SCTP_EOF;
      sctp_send(ric_socket.fd(),NULL,0,&sri,0);
  }
  rx_sockets->remove_socket(ric_socket.fd());
  ric_socket.reset();

  ric_mcc = ric_mnc = 0;
  ric_id = 0;

  set_state(RIC_DISCONNECTED);
}

void agent::stop()
{
  if (state == RIC_DISABLED || state == RIC_UNINITIALIZED)
    return;

  pending_tasks.push(agent_queue_id,[this]() { stop_impl(); });
  wait_thread_finish();
}

void agent::stop_impl()
{
  RIC_INFO("stopping agent\n");

  disconnect();
  rx_sockets->stop();
  pending_tasks.erase_queue(agent_queue_id);
  agent_queue_id = pending_tasks.add_queue();
  set_state(RIC_INITIALIZED);
  agent_thread_started = false;
}

/**
 * Implements an E2 reset.  Must not schedule any tasks, since it might
 * be called from connection_reset(), which clears the task queue.
 */
int agent::reset()
{
  RIC_INFO("resetting E2 agent state\n");

  /* TODO: cancel subscription actions/timers in a meaningful way. */
  subscriptions.clear();

  return SRSLTE_SUCCESS;
}

static const char *state_to_string(agent_state_t state)
{
    switch (state) {
    case RIC_UNINITIALIZED:
	return "UNINITIALIZED";
    case RIC_INITIALIZED:
	return "INITIALIZED";
    case RIC_CONNECTED:
	return "CONNECTED";
    case RIC_ESTABLISHED:
	return "ESTABLISHED";
    case RIC_FAILURE:
	return "FAILURE";
    case RIC_DISCONNECTED:
	return "DISCONNECTED";
    case RIC_DISABLED:
	return "DISABLED";
    default:
	return "INVALID";
    }
}

void agent::set_state(agent_state_t state_)
{
    state = state_;
    if (state == RIC_ESTABLISHED) {
	/* We have a successful connection, so clear our current delay. */
	current_reconnect_delay = 0;
    }
    state_time = std::time(NULL);
    RIC_DEBUG("RIC state -> %s\n",state_to_string(state_));
}

bool agent::is_state_stale(int seconds)
{
    if ((std::time(NULL) - state_time) >= seconds)
	return true;
    return false;
}

/**
 * Implements a connection reset: disconnect(), reset(), connect().
 */
int agent::connection_reset(int delay)
{
  RIC_INFO("resetting agent connection\n");

  if (delay < 0) {
    delay = current_reconnect_delay;
    /* Update our current reconnect delay. */
    current_reconnect_delay += RIC_AGENT_RECONNECT_DELAY_INC;
    if (current_reconnect_delay > RIC_AGENT_RECONNECT_DELAY_MAX)
      current_reconnect_delay = RIC_AGENT_RECONNECT_DELAY_MAX;
  }

  reset();
  disconnect();
  pending_tasks.erase_queue(agent_queue_id);
  agent_queue_id = pending_tasks.add_queue();
  set_state(RIC_INITIALIZED);
  /* This is only "safe" because the agent_queue was just cleared. */
  RIC_INFO("delaying new connection for %d seconds",delay);
  sleep(delay);
  return connect();
}

}
