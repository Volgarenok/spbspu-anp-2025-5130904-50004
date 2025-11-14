#include <iostream>

namespace aydogan {

std::istream& readStatic(std::istream& input, int* arr, int r, int c)
{
    for (int i = 0; i < r * c; ++i) {
        if (!(input >> arr[i])) {
            std::cerr << "Incorrect matrix input\n";
            return input;
        }
    }
    return input;
}


int main() {
    return 0;
}

}
