#include "pozdeev.hpp"

int main(int argc, char* argv[])
{
    int exit = 0;

    if (argc != 4)
    {
        const char* errorMessage = (argc < 4) ? "Not enough arguments" : "Too many arguments";
        std::cerr << errorMessage << std::endl;
        return 1;
    }

    int num = 0;
    int parseResult = pozdeev::numAnalysis(argv[1], num);

    if (parseResult == 1)
    {
        std::cerr << "First parameter is not a number" << std::endl;
        return 1;
    }
    if (parseResult == 2)
    {
        std::cerr << "First parameter is out of range (must be 1 or 2)" << std::endl;
        return 1;
    }

    std::ifstream fin(argv[2]);
    if (!fin.is_open())
    {
        std::cerr << "ERROR: Could not open input file" << std::endl;
        return 2;
    }

    std::ofstream fout(argv[3]);
    if (!fout.is_open())
    {
        std::cerr << "ERROR: Could not open output file" << std::endl;
        fin.close();
        return 2;
    }

    int rows, cols;
    if (!(fin >> rows) || !(fin >> cols))
    {
        std::cerr << "ERROR: Invalid matrix dimensions format or file is empty" << std::endl;
        fin.close();
        fout.close();
        return 2;
    }

    if (rows < 0 || cols < 0)
    {
        std::cerr << "ERROR: Matrix dimensions cannot be negative" << std::endl;
        fin.close();
        fout.close();
        return 2;
    }

    if (num == 1)
    {
        exit = pozdeev::processStatic(fin, fout, rows, cols);
    }
    else
    {
        exit = pozdeev::processDynamic(fin, fout, rows, cols);
    }

    fin.close();
    fout.close();

    return exit;
}
