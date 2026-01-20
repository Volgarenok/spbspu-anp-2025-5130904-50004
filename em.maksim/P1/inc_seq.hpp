#ifndef INC_SEQ_HPP
#define INC_SEQ_HPP

#include <cstddef>

namespace em {

class IncSeq {
public:
    IncSeq();
    void operator()(int value);
    std::size_t operator()() const;
    const char* name() const;

private:
    bool first_;
    int prev_;
    std::size_t count_;
};

} // namespace em

#endif
