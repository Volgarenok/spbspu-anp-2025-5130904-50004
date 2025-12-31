#include "matrix.hpp"
#include <istream>
#include <cstddef>

std::istream& aydogan::readMatrix(std::istream& input, int* arr, std::size_t count)
{
  for (std::size_t i = 0; i < count; ++i)
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

  std::size_t rr = static_cast< std::size_t >(r);
  std::size_t cc = static_cast< std::size_t >(c);

  std::size_t bestCol = 1;
  std::size_t bestLen = 0;

  for (std::size_t col = 0; col < cc; ++col)
  {
    std::size_t cur = 1;
    std::size_t maxHere = 1;

    for (std::size_t row = 1; row < rr; ++row)
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

  std::size_t rr = static_cast< std::size_t >(r);
  std::size_t cc = static_cast< std::size_t >(c);

  long long best = 0;
  bool first = true;

  for (std::size_t s = 0; s <= (rr - 1) + (cc - 1); ++s)
  {
    long long sum = 0;
    bool has = false;

    for (std::size_t i = 0; i < rr; ++i)
    {
      long long jll = static_cast< long long >(s) - static_cast< long long >(i);
      if (jll >= 0 && static_cast< std::size_t >(jll) < cc)
      {
        std::size_t j = static_cast< std::size_t >(jll);
        sum += a[i * cc + j];
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
