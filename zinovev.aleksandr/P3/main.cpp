#include <iostream>
#include <fstream>
#include <exception>

namespace zinovev
{
    std::istream& readInput(std::istream& input, int* array, int rows, int cols);
    void fillSpiral();
    int findLongestColumn(int* array, int rows, int cols);
    std::ostream& writeOutput(std::ostream& output, const int* array, int rows, int cols, int result);
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

        zinovev::readInput(input, array, rows, cols);

        input.close();

        result = zinovev::findLongestColumn(array, rows, cols);
        zinovev::fillSpiral();
        zinovev::writeOutput(output, array, rows, cols, result);
    }
    else if (argv[1][0] == '2')
    {
        int* array = nullptr;
        try
        {
            array = new int[rows * cols] {};

            zinovev::readInput(input, array, rows, cols);

            input.close();

            result = zinovev::findLongestColumn(array, rows, cols);
            zinovev::fillSpiral();
            zinovev::writeOutput(output, array, rows, cols, result);

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

std::istream& zinovev::readInput(std::istream& input, int* array, int rows, int cols)
{
    for (int i = 0; i < rows * cols && input >> array[i]; ++i);

    return input;
}

void zinovev::fillSpiral()
{

}

int zinovev::findLongestColumn(int* array, int rows, int cols)
{
    if (rows == 0)
    {
        return 0;
    }

    int result = 0;
    int maxCount = 0;

    for (int column = 0; column < cols; ++column)
    {
        int currentCount = 0;

        for (int row = 1; row < rows; ++row)
        {
            if (array[cols * (row - 1) + column] == array[cols * row + column])
            {
                ++currentCount;
            }
        }

        if (currentCount > maxCount)
        {
            maxCount = currentCount;
            result = column + 1;
        }
    }

    return result;
}

std::ostream& zinovev::writeOutput(std::ostream& output, const int* array, int rows, int cols, int result)
{
    output << result << "\n";

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            output << array[i * cols + j] << " ";
        }
        output << "\n";
    }

    return output;
}
