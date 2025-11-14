#include <iostream>
#include <fstream>

bool ifNumber (char ** m) {
	size_t k = 0;
	size_t k1 = 0;
	for (size_t i = 0; m[1][i]!='\0'; ++i) {
		for (size_t j = 0; j < 10; j++) {
			char tmp;
		  tmp = j;
			if (m[1][i] == tmp + '0') {
				++k;
			}
		}
		++k1;
	}
	if (k==k1) {
			return true;
	}
	return false;
}

int * create (size_t rows, size_t cols)
{
  int * result = nullptr;
  try {
    result = new int [rows*cols];
  }
	catch (...) {
		throw "Not enough memory";
	}
	return result;
}

std::ifstream& inputMatrix (std::ifstream& in, int * m, size_t rows, size_t cols) {
	for (size_t i = 0; i < rows; ++i) {
		for (size_t j = 0; j < cols; ++j) {
			in >> m[i*cols+j];
			if (!in) {
				throw "Wrong matrix input";
		  }
	  }
  }
	return in;
}

size_t CNT_COL_NSM (int * m, size_t rows, size_t cols) {
  size_t count = 0;
  for (size_t j = 0; j < cols; ++j) {
    size_t countcol = 0;
    for (size_t i = 0; i < rows-1; ++i) {
      if (m[i*cols+j]==m[i*cols+j+cols]) {
        ++countcol;
      }
    }
    if (countcol==0) {
      ++count;
    }
  }
  return count;
 }

void cut_to_square_DYNAMIC(int*& m, size_t& rows, size_t& cols) {
    if (rows > cols) {
        int* tmp = create(cols, cols);
        for (size_t i = 0; i < cols; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                tmp[i * cols + j] = m[i * cols + j];
            }
        }
        delete[] m;
        m = tmp;
        rows = cols;
    }
    if (rows < cols) {
        int* tmp = create(rows, rows);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < rows; ++j) {
                tmp[i * rows + j] = m[i * cols + j];
            }
        }
        delete[] m;
        m = tmp;
        cols = rows;
    }
}

void cut_to_square_FIXED(size_t& rows, size_t& cols) {
    if (rows > cols) {
        rows = cols;
    }
    if (rows < cols) {
        cols = rows;
    }
}

size_t CNT_NZR_DIG_DYNAMIC(int*& m, size_t& rows, size_t& cols) {
    cut_to_square_DYNAMIC(m, rows, cols);
    size_t count = 0;
    int k = -int(rows) + 1;
    while (k < int(rows)) {
        size_t countdiag = 0;
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; j++) {
                if (i == j) {
                    if ((int(i * cols + j) + k >= 0) && (int(i * cols + j)+ k < int(rows * cols))) {
                        if (m[i * cols + j + k] == 0) {
                            ++countdiag;
                        }
                    }
                }
            }
        }
        if (countdiag == 0 && k!=0) {
            ++count;
        }
        ++k;
    }
    return count;
}

size_t CNT_NZR_DIG_FIXED(int* m, size_t& rows, size_t& cols) {
    cut_to_square_FIXED(rows, cols);
    size_t count = 0;
    int k = -int(rows) + 1;
    while (k < int(rows)) {
        size_t countdiag = 0;
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; j++) {
                if (i == j) {
                    if ((int(i * cols + j) + k >= 0) && (int(i * cols + j)+ k < int(rows * cols))) {
                        if (m[i * cols + j + k] == 0) {
                            ++countdiag;
                        }
                    }
                }
            }
        }
        if (countdiag == 0 && k!=0) {
            ++count;
        }
        ++k;
    }
    return count;
}

int main(int argc, char ** argv)
{
	if (argc > 4) {
		std::cerr << "Too many arguments" << "\n";
		return 1;
	}
	else if (argc < 4) {
		std::cerr << "Not enough arguments" << "\n";
    return 1;
	}
	if (argc == 4) {
		size_t rows = 0;
		size_t cols = 0;
		std::ifstream input(argv[2]);
		input >> rows >> cols;
		if (!input) {
			std::cerr << "Wrong matrix input" << "\n";
      return 2;
		}
		char num = argv[1][0];
		if (num == '1') {
		  int fixedmatrix[10000];
      try {
        inputMatrix (input, fixedmatrix, rows, cols);
      }
      catch (const char* e) {
        std::cerr << e << "\n";
        return 2;
      }
      input.close();
      std::ofstream output(argv[3]);
      output << CNT_COL_NSM (fixedmatrix, rows, cols) << "\n";
      output << CNT_NZR_DIG_FIXED(fixedmatrix, rows, cols) << "\n";
      output.close();
		}
		else if (num == '2') {
      int * dynamicmatrix = nullptr;
      try {
			  dynamicmatrix = create (rows, cols);
      }
      catch (const char* e) {
        std::cerr << e << "\n";
        return 2;
      }
      try {
        inputMatrix (input, dynamicmatrix, rows, cols);
			  input.close();
        std::ofstream output(argv[3]);
        output << CNT_COL_NSM (dynamicmatrix, rows, cols) << "\n"; 
        output << CNT_NZR_DIG_DYNAMIC(dynamicmatrix, rows, cols) << "\n";
			  delete[] dynamicmatrix;
      }
      catch (const char* e) {
        std::cerr << e << "\n";
        delete[] dynamicmatrix;
        return 2;
      }
    }
	}
	else {
		if (ifNumber (argv) == 1) {
				std::cerr << "First parameter is out of range" << "\n";
				return 1;
		}
		if (ifNumber (argv) == 0) {
				std::cerr << "First parameter is not a number" << "\n";
				return 1;
		}
	}
}