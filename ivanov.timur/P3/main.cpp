#include <fstream>
#include <iostream>
namespace ivanov {
    struct Dynamic {
        int rows, cols;
        int * matrix = reinterpret_cast< int * >(malloc(sizeof(int) * (rows * cols)));
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
int main(int argc, char ** argv)
{
    if (argc != 4)
    {
        std::cerr << "Not enough arguments";
        return 1;
    }
    if (argv[1] != '1' && argv[1] != '2')
    {
        std::cerr << "Garbage in argument 1";
        return 1;
    }
    if (argv[1] == '1')
    {
        std::fstream input(argv[2]);
        ivanov::Static s;
        input >> s.rows >> s.cols;
        for (size_t i = 0; i < s.rows*s.cols; ++i)
        {
            input >> s.matrix[i];
        }
        input.close();
        s.fllincwav();
        std::ofstream output(argv[3]);
        for (size_t i = 0; i < s.rows*s.cols; ++i)
        {
            output << s.matrix[i] << " ";
        }
        output << "\n" << s.maxsummdg() << "\n";
    }
    else
    {
        std::fstream input(argv[2]);
        ivanov::Dynamic d;
        input >> d.rows >> d.cols;
        for (size_t i = 0; i < d.rows*d.cols; ++i)
        {
            input >> d.matrix[i];
        }
        if (!input)
        {
            free(d.matrix);
            return 2;
        }
        input.close();
        d.fllincwav();
        std::ofstream output(argv[3]);
        for (size_t i = 0; i < d.rows*d.cols; ++i)
        {
            output << d.matrix[i] << " ";
        }
        output << "\n" << d.maxsummdg() << "\n";
        free(d.matrix);
    }
}
void ivanov::Static::fllincwav()
{
    for (int row = 0; row < (rows/2 + rows%2); ++row)
    {
        for (int i = row; i < cols - row; ++i)
        {
            matrix[cols*row + i]+=(row+1);
            matrix[cols*(rows-row-1) + i]+=(row+1);
            matrix[cols*i + row]+=(row+1);
            matrix[cols*(rows-i-1) + row]+=(row+1);
        }
    }
}
void ivanov::Dynamic::fllincwav()
{
    for (int row = 0; row < (rows/2 + rows%2); ++row)
    {
        for (int i = row; i < cols - row; ++i)
        {
            matrix[cols*row + i]+=(row+1);
            matrix[cols*(rows-row-1) + i]+=(row+1);
            matrix[cols*i + row]+=(row+1);
            matrix[cols*(rows-i-1) + row]+=(row+1);
        }
    }
}
int ivanov::Static::maxsummdg() const
{
    int ans = matrix[0];
    int curr = 0;
    for (int c = 1; c < cols - 1; ++c)
    {
        curr = 0;
        for (int row = 0; row < c; ++row)
        {
            curr += matrix[cols*row + c - row];
        }
        if (curr > ans)
        {
            ans = curr;
        }
    }
    for (int c = 1; c < cols - 1; ++c)
    {
        curr = 0;
        for (int row = rows; row > rows - c; --row)
        {
            curr += matrix[cols*row + c - row];
        }
        if (curr > ans)
        {
            ans = curr;
        }
    }
    if (matrix[cols*rows - 1] > ans)
    {
        ans = matrix[cols*rows - 1];
    }
    return ans;
}
int ivanov::Dynamic::maxsummdg() const
{
    int ans = matrix[0];
    int curr = 0;
    for (int c = 1; c < cols - 1; ++c)
    {
        curr = 0;
        for (int row = 0; row < c; ++row)
        {
            curr += matrix[cols*row + c - row];
        }
        if (curr > ans)
        {
            ans = curr;
        }
    }
    for (int c = 1; c < cols - 1; ++c)
    {
        curr = 0;
        for (int row = rows; row > rows - c; --row)
        {
            curr += matrix[cols*row + c - row];
        }
        if (curr > ans)
        {
            ans = curr;
        }
    }
    if (matrix[cols*rows - 1] > ans)
    {
        ans = matrix[cols*rows - 1];
    }
    return ans;
}