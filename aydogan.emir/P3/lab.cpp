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

int main(int argc, char** argv)
{
    if (argc != 4) {
        std::cerr << "Wrong number of arguments\n";
        return 1;
    }

    int mode = argv[1][0] - '0';
    if (mode != 1 && mode != 2) {
        std::cerr << "First parameter is out of range\n";
        return 1;
    }

    std::ifstream in(argv[2]);
    std::ofstream out(argv[3]);

    if (!in) {
        std::cerr << "Cannot open input file\n";
        return 2;
    }

    int r = 0;
    int c = 0;

    if (!(in >> r >> c)) {
        std::cerr << "File is empty\n";
        return 2;
    }

    int variant = 0;
    if (!(in >> variant)) {
        std::cerr << "Cannot read variant\n";
        return 2;
    }

    if (variant != 1 && variant != 2) {
        std::cerr << "Variant must be 1 or 2\n";
        return 2;
    }

    if ((r == 0 && c != 0) || (r != 0 && c == 0) || r < 0 || c < 0) {
        std::cerr << "Invalid rows or columns\n";
        return 2;
    }

    if (r == 0 && c == 0) {
        out << 0 << "\n";
        return 0;
    }

    try {
        if (mode == 1) {
            work_static(r, c, in, out, variant);
        } else {
            work_dynamic(r, c, in, out, variant);
        }
    } catch (const std::exception& e) {
        std::cerr << "ERROR: " << e.what() << "\n";
        return 2;
    } catch (...) {
        std::cerr << "ERROR\n";
        return 2;
    }

    return 0;
}

} 

int main(int argc, char** argv)
{
    return aydogan::main(argc, argv);
}
