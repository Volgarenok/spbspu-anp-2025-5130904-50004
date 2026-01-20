#include "inc_seq.hpp"
#include "evn_cnt.hpp"
#include <iostream>

namespace em {

static bool is_valid_sequence() {
    int x;
    while (std::cin >> x) {
        if (x == 0) return true;
    }
    return false;
}

}

int main() {
    using namespace em;

    if (!is_valid_sequence()) {
        std::cerr << "Invalid input sequence\n";
        return 1;
    }

    std::cin.clear();
    std::cin.seekg(0);

    IncSeq inc_seq;
    EvnCnt evn_cnt;

    int x;
    bool has_elements = false;
    while (std::cin >> x && x != 0) {
        has_elements = true;
        inc_seq(x);
        evn_cnt(x);
    }

    if (!has_elements) {
        std::cerr << "Sequence too short to compute characteristics\n";
        return 2;
    }

    std::cout << inc_seq() << '\n';
    std::cout << evn_cnt() << '\n';

    return 0;
}
