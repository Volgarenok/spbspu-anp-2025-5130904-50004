#include "evn_cnt.hpp"

namespace em {

EvnCnt::EvnCnt() : current_(0), max_(0) {}

void EvnCnt::operator()(int value) {
    if (value % 2 == 0) {
        ++current_;
        if (current_ > max_) max_ = current_;
    } else {
        current_ = 0;
    }
}

std::size_t EvnCnt::operator()() const {
    return max_;
}

const char* EvnCnt::name() const {
    return "evn-cnt";
}

}
