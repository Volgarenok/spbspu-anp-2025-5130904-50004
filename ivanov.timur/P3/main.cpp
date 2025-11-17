#include<fstream>
#include<iostream>

namespace ivanov
{
  void fll_inc_wav(int* mtr, int rows, int cols);
  int max_sum_mdg(int* matrix, int rows, int cols);
}

int main(int argc, char ** argv)
{
  if (argc != 4)
  {
    std::cerr << "Error: Incorrect number of arguments" << std::endl;
    return 1;
  }

  std::ifstream input(argv[2]);
  std::ofstream output(argv[3]);
  if (!output.is_open())
  {
    std::cerr << "Error: Cannot open output file." << std::endl;
    return 2;
  }
  char num = argv[1][0];
  if ((num != '1' && num != '2') || std::cin.fail())
  {
    std::cerr << "Error: Wrong question" << std::endl;
    return 1;
  }
  if (!input.is_open())
  {
    std::cerr << "Error: Cannot open input file" << std::endl;
    return 1;
  }
  int rows, cols;
  input >> rows >> cols;
  if (input.fail())
  {
    std::cerr << "Error: Input fail" << std::endl;
    return 1;
  }
  if (rows == 0 || cols == 0)
  {
    output << 0;
    return 0;
  }
  if (rows <= 0 || cols <= 0)
  {
    std::cerr << "Error: Invalid matrix dimensions" << std::endl;
    return 1;
  }
  if (num == '1' && rows * cols > 10000)
  {
    std::cerr << "Error: Matrix too large for static array" << std::endl;
    return 1;
  }
  if (num == '1')
  {
    int matrix[10000];
    for (int i = 0; i < rows * cols; i++)
    {
      input >> matrix[i];
    }
    if (input.fail())
    {
      std::cerr << "Error: Invalid matrix data" << std::endl;
      return 2;
    }
    ivanov::fll_inc_wav(matrix, rows, cols);
    int result = ivanov::max_sum_mdg(matrix, rows, cols);
    output << result << std::endl;
  }
  else {
    int* matrix = static_cast< int * >(malloc(sizeof(int) * rows * cols));
    if (matrix == nullptr)
    {
      std::cerr << "Error: Memory allocation failed" << std::endl;
      return 2;
    }
    for (int i = 0; i < rows * cols; i++)
    {
      input >> matrix[i];
      if (input.fail())
      {
        std::cerr << "Error: Invalid matrix data" << std::endl;
        free(matrix);
        return 2;
      }
    }
    ivanov::fll_inc_wav(matrix, rows, cols);
    int result = ivanov::max_sum_mdg(matrix, rows, cols);
    output << result << std::endl;
    free(matrix);
  }
}
    ivanov::fll_inc_wav(matrix, rows, cols);
    int result = ivanov::max_sum_mdg(matrix, rows, cols);
    output << result << std::endl;
    free(matrix);
  }
  return 0;
}

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

int ivanov::max_sum_mdg(int* matrix, int rows, int cols)
{
  if (rows == 0 || cols == 0)
  {
    return 0;
  }
  const int size_sums = rows + cols - 1;

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
