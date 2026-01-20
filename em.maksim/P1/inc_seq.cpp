#include "inc_seq.hpp"

namespace em {

IncSeq::IncSeq() : first_(true), prev_(0), count_(0) {}

void IncSeq::operator()(int value) {
    if (first_) {
        first_ = false;
    } else if (value > prev_) {
        ++count_;
    }
    prev_ = value;
}

std::size_t IncSeq::operator()() const {
    return count_;
}

const char* IncSeq::name() const {
    return "inc-seq";
}

}
