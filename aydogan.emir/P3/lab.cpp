#include <iostream>
#include <fstream>
#include <stdexcept>

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

long long minSumMDG(int r, int c, const int* a)
{
    if (r <= 0 || c <= 0) return 0;

    long long best = 0;
    bool first = true;

    for (int s = 0; s <= (r - 1) + (c - 1); ++s) {
        long long sum = 0;

        for (int i = 0; i < r; ++i) {
            int j = s - i;
            if (j >= 0 && j < c) {
                sum += a[i * c + j];
            }
        }

        if (first) {
            best = sum;
            first = false;
        } else if (sum < best) {
            best = sum;
        }
    }

    return best;
}

void work_static(int r, int c, std::ifstream& in, std::ofstream& out, int variant)
{
    const int MAX = 10000;
    if (r * c > MAX) throw std::runtime_error("Too big for static array");

    int a[MAX];

    if (!readStatic(in, a, r, c)) {
        throw std::logic_error("Input error");
    }

    if (variant == 1) {
        out << numColLsr(r, c, a) << "\n";
    } else {
        out << minSumMDG(r, c, a) << "\n";
    }
}

void work_dynamic(int r, int c, std::ifstream& in, std::ofstream& out, int variant)
{
    int* a = new int[r * c];

    if (!readDynamic(in, a, r, c)) {
        delete[] a;
        throw std::logic_error("Input error");
    }

    if (variant == 1) {
        out << numColLsr(r, c, a) << "\n";
    } else {
        out << minSumMDG(r, c, a) << "\n";
    }

    delete[] a;
}

int main()
{
    return 0;
}

} 
