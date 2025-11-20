#include <fstream>
#include <iostream>
#include <cstring>
#include <cstdlib>

namespace em {

bool validate_arguments(int argc, char* argv[])
{
  if (argc != 4)
  {
    std::cerr << "Invalid number of arguments" << std::endl;
    return false;
  }

  char first_char = argv[1][0];
  if (first_char != '1' && first_char != '2')
  {
    std::cerr << "First parameter is out of range or not a number" << std::endl;
    return false;
  }

  return true;
}

int* create_matrix(int rows, int cols)
{
  if (rows <= 0 || cols <= 0)
  {
    return nullptr;
  }
  return new int[rows * cols]();
}

void free_matrix(int* matrix)
{
  delete[] matrix;
}

bool read_matrix(const char* filename, int** matrix, int& rows, int& cols)
{
  rows = 0;
  cols = 0;
  *matrix = nullptr;

  std::ifstream file(filename);
  if (!file.is_open())
  {
    std::cerr << "Cannot open input file: " << filename << std::endl;
    return false;
  }

  if (file.peek() == std::ifstream::traits_type::eof())
  {
    return false;
  }

  file >> rows >> cols;

  if (file.fail())
  {
    return false;
  }

  if (rows < 0 || cols < 0)
  {
    return false;
  }

  if (rows == 0 && cols == 0)
  {
    *matrix = nullptr;
    return true;
  }

  *matrix = create_matrix(rows, cols);
  if (!*matrix)
  {
    return false;
  }

  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < cols; ++j)
    {
      if (!(file >> (*matrix)[i * cols + j]))
      {
        free_matrix(*matrix);
        *matrix = nullptr;
        return false;
      }
    }
  }

  return true;
}

bool write_matrix(const char* filename, const int* matrix, int rows, int cols, bool smooth_matrix = false)
{
  std::ofstream file(filename);
  if (!file.is_open())
  {
    return false;
  }

  file << rows << " " << cols;

  if (rows > 0 && cols > 0)
  {
    for (int i = 0; i < rows; ++i)
    {
      for (int j = 0; j < cols; ++j)
      {
        file << " ";
        if (smooth_matrix)
        {
          int value = matrix[i * cols + j];
          file << value / 10 << "." << abs(value % 10);
        }
        else
        {
          file << matrix[i * cols + j];
        }
      }
    }
  }

  return file.good();
}

void process_left_bottom_clockwise(int* matrix, int rows, int cols)
{
  if (!matrix || rows <= 0 || cols <= 0)
  {
    return;
  }

  int top = 0;
  int bottom = rows - 1;
  int left = 0;
  int right = cols - 1;
  int counter = 1;

  while (top <= bottom && left <= right)
  {
    for (int i = bottom; i >= top; --i)
    {
      matrix[i * cols + left] -= counter;
      counter++;
    }
    left++;
    if (left > right)
    {
      break;
    }

    for (int j = left; j <= right; ++j)
    {
      matrix[top * cols + j] -= counter;
      counter++;
    }
    top++;
    if (top > bottom)
    {
      break;
    }

    for (int i = top; i <= bottom; ++i)
    {
      matrix[i * cols + right] -= counter;
      counter++;
    }
    right--;
    if (left > right)
    {
      break;
    }

    for (int j = right; j >= left; --j)
    {
      matrix[bottom * cols + j] -= counter;
      counter++;
    }
    bottom--;
  }
}

void build_smooth_matrix(int* matrix, int rows, int cols)
{
  if (!matrix || rows <= 0 || cols <= 0)
  {
    return;
  }

  int* temp = create_matrix(rows, cols);
  if (!temp)
  {
    return;
  }

  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < cols; ++j)
    {
      int sum = 0;
      int count = 0;

      for (int di = -1; di <= 1; ++di)
      {
        for (int dj = -1; dj <= 1; ++dj)
        {
          if (di == 0 && dj == 0)
          {
            continue;
          }

          int ni = i + di;
          int nj = j + dj;
          if (ni >= 0 && ni < rows && nj >= 0 && nj < cols)
          {
            sum += matrix[ni * cols + nj];
            count++;
          }
        }
      }

      if (count > 0)
      {
        temp[i * cols + j] = sum * 10 / count;
      }
      else
      {
        temp[i * cols + j] = matrix[i * cols + j] * 10;
      }
    }
  }

  for (int i = 0; i < rows * cols; ++i)
  {
    matrix[i] = temp[i];
  }

  free_matrix(temp);
}

} // namespace em

int main(int argc, char* argv[])
{
  if (!em::validate_arguments(argc, argv))
  {
    return 1;
  }

  int task_number = argv[1][0] - '0';
  const char* input_file = argv[2];
  const char* output_file = argv[3];

  int rows = 0;
  int cols = 0;
  int* matrix = nullptr;

  if (!em::read_matrix(input_file, &matrix, rows, cols))
  {
    std::cerr << "Failed to read matrix from file" << std::endl;
    return 2;
  }

  if (task_number == 1 && rows * cols > 10000)
  {
    std::cerr << "Matrix too large for fixed array (max 10000 elements)" << std::endl;
    em::free_matrix(matrix);
    return 2;
  }

  bool success = true;
  if (rows > 0 && cols > 0)
  {
    em::process_left_bottom_clockwise(matrix, rows, cols);
    success = em::write_matrix(output_file, matrix, rows, cols, false);

    em::build_smooth_matrix(matrix, rows, cols);
    success = success && em::write_matrix(output_file, matrix, rows, cols, true);
  }
  else
  {
    success = em::write_matrix(output_file, matrix, rows, cols, false);
  }

  em::free_matrix(matrix);

  if (success)
  {
    return 0;
  }
  else
  {
    return 2;
  }
}
