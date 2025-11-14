#include <iostream>
#include <fstream>

namespace pozdeev
{
    const int MAX_SIZE = 10000;

    int countNonSequentialRows(const int* matrix, int rows, int cols)
    {
        if (rows <= 0 || cols <= 0)
        {
            return 0;
        }

        int rowsWithoutConsecutive = 0;
        
        for (int r = 0; r < rows; ++r)
        {
            bool hasConsecutive = false;
            for (int c = 0; c < cols - 1; ++c)
            {
                int idx1 = r * cols + c;
                int idx2 = r * cols + c + 1;
                
                if (matrix[idx1] == matrix[idx2])
                {
                    hasConsecutive = true;
                    break; 
                }
            }
            if (!hasConsecutive)
            {
                rowsWithoutConsecutive++;
            }
        }
        return rowsWithoutConsecutive;
    }

    void spiral(int* matrix, int rows, int cols)
    {
        if (rows <= 0 || cols <= 0)
        {
            return;
        }

        int top = 0, bottom = rows - 1;
        int left = 0, right = cols - 1;
        int decrement = 1; 

        while (top <= bottom && left <= right)
        {
            for (int r = bottom; r >= top; --r)
            {
                matrix[r * cols + left] -= decrement;
                decrement++;
            }
            if (++left > right)
            {
                break;
            }

            for (int c = left; c <= right; ++c)
            {
                matrix[top * cols + c] -= decrement;
                decrement++;
            }
            if (++top > bottom)
            {
                break;
            }

            for (int r = top; r <= bottom; ++r)
            {
                matrix[r * cols + right] -= decrement;
                decrement++;
            }
            if (--right < left)
            {
                break;
            }

            for (int c = right; c >= left; --c)
            {
                matrix[bottom * cols + c] -= decrement;
                decrement++;
            }
            --bottom; 
        }
    }

    int numAnalysis(const char* s, int& outVal)
    {
        if (s == nullptr || s[0] == '\0')
        {
            return 1;
        }
        
        if (s[0] == '1' && s[1] == '\0')
        {
            outVal = 1;
            return 0; 
        }
        if (s[0] == '2' && s[1] == '\0')
        {
            outVal = 2;
            return 0; 
        }
        
        for (int i = 0; s[i] != '\0'; ++i)
        {
            if (s[i] < '0' || s[i] > '9')
            {
                return 1;
            }
        }
        
        return 2;
    }

    int processStatic(std::ifstream& fin, std::ofstream& fout, int rows, int cols)
    {
        int numElements = rows * cols;

        if (numElements > MAX_SIZE)
        {
            std::cerr << "ERROR: Matrix too large for static array\n";
            return 2;
        }

        int staticMatrix[MAX_SIZE];

        if (numElements == 0)
        {
            fout << "0";
            return 0;
        }

        for (int i = 0; i < numElements; ++i)
        {
            if (!(fin >> staticMatrix[i]))
            {
                if (fin.eof())
                {
                    std::cerr << "ERROR: Not enough matrix elements\n";
                }
                else
                {
                    std::cerr << "ERROR: Invalid matrix element\n";
                }
                return 2;
            }
        }

        fout << countNonSequentialRows(staticMatrix, rows, cols);
        return 0;
    }

    int processDynamic(std::ifstream& fin, std::ofstream& fout, int rows, int cols)
    {
        int numElements = rows * cols;

        if (rows == 0 || cols == 0)
        {
            fout << "0 0";
            return 0;
        }

        int* dynamicMatrix = new (std::nothrow) int[numElements];
        if (dynamicMatrix == nullptr)
        {
            std::cerr << "ERROR: Memory not allocated for array\n";
            return 2;
        }

        for (int i = 0; i < numElements; ++i)
        {
            if (!(fin >> dynamicMatrix[i]))
            {
                if (fin.eof())
                {
                    std::cerr << "ERROR: Not enough matrix elements\n";
                }
                else
                {
                    std::cerr << "ERROR: Invalid matrix element\n";
                }
                delete[] dynamicMatrix;
                return 2;
            }
        }
        
        spiral(dynamicMatrix, rows, cols);

        fout << rows << " " << cols;
        for (int i = 0; i < numElements; ++i)
        {
            fout << " " << dynamicMatrix[i];
        }

        delete[] dynamicMatrix;
        return 0;
    }
}

int main(int argc, char* argv[])
{
    int exit = 0;

    if (argc != 4)
    {
        const char* errorMessage;

        if (argc < 4)
        {
            errorMessage = "Not enough arguments";
        }
        else
        {
            errorMessage = "Too many arguments";
        }
        
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
}
