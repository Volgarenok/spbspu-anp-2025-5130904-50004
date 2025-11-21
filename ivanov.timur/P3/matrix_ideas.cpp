#include "matrix_ideas.h"
#include <algorithm>
#include <iostream>
#include <fstream>

void ivanov::fll_inc_wav(int* mtr, int rows, int cols)
{
  int lvs = (std::min(rows, cols) + 1) / 2;
  for (int lv = 0; lv < lvs; lv++)
  {
    int inc = lv + 1;
    int* top_row = mtr + lv * cols;
    int* bottom_row = mtr + (rows - lv - 1) * cols;
    for (int j = lv; j < cols - lv; j++)
    {
      top_row[j] += inc;
      bottom_row[j] += inc;
    }
    for (int i = lv + 1; i < rows - lv - 1; i++)
    {
      int* current_row = mtr + i * cols;
      current_row[lv] += inc;
      current_row[cols - lv - 1] += inc;
    }
  }
}
int ivanov::max_sum_mdg(const int* matrix, int rows, int cols)
{
  if (rows == 0 || cols == 0)
  {
    return 0;
  }
  const int size_sums = rows + cols - 1;
  if (size_sums > 10000)
  {
    return 0;
  }
  int sums[10000] = {};
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      const int diagonal_index = i + j;
      sums[diagonal_index] += matrix[i * cols + j];
    }
  }
  const int main_anti_diagonal = rows - 1;
  int max_sum = 0;
  bool found_valid = false;
  for (int s = 0; s < size_sums; s++)
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
bool ivanov::write_in(int* matrix, int rows, int cols, std::ifstream& input, bool is_dynamic) {
  for (int i = 0; i < rows * cols; i++)
  {
    input >> matrix[i];
  }
  if (input.fail() || input.eof())
  {
    std::cerr << "Error: Invalid matrix data" << std::endl;
    if (is_dynamic)
    {
      free(matrix);
    }
    return false;
  }
  return true;
}
