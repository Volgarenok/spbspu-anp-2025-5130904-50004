#include <iostream>
#include <fsream>

int main(int argc, char* argv[]) 
{
 if (argc < 4) return 1;
 if (string(argv[1]) != "2") return 1;
 ifstream input(argv[2]);
 ofstream output(argv[3]);
 int rows, cols;
 input >> rows >> cols;
 int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            input >> matrix[i][j];
        }
    }

