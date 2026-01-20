#include "inc_seq.hpp"
#include "evn_cnt.hpp"
#include <iostream>

int main() {
    em::IncSeq inc_seq;
    em::EvnCnt evn_cnt;
    int x;
    while (std::cin >> x && x != 0) {
        inc_seq(x);
        evn_cnt(x);
    }
    std::cout << inc_seq() << '\n';
    std::cout << evn_cnt() << '\n';
    return 0;
}
