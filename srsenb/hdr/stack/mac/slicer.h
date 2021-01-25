#ifndef __SLICER_H_
#define __SLICER_H_

#include "srslte/common/common.h"
#include "srslte/common/log.h"
#include <map>
#include <string>
#include <stdint.h>
#include <vector>

namespace slicer {

typedef struct slice {
    uint32_t n_sf_rel;
    uint32_t n_sf_alloc = 0;
    std::vector<uint64_t> member_imsis;
} slice_t;


class slicer {
  public:
    slicer();
    ~slicer();

    void init(std::string slice_db_fname, bool workshare_);
    int add_slice(std::string name, uint32_t n_sf_rel, std::vector<uint64_t> member_imsis);
    int rem_slice(std::string name);
    int add_slice_member(std::string s_name, uint64_t imsi);
    int rem_slice_member(std::string s_name, uint64_t imsi);
    int upd_slice_n_sf_rel(std::string s_name, uint32_t n_sf);
    int upd_member_crnti(uint64_t imsi, uint16_t crnti);
    int upd_member_crnti(uint16_t old_crnti, uint16_t crnti);
    void upd_slice_crntis(std::string s_name);
    void upd_sf_alloc();
    std::vector<uint16_t> get_cur_sf_crntis(uint32_t tti_tx_dl);
    bool read_slice_db_file(std::string db_filename);

    std::map<std::string, std::vector<uint16_t> > slice_to_crnti_vec;
    std::map<uint64_t, uint16_t> imsi_to_crnti; // for all ues, regardless of slices
    std::map<std::string, slice> slices;
    std::map<std::string, slice>::iterator slice_iter;
    std::vector<uint32_t> sf_alloc;
    uint32_t cur_slice_sf = 0;
    uint32_t total_sf_alloc = 0;
    bool enable = false;
    bool workshare = false;
};


  // helper functions
  std::vector<std::string> split_string(const std::string& str, char delimiter);
  uint32_t calc_gcf(uint32_t a, uint32_t b);
  uint32_t calc_gcf_vec(std::vector<uint32_t> v);

} // namespace slicer

#endif // __SLICER_H_
