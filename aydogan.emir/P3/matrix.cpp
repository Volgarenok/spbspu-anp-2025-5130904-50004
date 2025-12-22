#include "matrix.hpp"
#include <istream>
#include <cstddef>

std::istream& aydogan::readMatrix(std::istream& input, int* arr, int count)
{
  for (int i = 0; i < count; ++i)
  {
    input >> arr[i];
  }
  return input;
}

int aydogan::numColLsr(int r, int c, const int* a)
{
  if (r <= 0 || c <= 0)
  {
    return 0;
  }

  size_t rr = static_cast< size_t >(r);
  size_t cc = static_cast< size_t >(c);

  size_t bestCol = 1;
  size_t bestLen = 0;

  for (size_t col = 0; col < cc; ++col)
  {
    size_t cur = 1;
    size_t maxHere = 1;

    for (size_t row = 1; row < rr; ++row)
    {
      int prev = a[(row - 1) * cc + col];
      int now  = a[row * cc + col];

      if (now == prev)
      {
        ++cur;
        if (cur > maxHere)
        {
          maxHere = cur;
        }
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

  return static_cast< int >(bestCol);
}

long long aydogan::minSumMDG(int r, int c, const int* a)
{
  if (r <= 0 || c <= 0)
  {
    return 0;
  }

  long long best = 0;
  bool first = true;

  for (int s = 0; s <= (r - 1) + (c - 1); ++s)
  {
    long long sum = 0;
    bool has = false;

    for (int i = 0; i < r; ++i)
    {
      int j = s - i;
      if (j >= 0 && j < c)
      {
        sum += a[i * c + j];
        has = true;
      }
    }

    if (has)
    {
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
  }

  return best;
}
