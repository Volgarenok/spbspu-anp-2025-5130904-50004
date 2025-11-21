#include <iostream>
#include <fstream>
#include <cstdlib>

namespace zvyagin
{

size_t count_columns_no_same_adjacent(const int* data, size_t rows, size_t cols)
{
    if (cols == 0) {
        return 0;
    }
    if (rows < 2) {
        return cols;
    }
    unsigned count = 0;
    for (size_t j = 0; j < cols; ++j)
    {
        bool has_same = false;
        for (size_t i = 0; i < rows - 1; ++i)
        {
            if (data[i * cols + j] == data[(i + 1) * cols + j])
            {
                has_same = true;
                break;
            }
        }
        if (!has_same) {
            ++count;
        }
    }
    return count;
}

size_t count_local_maxima(const int* data, size_t rows, size_t cols)
{
    if (rows < 3 || cols < 3) {
        return 0;
    }
    unsigned count = 0;
    for (size_t i = 1; i < rows - 1; ++i)
    {
        for (size_t j = 1; j < cols - 1; ++j)
        {
            int cur = data[i * cols + j];
            bool is_max = true;
            for (int di = -1; di <= 1 && is_max; ++di)
            {
                for (int dj = -1; dj <= 1; ++dj)
                {
                    if (di == 0 && dj == 0) {
                        continue;
                    }
                    if (cur <= data[(i + di) * cols + (j + dj)]) {
                        is_max = false;
                        break;
                    }
                }
            }
            if (is_max) {
                ++count;
            }
        }
    }
    return count;
}
} // namespace zvyagin

int main(int argc, char** argv)
{
    if (argc != 4)
    {
        std::cerr << "Usage: ./lab num input output\n";
        return 1;
    }

    int num = std::atoi(argv[1]);
    if (num != 1 && num != 2)
    {
        std::cerr << "First parameter must be 1 or 2\n";
        return 1;
    }

    std::ifstream input(argv[2]);
    if (!input.is_open())
    {
        std::cerr << "Cannot open input file\n";
        return 2;
    }

    size_t n, m;
    if (!(input >> n >> m))
    {
        std::cerr << "Cannot read matrix dimensions\n";
        return 2;
    }

    if (n == 0 || m == 0)
    {
        std::ofstream output(argv[3]);
        if (!output.is_open())
        {
            std::cerr << "Cannot open output file\n";
            return 1;
        }
        output << "0\n0\n";
        output.close();
        input.close();
        return 0;
    }

    if (num == 1)
    {
        int fixed[10000];
        for (size_t i = 0; i < n * m; ++i)
        {
            if (!(input >> fixed[i]))
            {
                std::cerr << "Invalid matrix element data\n";
                return 2;
            }
        }

        input.close();

        std::ofstream output(argv[3]);
        if (!output.is_open())
        {
            std::cerr << "Cannot open output file\n";
            return 1;
        }

        output << zvyagin::count_columns_no_same_adjacent(fixed, n, m) << '\n';
        output << zvyagin::count_local_maxima(fixed, n, m) << '\n';
        output.close();
    }

    else
    {
        int* dyn = static_cast<int*>(std::malloc(n * m * sizeof(int)));
        if (!dyn && n * m > 0)
        {
            std::cerr << "Memory allocation failed\n";
            return 1;
        }

        for (unsigned i = 0; i < n * m; ++i)
        {
            if (!(input >> dyn[i]))
            {
                std::free(dyn);
                std::cerr << "Invalid matrix element data\n";
                return 2;
            }
        }
        input.close();

        std::ofstream output(argv[3]);
        if (!output.is_open())
        {
            std::free(dyn);
            std::cerr << "Cannot open output file\n";
            return 1;
        }

        output << zvyagin::count_columns_no_same_adjacent(dyn, n, m) << '\n';
        output << zvyagin::count_local_maxima(dyn, n, m) << '\n';
        output.close();

        std::free(dyn);
    }
    return 0;
}
