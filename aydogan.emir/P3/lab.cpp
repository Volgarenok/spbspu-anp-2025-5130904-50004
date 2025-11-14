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

std::istream& readDynamic(std::istream& input, int* arr, int r, int c)
{
    for (int i = 0; i < r * c; ++i) {
        if (!(input >> arr[i])) {
            std::cerr << "Incorrect matrix input\n";
            return input;
        }
    }
    return input;
}

int numColLsr(int r, int c, const int* a)
{
    if (r <= 0 || c <= 0) return 0;

    int bestLen = 0;
    int bestCol = 1;

    for (int col = 0; col < c; ++col) {
        int cur = 1;
        int maxHere = 1;

        for (int row = 1; row < r; ++row) {
            int prev = a[(row - 1) * c + col];
            int now  = a[row * c + col];

            if (now == prev) {
                ++cur;
                if (cur > maxHere) maxHere = cur;
            } else {
                cur = 1;
            }
        }

        if (maxHere > bestLen) {
            bestLen = maxHere;
            bestCol = col + 1;
        }
    }

    return bestCol;
}

int main()
{
    return 0;
}

} 
