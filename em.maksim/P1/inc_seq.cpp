#include "inc_seq.hpp"

em::IncSeq::IncSeq() : first_(true), prev_(0), count_(0) {}

void em::IncSeq::operator()(int value) {
    if (first_) {
        first_ = false;
    } else if (value > prev_) {
        ++count_;
    }
    prev_ = value;
}

std::size_t em::IncSeq::operator()() const {
    return count_;
}

const char* em::IncSeq::name() const {
    return "inc-seq";
}
