#include<fstream>
#include<iostream>

namespace ivanov
{
  void fll_inc_wav(int mtr[], int rows, int cols);
  void fll_inc_wav(int** mtr, int rows, int cols);
  int max_sum_mdg(int matrix[], int rows, int cols) const;
  int max_sum_mdg(int** matrix, int rows, int cols) const;
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
    int** matrix = static_cast< int ** >(malloc(sizeof(int*) * cols));
    if (matrix == nullptr)
    {
      std::cerr << "Error: Memory segmentaion" << std::endl;
      return 2;
    }
    for (int i = 0; i < rows; i++)
    {
      matrix[i] = static_cast< int * >(malloc(sizeof(int) * cols));
      if (matrix[i] == nullptr)
      {
        std::cerr << "Error: Memory segmentaion" << std::endl;
        for (int j = 0; j <= i; j++)
        {
          free(matrix[j]);
        }
        free(matrix);
        return 2;
      }
    }
    for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < cols; j++)
      {
        input >> matrix[i][j];
        if (input.fail())
        {
          std::cerr << "Error: Invalid matrix data" << std::endl;
          for (int k = 0; k <= i; k++)
          {
            free(matrix[k]);
          }
          free(matrix);
          return 2;
        }
      }
    }
    ivanov::fll_inc_wav(matrix, rows, cols);
    int result = ivanov::max_sum_mdg(matrix, rows, cols);
    output << result << std::endl;
    for (int i = 0; i < rows; i++)
    {
      free(matrix[i]);
    }
    free(matrix);
  }
  return 0;
}

void ivanov::fll_inc_wav(int mtr[], int rows, int cols)
{
  int lvs = (std::min(rows, cols) + 1) / 2;
  for (int lv = 0; lv < lvs; lv++)
  {
    int inc = lv + 1;
    for (int j = lv; j < cols - lv; j++)
    {
      mtr[lv * cols + j] += inc;
    }
    for (int j = lv; j < cols - lv; j++)
    {
      mtr[(rows - lv - 1) * cols + j] += inc;
    }
    for (int i = lv + 1; i < rows - lv - 1; i++)
    {
      mtr[i * cols + lv] += inc;
    }
    for (int i = lv + 1; i < rows - lv - 1; i++)
    {
      mtr[i * cols + (cols - lv - 1)] += inc;
    }
  }
}
void ivanov::fll_inc_wav(int** mtr, int rows, int cols)
{
  int lvs = (std::min(rows, cols) + 1) / 2;
  for (int lv = 0; lv < lvs; lv++)
  {
    int inc = lv + 1;
    for (int j = lv; j < cols - lv; j++)
    {
      mtr[lv][j] += inc;
    }
    for (int j = lv; j < cols - lv; j++)
    {
      mtr[rows - lv - 1][j] += inc;
    }
    for (int i = lv + 1; i < rows - lv - 1; i++)
    {
      mtr[i][lv] += inc;
    }
    for (int i = lv + 1; i < rows - lv - 1; i++)
    {
      mtr[i][cols - lv - 1] += inc;
    }
  }
}

int ivanov::max_sum_mdg(int matrix[], int rows, int cols)
{
  if (rows == 0 || cols == 0)
  {
    return 0;
  }
  int size_sums = rows + cols - 1;
  int* sums = new int[size_sums]();
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      int s = i + j;
      sums[s] += matrix[i * cols + j];
    }
  }
  int main_anti = rows - 1;
  int max_sum = 0;
  for (int s = 0; s < size_sums; s++)
  {
    if (s == main_anti)
    {
      continue;
    }
    if (sums[s] > max_sum)
    {
      max_sum = sums[s];
    }
  }
  delete[] sums;
  return max_sum;
}
int ivanov::max_sum_mdg(int** matrix, int rows, int cols)
{
  if (rows == 0 || cols == 0)
  {
    return 0;
  }
  int size_sums = rows + cols - 1;
  int* sums = new int[size_sums]();
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      int s = i + j;
      sums[s] += matrix[i][j];
    }
  }
  int main_anti = rows - 1;
  int max_sum = 0;
  for (int s = 0; s < size_sums; s++)
  {
    if (s == main_anti)
    {
      continue;
    }
    if (sums[s] > max_sum)
    {
      max_sum = sums[s];
    }
  }
  delete[] sums;
  return max_sum;
}
