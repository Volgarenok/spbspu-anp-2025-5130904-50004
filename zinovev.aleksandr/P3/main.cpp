#include <iostream>
#include <fstream>
#include <exception>

namespace zinovev
{
    std::istream& readInput();
    void fillSpiral();
    int findLongestColumn();
    std::ostream& writeOutput();
}

int main(int argc, char** argv)
{
    std::ifstream input(argv[2]);
    std::ofstream output(argv[3]);

    int rows = 0;
    int cols = 0;
    int result = 0;

    input >> rows >> cols;

    if (argv[1][0] == '1')
    {
        int array[10000] = {};

        zinovev::readInput();

        input.close();

        result = zinovev::findLongestColumn();
        zinovev::fillSpiral();
        zinovev::writeOutput();
    }
    else if (argv[1][0] == '2')
    {
        int* array = nullptr;
        try
        {
            array = new int[rows * cols] {};

            zinovev::readInput();

            input.close();

            result = zinovev::findLongestColumn();
            zinovev::fillSpiral();
            zinovev::writeOutput();

            delete[] array;
        }
        catch (std::exception& exception)
        {
            std::cerr << exception.what() << "\n";
            delete[] array;
            return 1;
        }
    }

    return 0;
}

std::istream& zinovev::readInput()
{

}

void zinovev::fillSpiral()
{

}

int zinovev::findLongestColumn()
{

}

std::ostream& zinovev::writeOutput()
{

}
