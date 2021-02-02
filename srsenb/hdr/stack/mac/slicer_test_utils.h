#ifndef __SLICER_TEST_UTILS_H_
#define __SLICER_TEST_UTILS_H_

#include "slicer_defs.h"

namespace slicer {

std::vector<slice_t> slices{
//  name      share      imsis
  { "slice0", { 12 },  { 1010123456789, 1010123456790, 1010123456791 }},
  { "slice1", { 90 },  { 1010123456792, 1010123456793, 1010123456794 }},
  { "slice2", { 30 },  { 1010123456795, 1010123456796, 1010123456797 }},
  { "slice3", { 30 },  { 1010123456798, 1010123456799 }},
};

std::vector<slice_imsis_t> imsis_to_unbind{
//  name        imsis
  { "slice0", { 1010123456790, 1010123456791 }},
  { "slice1", { 1010123456793, 1010123456794 }},
  { "slice2", { 1010123456796, 1010123456797 }},
  { "slice3", { 1010123456799 }},
};

std::vector<std::string> slices_to_delete{ "slice1", "slice3" };

} // namespace slicer

#endif // __SLICER_TEST_UTILS_H_
