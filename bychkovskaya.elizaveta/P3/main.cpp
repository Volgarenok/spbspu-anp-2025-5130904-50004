#include <iostream>
#include <fstream>

//проверить, является ли первый параметр кмд числом
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

int main(int argc, char ** argv)
{
	if (argc > 4) {
		std::cerr << "Too many arguments" << "\n";
		return 1;
	}
	else if (argc < 4) {
		std::cerr << "Not enough arguments" << "\n";
	}
	if (argc == 4) {
		size_t rows = 0;
		size_t cols = 0;
		std::ifstream input(argv[2]);
		input >> rows >> cols;
		if (!in) {
			throw "Wrong matrix input";
		}
		char num = argv[1][0];
		if (num == '1') {
		  int statmatrix[10000];
      inputMatrix (input, statmatrix, rows, cols);
	
		}
		else if (num == '2') {
			int * dinmatrix = create (rows, cols);
      inputMatrix (input, dinmatrix, rows, cols);
			//работа с матрицей
			delete[] dinmatrix;
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
} 