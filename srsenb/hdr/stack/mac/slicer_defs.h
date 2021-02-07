#ifndef __SLICER_DEFS_H_
#define __SLICER_DEFS_H_

#include "stdint.h"
#include <string>
#include <vector>

namespace slicer {

typedef struct prop_alloc_policy {
  uint32_t share;
} prop_alloc_policy_t;

typedef struct slice_config {
  std::string name;
  prop_alloc_policy_t prop_alloc_policy;
} slice_config_t;

typedef struct slice_imsis {
  std::string name;
  std::vector<uint64_t> imsi_list;
} slice_imsis_t;

typedef struct slice {
  slice_config_t config;
  std::vector<uint64_t> imsi_list;
} slice_t, slice_status_t;

} // namespace slicer



#endif // __SLICER_DEFS_H_
