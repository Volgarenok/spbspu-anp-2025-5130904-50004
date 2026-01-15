#include "matrix.hpp"
#include <istream>
#include <cstddef>

std::istream& aydogan::readMatrix(std::istream& input, int* arr, size_t count)
{
  for (size_t i = 0; i < count; ++i)
  {
    input >> arr[i];
  }
  return input;
}

int aydogan::numColLsr(size_t r, size_t c, const int* a)
{
  if (r == 0 || c == 0)
  {
    return 0;
  }

  size_t bestCol = 1;
  size_t bestLen = 0;

  for (size_t col = 0; col < c; ++col)
  {
    size_t cur = 1;
    size_t maxHere = 1;

    for (size_t row = 1; row < r; ++row)
    {
      int prev = a[(row - 1) * c + col];
      int now  = a[row * c + col];

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

long long aydogan::minSumMDG(size_t r, size_t c, const int* a)
{
  if (r == 0 || c == 0)
  {
    return 0;
  }

  long long best = 0;
  bool first = true;

  for (size_t s = 0; s <= (r - 1) + (c - 1); ++s)
  {
    long long sum = 0;
    bool has = false;

    for (size_t i = 0; i < r; ++i)
    {
      long long jll = static_cast< long long >(s) - static_cast< long long >(i);
      if (jll >= 0 && static_cast< size_t >(jll) < c)
      {
        size_t j = static_cast< size_t >(jll);
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
