#include <fstream>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <memory>
namespace ivanov {
    struct Dynamic {
        int rows, cols;
        int* matrix = nullptr;
        void freed();
        void fllincwav();
        int maxsummdg() const;
    };
    struct Static {
        int rows, cols;
        int matrix[1000] = {};
        void fllincwav();
        int maxsummdg() const;
    };
}
int main(int argc, char** argv)
{
    if (argc != 4)
    {
        std::cerr << "Not enough arguments";
        return 1;
    }
    if (strcmp(argv[1], "1") != 0 && strcmp(argv[1], "2") != 0)
    {
        std::cerr << "Garbage in argument 1";
        return 1;
    }
    if (strcmp(argv[1], "1") == 0)
    {
        std::fstream input(argv[2]);
        if (!input.is_open()) {
            std::cerr << "Cannot open input file";
            return 1;
        }
        ivanov::Static s;
        input >> s.rows >> s.cols;
        if (input.fail() || input.eof())
        {
            std::cerr << "Input fail";
            return 1;
        }
        for (int i = 0; i < s.rows * s.cols; ++i)
        {
            input >> s.matrix[i];
        }
        if (input.fail() || input.eof())
        {
            std::cerr << "Input fail";
            return 1;
        }
        input.close();
        s.fllincwav();
        std::ofstream output(argv[3]);
        for (int i = 0; i < s.rows * s.cols; ++i)
        {
            output << s.matrix[i] << " ";
        }
        output << "\n" << s.maxsummdg() << "\n";
    }
    else
    {
        std::fstream input(argv[2]);
        if (!input.is_open()) {
            std::cerr << "Cannot open input file";
            return 1;
        }
        ivanov::Dynamic d;
        input >> d.rows >> d.cols;
        if (input.fail() || input.eof())
        {
            std::cerr << "Input fail";
            return 1;
        }
        d.matrix = reinterpret_cast<int*>(malloc(sizeof(int) * (d.rows * d.cols)));
        if (!d.matrix) {
            std::cerr << "Memory allocation failed";
            d.freed();
            return 1;
        }
        for (int i = 0; i < d.rows * d.cols; ++i)
        {
            input >> d.matrix[i];
        }
        if (input.fail() || input.eof())
        {
            std::cerr << "Input fail";
            d.freed();
            return 1;
        }
        input.close();
        d.fllincwav();
        std::ofstream output(argv[3]);
        for (int i = 0; i < d.rows * d.cols; ++i)
        {
            output << d.matrix[i] << " ";
        }
        output << "\n" << d.maxsummdg() << "\n";
        free(d.matrix);
    }
    return 0;
}
void ivanov::Static::fllincwav()
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            int layer = std::min(std::min(i, rows-1-i), std::min(j, cols-1-j));
            matrix[i*cols + j] += (layer + 1);
        }
    }
}
void ivanov::Dynamic::fllincwav()
{
    for (int i = 0; i < rows; ++i)
     {
        for (int j = 0; j < cols; ++j)
        {
            int layer = std::min(std::min(i, rows-1-i), std::min(j, cols-1-j));
            matrix[i*cols + j] += (layer + 1);
        }
    }
}
int ivanov::Static::maxsummdg() const
{
    int ans = 0;
    for (int d = 0; d < rows + cols - 1; ++d)
    {
        int curr = 0;
        for (int i = 0; i < rows; ++i)
        {
            int j = d - i;
            if (j >= 0 && j < cols)
            {
                curr += matrix[i * cols + j];
            }
        }
        if (curr > ans) {
            ans = curr;
        }
    }
    return ans;
}
int ivanov::Dynamic::maxsummdg() const
{
    int ans = 0;
    for (int d = 0; d < rows + cols - 1; ++d)
    {
        int curr = 0;
        for (int i = 0; i < rows; ++i)
        {
            int j = d - i;
            if (j >= 0 && j < cols)
            {
                curr += matrix[i * cols + j];
            }
        }
        if (curr > ans)
        {
            ans = curr;
        }
    }
    return ans;
}
void ivanov::Dynamic::freed()
{
    free(matrix);
}
