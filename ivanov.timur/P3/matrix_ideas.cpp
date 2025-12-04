#include "matrix_ideas.h"
#include <algorithm>
#include <iostream>
#include <fstream>

void ivanov::fll_inc_wav(int* mtr, size_t rows, size_t cols)
{
  size_t lvs = (std::min(rows, cols) + 1) / 2;
  for (size_t lv = 0; lv < lvs; lv++)
  {
    size_t inc = lv + 1;
    int* top_row = mtr + lv * cols;
    int* bottom_row = mtr + (rows - lv - 1) * cols;
    for (size_t j = lv; j < cols - lv; j++)
    {
      top_row[j] += inc;
      bottom_row[j] += inc;
    }
    for (size_t i = lv + 1; i < rows - lv - 1; i++)
    {
      int* current_row = mtr + i * cols;
      current_row[lv] += inc;
      current_row[cols - lv - 1] += inc;
    }
  }
}
int ivanov::max_sum_mdg(const int* matrix, size_t rows, size_t cols)
{
  size_t size_sums = rows + cols - 1;
  if (size_sums > 10000)
  {
    return 0;
  }
  size_t sums[10000] = {};
  for (size_t i = 0; i < rows; i++)
  {
    for (size_t j = 0; j < cols; j++)
    {
      size_t diagonal_index = i + j;
      sums[diagonal_index] += matrix[i * cols + j];
    }
  }
  size_t main_anti_diagonal = rows - 1;
  size_t max_sum = 0;
  bool found_valid = false;
  for (size_t s = 0; s < size_sums; s++)
  {
    if (s == main_anti_diagonal)
    {
      continue;
    }
    if (!found_valid || sums[s] > max_sum)
    {
      max_sum = sums[s];
      found_valid = true;
    }
  }
  return found_valid ? max_sum : 0;
}
void ivanov::write_in(int* matrix, size_t rows, size_t cols, std::ifstream& input)
{
  for (size_t i = 0; i < rows * cols; i++)
  {
    input >> matrix[i];
  }
}
