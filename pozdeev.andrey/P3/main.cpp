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
}

int main()
{
}
