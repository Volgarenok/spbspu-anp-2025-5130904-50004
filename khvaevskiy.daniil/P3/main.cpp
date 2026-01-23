#include <iostream>
#include <fstream>
#include <cstdlib>
#include "func.h"

int main (int argc, char* argv[])
{
  if (argc != 4)
  {
    std::cerr << "Usage: " << argv[0] << " num input output\n";
    return 1;
  }


  if (argv[1][0] != '1' && argv[1][0] != '2')
  {
    std::cerr << "First parameter is out of range\n";
    return 1;
  }
  if (argv[1][1] != '\0')
  {
    std::cerr << "First parameter is not a number\n";
    return 1;
  }

  char* input_filename = argv[2];
  char* output_filename = argv[3];

  int rows, cols;
  int* matrix = nullptr;
  bool is_fixed = (argv[1][0] == '1');

  std::ifstream infile (input_filename);
  if (!infile.is_open ())
  {
    std::cerr << "Error reading matrix from file\n";
    return 2;
  }

  std::ofstream outfile (output_filename);
  if (!outfile.is_open ())
  {
    infile.close ();
    return 2;
  }

  if (is_fixed)
  {
    int fixed_matrix[10000];
    if (!Khvaevskii::readMatrixFixed (infile, fixed_matrix, 100, 100))
    {
      infile.close ();
      outfile.close ();
      std::cerr << "Error reading matrix from file\n";
      return 2;
    }

    infile.close ();
    infile.open (input_filename);
    long long temp_rows, temp_cols;
    if (!(infile >> temp_rows >> temp_cols))
    {
      infile.close ();
      outfile.close ();
      std::cerr << "Error reading matrix dimensions from file\n";
      return 2;
    }
    rows = static_cast<int> (temp_rows);
    cols = static_cast<int> (temp_cols);
    if (rows < 0 || cols < 0 || rows > 100 || cols > 100)
    {
      infile.close ();
      outfile.close ();
      std::cerr << "Invalid matrix dimensions\n";
      return 2;
    }

    infile.close ();
    infile.open (input_filename);
    infile >> temp_rows >> temp_cols;
    for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < cols; j++)
      {
        long long temp_val;
        if (!(infile >> temp_val))
        {
          infile.close ();
          outfile.close ();
          std::cerr << "Error reading matrix elements from file\n";
          return 2;
        }
        if (!Khvaevskii::isValidNumber (temp_val))
        {
          infile.close ();
          outfile.close ();
          std::cerr << "Invalid matrix element\n";
          return 2;
        }
        fixed_matrix[i * cols + j] = static_cast<int> (temp_val);
      }
    }
    matrix = fixed_matrix;

    long long result = Khvaevskii::maxSumDiagonal (matrix, rows, cols);
    outfile << result << "\n";
  }
  else
  {
    matrix = Khvaevskii::readMatrixDynamic (infile, rows, cols);
    if (!matrix)
    {
      infile.close ();
      outfile.close ();
      std::cerr << "Error reading matrix from file\n";
      return 2;
    }

    int result = Khvaevskii::countSaddlePoints (matrix, rows, cols);
    outfile << result << "\n";

    Khvaevskii::freeMatrix (matrix);
  }

  infile.close ();
  outfile.close ();

  return 0;
}
