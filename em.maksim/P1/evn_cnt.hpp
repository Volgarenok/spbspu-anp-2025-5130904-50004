#ifndef EVN_CNT_HPP
#define EVN_CNT_HPP

#include <cstddef>

namespace em {

class EvnCnt {
public:
    EvnCnt();
    void operator()(int value);
    std::size_t operator()() const;
    const char* name() const;

private:
    std::size_t current_;
    std::size_t max_;
};

}

#endif
