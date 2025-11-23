#include "lab.hpp"
#include <iostream>
#include <cstddef>

std::istream & aydogan::readMatrix(std::istream & input, int * arr, int count)
{
  for (int i = 0; i < count; ++i)
  {
    if (!(input >> arr[i]))
    {
      std::cerr << "Incorrect matrix input\n";
      return input;
    }
  }
  return input;
}

int aydogan::numCollSr(int r, int c, const int * a)
{
  if (r <= 0 || c <= 0)
  {
    return 0;
  }

  const std::size_t rows = static_cast<std::size_t> (r);
  const std::size_t cols = static_cast<std::size_t> (c);

  std::size_t bestCol = 1;
  std::size_t bestLen = 0;

  for (std::size_t col = 0; col < cols; ++col)
  {
    std::size_t cur = 1;
    std::size_t maxHere = 1;

    for (std::size_t row = 1; row < rows; ++row)
    {
      int prev = a[(row - 1) * cols + col];
      int now = a[row * cols + col];

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

  return static_cast<int> (bestCol);
}

long long aydogan::minSumMDG(int r, int c, const int * a)
{
  if (r <= 0 || c <= 0)
  {
    return 0;
  }

  const std::size_t rows = static_cast<std::size_t> (r);
  const std::size_t cols = static_cast<std::size_t> (c);
  const std::size_t maxS = (rows - 1) + (cols - 1);

  long long best = 0;
  bool first = true;

  for (std::size_t s = 0; s <= maxS; ++s)
  {
    long long sum = 0;
    bool hasElement = false;

    for (std::size_t i = 0; i < rows; ++i)
    {
      std::size_t j = s - i;
      if (j < cols)
      {
        sum += a[i * cols + j];
        hasElement = true;
      }
    }

    if (hasElement)
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

int aydogan::processMatrix(int r, int c, const int * a, int variant)
{
  if (variant == 1)
  {
    return numCollSr(r, c, a);
  }
  else if (variant == 2)
  {
    long long value = minSumMDG(r, c, a);
    return static_cast<int> (value);
  }

  return 0;
}
