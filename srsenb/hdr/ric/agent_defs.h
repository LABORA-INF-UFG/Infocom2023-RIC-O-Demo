#ifndef RIC_AGENT_DEFS_H
#define RIC_AGENT_DEFS_H

namespace ric {

class agent;

typedef struct agent_args {
  bool        enabled;
  std::string remote_ipv4_addr;
  uint16_t    remote_port;
  std::string functions_disabled;
  std::string log_level;
  int log_hex_limit;
} agent_args_t;

}

#endif
