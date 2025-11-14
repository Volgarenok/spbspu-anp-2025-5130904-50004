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
}

int main()
{
}
