#include <iostream>
#include <fstream>
#include <exception>

namespace zinovev
{
    std::istream& readInput(std::istream& input, int* array, int rows, int cols);
    void fillSpiral(int* array, int rows, int cols);
    int findLongestColumn(int* array, int rows, int cols);
    std::ostream& writeOutput(std::ostream& output, const int* array, int rows, int cols, int result);
}

int main(int argc, char** argv)
{
    if (argc < 4)
    {
        std::cerr << "Not enough arguments" << "\n";
        return 1;
    }
    else if (argc > 4)
    {
        std::cerr << "Too many arguments" << "\n";
        return 1;
    }

    int size = 0;
    while (argv[1][size] != '\0')
    {
        ++size;
    }

    if (size != 1)
    {
        std::cerr << "First parameter is not a number" << "\n";
        return 1;
    }

    if (argv[1][0] != '1' && argv[1][0] != '2')
    {
        std::cerr << "First parameter is out of range" << "\n";
        return 1;
    }

    std::ifstream input(argv[2]);
    std::ofstream output(argv[3]);

    if (!input.is_open())
    {
        std::cerr << "ERROR: " << argv[2] << " is not open" << '\n';
        return 1;
    }
    else if (!output.is_open())
    {
        std::cerr << "ERROR: " << argv[3] << " is not open" << '\n';
        return 1;
    }

    int rows = 0;
    int cols = 0;
    int result = 0;

    if (!(input >> rows))
    {
        std::cerr << "ERROR: Incorrect number of rows entered" << "\n";
        return 2;
    }
    else if (!(input >> cols))
    {
        std::cerr << "ERROR: Incorrect number of columns entered" << "\n";
        return 2;
    }
    else if (rows < 0 || cols < 0)
    {
        std::cerr << "ERROR: Rows and columns must be non-negative" << "\n";
        return 2;
    }

    if (argv[1][0] == '1')
    {
        if (rows * cols > 1000)
        {
            std::cerr << "ERROR: The array is too large" << "\n";
            return 1;
        }

        int array[10000] = {};

        zinovev::readInput(input, array, rows, cols);

        if (!input)
        {
            return 2;
        }

        input.close();

        result = zinovev::findLongestColumn(array, rows, cols);
        zinovev::fillSpiral(array, rows, cols);
        zinovev::writeOutput(output, array, rows, cols, result);
    }
    else if (argv[1][0] == '2')
    {
        int* array = nullptr;
        try
        {
            array = new int[rows * cols] {};

            zinovev::readInput(input, array, rows, cols);

            if (!input)
            {
                delete[] array;
                return 2;
            }

            input.close();

            result = zinovev::findLongestColumn(array, rows, cols);
            zinovev::fillSpiral(array, rows, cols);
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

void zinovev::fillSpiral(int* array, int rows, int cols)
{
    int number = 1;
    int position = (rows - 1) * cols;

    for (int layer = 0; number <= rows * cols; layer++)
    {
        for (int i = 0; i < (cols - 2 * layer) && number <= rows * cols; i++)
        {
            if (position >= 0 && position < rows * cols)
            {
                array[position] += number;
            }
            position++;
            number++;
        }

        if (number > rows * cols)
        {
            break;
        }

        position -= (cols + 1);

        for (int i = 0; i < (rows - 2 * layer - 1) && number <= rows * cols; i++)
        {
            if (position >= 0 && position < rows * cols)
            {
                array[position] += number;
            }
            position -= cols;
            number++;
        }

        if (number > rows * cols)
        {
            break;
        }

        position += (cols - 1);

        for (int i = 0; i < (cols - 2 * layer - 1) && number <= rows * cols; i++)
        {
            if (position >= 0 && position < rows * cols)
            {
                array[position] += number;
            }
            position--;
            number++;
        }

        if (number > rows * cols)
        {
            break;
        }

        position += (cols + 1);

        for (int i = 0; i < (rows - 2 * layer - 2) && number <= rows * cols; i++)
        {
            if (position >= 0 && position < rows * cols)
            {
                array[position] += number;
            }
            position += cols;
            number++;
        }

        position -= (cols - 1);
    }
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

