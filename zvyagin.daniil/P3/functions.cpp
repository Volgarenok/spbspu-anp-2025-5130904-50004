#include "functions.hpp"

size_t zvyagin::count_columns_no_same_adjacent(const int* data, size_t rows, size_t cols)
{
    if (cols == 0) {
        return 0;
    }
    if (rows < 2) {
        return cols;
    }
    size_t count = 0;
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

size_t zvyagin::count_local_maxima(const int* data, size_t rows, size_t cols)
{
    if (rows < 3 || cols < 3) {
        return 0;
    }
    size_t count = 0;
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

bool zvyagin::readMatrix(std::ifstream& input, int* data, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        if (!(input >> data[i]))
        {
            return false;
        }
    }
    return true;
}
