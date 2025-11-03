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
    }
}
