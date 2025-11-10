#include <iostream>
#include <fstream>
#include <algorithm>

namespace khairullin
{
  int check_arguments(int argc, char ** argv, int command);
  void filling(int * array, std::ifstream & input, int rows, int cols, int command);
  int localmax(int * array, int rows, int cols);
  int CheckZero(int * array, int index1,int index2, int size);
  bool triangle(int *array, int size);
  void work_with_dinamic(int rows, int cols,std::ifstream & input, std::ofstream & output, int command);
  void work_with_static(int rows, int cols, std::ifstream & input, std::ofstream & output, int command);
}
void khairullin::filling(int * array, std::ifstream & input, int rows, int cols, int command)
{
  for (int i = 0; i < rows * cols; ++i)
  {
    input >> array[i];
    if (input.fail() or input.eof())
    {
      if (command == 2)
      {
        free(array);
      }
      throw std::invalid_argument("Error: file includes the mistake");
    }
  }
  input.close();
}
int khairullin::CheckZero(int * array, int index1, int index2, int size)
{
  if (array[index1 * size + index2] == array[index1 * size + index2 + 1] and array[index1 * size + index2] == 0)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
int khairullin::localmax(int * array, int rows, int cols)
{
  int counter_of_max = 0;
  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < cols; ++j)
    {
      if (i != 0 and j != 0 and i != rows - 1 and j != cols - 1)
      {
        if(array[i*cols + j] > array[(i-1)*cols+j]
            and array[i * cols + j] > array[(i+1)*cols
                + j]  and array[i*cols + j] > array[i *
                    cols + j-1] and array[i*cols + j] >
                        array[i*cols + j+1])
            {
              counter_of_max++;
            }
        }
      }
    }
  return counter_of_max;
}

bool khairullin::triangle(int *array, int size)
{
  int sum_of_zeroes = 0;
  int count_of_nulls_on_row = size - 1;
  int counter = 0;
  const int COUNT_OF_ROWS_WITH_ZEROES = size - 1;
  for (int i = 0; i < COUNT_OF_ROWS_WITH_ZEROES; ++i)
  {
    for (int j = 0; j < size; ++j)
    {
      if (j != size - 1)
      {
        counter += khairullin::CheckZero(array, i, j, size);
      }
    }
    if (count_of_nulls_on_row - 1 == counter)
    {
      sum_of_zeroes++;
      counter = 0;
      count_of_nulls_on_row--;
    }
  }
  return (sum_of_zeroes == COUNT_OF_ROWS_WITH_ZEROES);
}
int khairullin::check_arguments(int argc, char ** argv, int command)
{
  if (argc < 4)
  {
    std::cerr << "Not enough arguments\n";
    return 1;
  }
  else if (argc > 4)
  {
    std::cerr << "Too many arguments\n";
    return 1;
  }
  else if (argv[1][1] != '\0')
  {
    std::cerr << "First parameter is not a number\n";
    return 1;
  }
  else if (command > 2 or command < 1)
  {
    std::cerr << "First parameter is out of range\n";
    return 1;
  }
  else if (command == 1 or command == 2)
  {
    return 0;
  }
  return 0;
}
void khairullin::work_with_static(int rows, int cols, std::ifstream & input, std::ofstream & output, int command)
{
  int array[10000] = {};
  khairullin::filling(array, input, rows, cols, command);
  output << khairullin::localmax(array, rows, cols) << "\n";
  int square_array[10000] = {};
  const int MIN_SIZE = std::min(rows, cols);
  const int MAX_SIZE = std::max(rows, cols);
  for (int i = 0; i < MIN_SIZE; ++i)
  {
    for(int j = 0; j < MIN_SIZE; ++j)
    {
      square_array[i * MIN_SIZE + j] = array[i * MAX_SIZE + j];
    }
  }
  if (khairullin::triangle(square_array, MIN_SIZE))
  {
    output << "True\n";
  }
  else
  {
    output << "False\n";
  }
}
void khairullin::work_with_dinamic(int rows, int cols, std::ifstream & input, std::ofstream & output, int command)
{
  int * array = reinterpret_cast<int *> (std::malloc(rows * cols * sizeof(int)));
  if (array == nullptr)
  {
    throw std::bad_alloc();
  }
  khairullin::filling(array, input, rows, cols, command);
  output << khairullin::localmax(array, rows, cols) << "\n";
  const int MIN_SIZE = std::min(rows, cols);
  const int MAX_SIZE = std::max(rows, cols);
  int * square_array = reinterpret_cast<int *>(std::malloc(MIN_SIZE * MIN_SIZE * sizeof(int)));
  if (square_array == nullptr)
  {
    throw std::bad_alloc();
  }
  for (int i = 0; i < MIN_SIZE; i++)
  {
    for (int j = 0; j < MIN_SIZE; ++j)
    {
      square_array[MIN_SIZE * i + j] = array[MAX_SIZE * i + j];
    }
  }
  free(array);
  if (khairullin::triangle(square_array, MIN_SIZE))
  {
    output << "True\n";
  }
  else
  {
    output << "False\n";
  }
  free(square_array);
}
int main (int argc, char ** argv)
{
  int command = 0;
  if (argc != 1)
  {
    command = argv[1][0] - '0';
  }
  else
  {
    std::cerr << "No arguments\n";
    return 1;
  }
  namespace khair = khairullin;
  try
  {
    if (khair::check_arguments(argc, argv, command))
    {
      return 1;
    }
    std::ifstream input(argv[2]);
    std::ofstream output(argv[3]);
    int rows = 0, cols = 0;
    input >> rows >> cols;
    if (!input)
    {
      throw std::logic_error("File is empty");
    }
    else if ((rows == 0 and cols != 0) || (rows != 0 and cols == 0) || (rows < 0 or cols < 0))
    {
      throw std::runtime_error("Invalid rows or columns");
    }
    else if (rows != 0 and cols != 0)
    {
      if (argv[1][0] == '1')
      {
        khair::work_with_static(rows, cols, input, output, command);
      }
      else if (argv[1][0] == '2')
      {
        khair::work_with_dinamic(rows, cols, input, output, command);
      }
    }
    else if (rows == 0 and cols == 0)
    {
      output << "Count of local maximums - 0\n";
      output << "False\n";
    }
  }
  catch (const std::runtime_error & err)
  {
    std::cerr << "ERROR: " << err.what() << "\n";
    return 2;
  }
  catch(const std::invalid_argument & msg)
  {
    std::cerr << "ERROR: " << msg.what() << "\n";
    return 2;
  }
  catch(const std::bad_alloc & e)
  {
    std::cerr << "ERROR: " << e.what() << "\n";
    return 2;
  }
  catch (std::logic_error & exc)
  {
    std::cerr << "ERROR: " << exc.what() << "\n";
    return 2;
  }
  catch(...)
  {
    std::cerr << "Error\n";
    return 2;
  }
}
