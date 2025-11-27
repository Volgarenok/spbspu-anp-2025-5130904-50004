#include <iostream>
#include <fstream>
#include <cstdlib>
#include "functions.hpp"

int main(int argc, char** argv)
{
    if (argc != 4)
    {
        std::cerr << "Usage: ./lab num input output\n";
        return 1;
    }

    int num;
    try {
        num = std::stoi(argv[1]);
    } catch (const std::invalid_argument&) {
        std::cerr << "First parameter is not a number\n";
        return 1;
    } catch (const std::out_of_range&) {
        std::cerr << "First parameter is out of range\n";
        return 1;
    }

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

    size_t n = 0, m = 0;
    if (!(input >> n >> m))
    {
        std::cerr << "Cannot read matrix dimensions\n";
        return 2;
    }

    std::ofstream output;

    if (n == 0 || m == 0)
    {
        output.open(argv[3]);
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

        output.open(argv[3]);
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

        output.open(argv[3]);
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
