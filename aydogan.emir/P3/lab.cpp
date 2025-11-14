#include <iostream>

namespace aydogan {


std::istream& readStatic(std::istream& input, int* arr, int r, int c)
{
    for (int i = 0; i < r * c; ++i)
    {
        if (!(input >> arr[i]))
        {
            std::cerr << "Incorrect matrix input\n";
            return input;
        }
    }
    return input;
}


std::istream& readDynamic(std::istream& input, int* arr, int r, int c)
{
    for (int i = 0; i < r * c; ++i)
    {
        if (!(input >> arr[i]))
        {
            std::cerr << "Incorrect matrix input\n";
            return input;
        }
    }
    return input;
}


int numColLsr(int r, int c, const int* a)
{
    if (r <= 0 || c <= 0) return 0;

    int bestLen = 0;
    int bestCol = 1;

    for (int col = 0; col < c; ++col)
    {
        int cur = 1;
        int maxHere = 1;

        for (int row = 1; row < r; ++row)
        {
            int prev = a[(row - 1) * c + col];
            int now  = a[row * c + col];

            if (now == prev)
            {
                ++cur;
                if (cur > maxHere)
                    maxHere = cur;
            }
            else
            {
                cur = 1;
            }
        }

        if (maxHere > bestLen)
        {
            bestLen = maxHere;
            bestCol = col + 1;
        }
    }

    return bestCol;
}

long long minSumMDG(int r, int c, const int* a)
{
    if (r <= 0 || c <= 0) return 0;

    long long best = 0;
    bool first = true;

    
    for (int s = 0; s <= (r - 1) + (c - 1); ++s)
    {
        long long sum = 0;

        for (int i = 0; i < r; ++i)
        {
            int j = s - i;
            if (j >= 0 && j < c)
                sum += a[i * c + j];
        }

        if (first)
        {
            best = sum;
            first = false;
        }
        else if (sum < best)
        {
            best = sum;
        }
    }

    return best;
}

int main()
{
    return 0;
}

} 
