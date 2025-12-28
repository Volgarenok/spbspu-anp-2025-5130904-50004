#include "transform.h"
#include <iostream>

int main()

{
    auto res = ahrammev::compute();
    std::cout << res.cntMin << '\n';
    std::cout << res.aftMax << '\n';
    return 0;
}
