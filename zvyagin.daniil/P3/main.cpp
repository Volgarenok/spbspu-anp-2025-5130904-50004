#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

namespace zvyagin
{

struct FixedMatrix {
    unsigned rows = 0;
    unsigned cols = 0;
    int data[10000] = {};

    unsigned count_columns_no_same_adjacent() const;
    unsigned count_local_maxima() const;
};

struct DynamicMatrix {
    unsigned rows = 0;
    unsigned cols = 0;
    int* data = nullptr;

    void free();
    unsigned count_columns_no_same_adjacent() const;
    unsigned count_local_maxima() const;
};

void DynamicMatrix::free()
{
    std::free(data);
    data = nullptr;
}

unsigned FixedMatrix::count_columns_no_same_adjacent() const
{
    if (cols == 0) {
      return 0;
    }

    if (rows < 2) {
      return cols;
    }

    unsigned count = 0;
    for (unsigned j = 0; j < cols; ++j)
    {
        bool has_same = false;
        for (unsigned i = 0; i < rows - 1; ++i)
        {
            if (data[i * cols + j] == data[(i + 1) * cols + j])
            {
                has_same = true;
                break;
            }
        }
        if (!has_same)
            ++count;
    }
    return count;
}

unsigned DynamicMatrix::count_columns_no_same_adjacent() const
{
    if (cols == 0) {
        return 0;
    }
    if (rows < 2) {
        return cols;
    }

    unsigned count = 0;
    for (unsigned j = 0; j < cols; ++j)
        {
            if (data[i * cols + j] == data[(i + 1) * cols + j])
            {
                has_same = true;
                break;
            }
        }
        if (!has_same)
            ++count;
    }
    return count;
}

unsigned FixedMatrix::count_local_maxima() const
{
    if (rows < 3 || cols < 3) return 0;

    unsigned count = 0;
    for (unsigned i = 1; i < rows - 1; ++i)
    {
        for (unsigned j = 1; j < cols - 1; ++j)
        {
            int cur = data[i * cols + j];
            bool is_max = true;
            for (int di = -1; di <= 1 && is_max; ++di)
            {
                for (int dj = -1; dj <= 1; ++dj)
                {
                    if (di == 0 && dj == 0) continue;
                    if (cur <= data[(i + di) * cols + (j + dj)])
                    {
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

unsigned DynamicMatrix::count_local_maxima() const
{
    if (rows < 3 || cols < 3) return 0;

    unsigned count = 0;
    for (unsigned i = 1; i < rows - 1; ++i)
    {
        for (unsigned j = 1; j < cols - 1; ++j)
        {
            int cur = data[i * cols + j];
            bool is_max = true;
            for (int di = -1; di <= 1 && is_max; ++di)
            {
                for (int dj = -1; dj <= 1; ++dj)
                {
                    if (di == 0 && dj == 0) continue;
                    if (cur <= data[(i + di) * cols + (j + dj)])
                    {
                        is_max = false;
                        break;
                    }
                }
            }
            if (is_max)
                ++count;
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

    if (std::strcmp(argv[1], "1") != 0 && std::strcmp(argv[1], "2") != 0)
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

    unsigned n, m;
    if (!(input >> n >> m))
    {
        std::cerr << "Cannot read matrix dimensions\n";
        return 2;
    }

    if (n == 0 || m == 0)
    {
        // Корректная матрица нулевого размера → результат 0
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

    if (std::strcmp(argv[1], "1") == 0)
    {
        if (n * m > 10000)
        {
            std::cerr << "Static matrix size exceeds limit (10000)\n";
            return 2;
        }

        zvyagin::FixedMatrix mat;
        mat.rows = n;
        mat.cols = m;

        for (unsigned i = 0; i < n * m; ++i)
        {
            if (!(input >> mat.data[i]))
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

        output << mat.count_columns_no_same_adjacent() << '\n';
        output << mat.count_local_maxima() << '\n';
        output.close();
    }
    else // argv[1] == "2"
    {
        zvyagin::DynamicMatrix mat;
        mat.rows = n;
        mat.cols = m;

        mat.data = static_cast<int *>(std::malloc(n * m * sizeof(int)));
        if (!mat.data && n * m > 0)
        {
            std::cerr << "Memory allocation failed\n";
            return 1;
        }

        bool read_error = false;
        for (unsigned i = 0; i < n * m; ++i)
        {
            if (!(input >> mat.data[i]))
            {
                read_error = true;
                break;
            }
        }
        input.close();

        if (read_error)
        {
            mat.free();
            std::cerr << "Invalid matrix element data\n";
            return 2;
        }

        std::ofstream output(argv[3]);
        if (!output.is_open())
        {
            mat.free();
            std::cerr << "Cannot open output file\n";
            return 1;
        }

        output << mat.count_columns_no_same_adjacent() << '\n';
        output << mat.count_local_maxima() << '\n';
        output.close();

        mat.free();
    }

    return 0;
}
