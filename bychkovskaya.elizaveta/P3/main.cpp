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

void clearMatrix (int ** m, size_t rows)
{
	for (size_t i=0; i < rows; ++i) {
		delete[] m[i];
	}
	delete[] m;
}

int ** create (size_t rows, size_t cols)
{
	int ** result = new int * [rows];
	size_t i = 0;
	try {
		for (; i < rows; ++i) {
			result[i] = new int[cols];
		}
	}
	catch (...) {
		clearMatrix (result, i);
		throw "Not enough memory";
	}
	return result;
}

std::ifstream& inputDinMatrix (std::ifstream& in, int ** m, size_t rows, size_t cols) {
	in >> rows >> cols;
	if (!(in >> rows >> cols)) {
		throw "Wrong matris input";
	}
	for (size_t i = 0; i < rows; ++i) {
		for (size_t j = 0; j < cols; ++j) {
			in >> m[i][j];
			if (!(in >> m[i][j])) {
				throw "Wrong matris input";
		  }
	  }
  }
	return in;
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
	

		char num = argv[1][0];
		if (num == '1') {
		  // int statmatrix[10000];
			
		}
		else if (num == '2') {
			//динамичсекий массив
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