#include <iostream>
#include <fstream>
#include <algorithm>

void filling(int * array, std::ifstream &
  input, int rows, int cols, int command)
{
  for (int i = 0; i < rows * cols; ++i)
  {
    input >> array[i];
    if (std::cin.fail() or std::cin.eof())
    {
      if (command == 2)
      {
        free(array);
      }
      throw std::invalid_argument("Error:
        file includes the mistake");
    }
  }
  input.close();
}

int localmax(int * array, int rows, int cols)
{
   int CounterOfMax = 0;
     for (int i = 0; i < rows; ++i){
       for (int j = 0; j < cols; ++j){
         if (i != 0 and j != 0 and i != rows - 1
           and j != cols - 1){
             if(array[i*cols + j] > array[(i-1)*cols+j]
               and array[i * cols + j] > array[(i+1)*cols 
                 + j]  and array[i*cols + j] > array[i * 
                   cols + j-1] and array[i*cols + j] > 
                     array[i*cols + j+1])
                     {
                       CounterOfMax++;
                     }
                   } 
                 }
               }
  return CounterOfMax;
}

bool triangle(int *array, int size)
{
    int SumOfZeroes = 0;
    int CountOfNullsOnRow = size - 1;
    int counter = 0;
    const int COUNT_OF_ROWS_WITH_ZEROES = size - 1;
    for ( int i = 0; i < COUNT_OF_ROWS_WITH_ZEROES; ++i)
    {
        for ( int j = 0; j < size; ++j)
        {
            if (j != size - 1)
            {
                counter += CheckZero(array, i, j, size);
            }
            
        }
        if (CountOfNullsOnRow - 1 == counter)
        {
            SumOfZeroes++;
            counter = 0;
            CountOfNullsOnRow--;
        }
      
    }
    return (SumOfZeroes == COUNT_OF_ROWS_WITH_ZEROES);
}

int check_arguments(int argc, char ** argv, int command)
{
  if (argc < 4)
  {
    std::cerr << "Not enough arguments";
    return 1;
  }
  else if (argc > 4)
  {
    std::cerr << "Too many arguments";
    return 1;
  }
  else if (argv[1][1] != '\0')
  {
    std::cerr << "First parameter is not a number";
    return 1;
  }
  else if (command > 2 or command < 1)
  {
    std::cerr << "First parameter is out of range";
    return 1;
  }
  else if (command == 1 or command == 2)
  {
    return 0;
  }
  return 0;
}

void work_with_static(int rows, int cols,
  std::ifstream & input, std::ofstream & 
    output, int command)
{
  int array[10000] = {};
  filling(array, input, rows, cols, command);
  output << localmax(array, rows, cols) << "\n";
  int square_array[10000] = {};
  const int MIN_SIZE = std::min(rows, cols);
  const int MAX_SIZE = std::max(rows, cols);
  for (int i = 0; i < MIN_SIZE; ++i)
  {
    for(int j = 0; j < MIN_SIZE; ++j)
    {
      square_array[i * MIN_SIZE + j] = 
        array[i * MAX_SIZE + j];
    }
  } 
}

void worl_with_dinamic(int rows, int cols,
  std::ifstream & input, std::ofstream & 
    output, int command)
{
  int * array = reinterpret_cast<int *> 
    (std::malloc(rows * cols *
      sizeof(int)));
  if (array == nullptr)
  {
    throw std::bad_alloc();
  }
  filling(array, input, rows, cols, command);
  output << localmax(array rows, cols) << "\n";
  int * square_array = reinterpret_cast<int *>
    (std::malloc(MIN_SIZE * MIN_SIZE * sizeof(int)));
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
}

int main (int argc, char ** argv)
{
  int rows = 0, cols = 0;
  int command = argv[1][0] - '0';
  std::ifstream input(argv[2]);
  std::ofstream output(argv[3]);
  input >> rows >> cols;
  if (check_arguments(argc, argv))
  {
    return 1;
  }
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
        work_with_static(rows, cols, input, output, command);        
      }
    else if (argv[1][0] == '2')
      {
        work_with_dinamic(rows, cols, input, output, command);
      }
  }
  else if (rows == 0 and cols == 0)
  {
    output << "Count of local maximums - 0\n";
    output << "False\n";
  }
}
