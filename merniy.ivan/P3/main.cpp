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
 int task = stoi(argv[1]);
 int top = 0, bottom = rows - 1, left = 0, right = cols - 1;
 int val = 1;
 if (task == 5) {
	 while (top <= bottom && left <= right) {
            for (int i = left; i <= right; i++) matrix[top][i] -= val++;
            top++;
            for (int i = top; i <= bottom; i++) matrix[i][right] -= val++;
            right--;
            for (int i = right; i >= left && top <= bottom; i--) matrix[bottom][i] -= val++;
            bottom--;
            for (int i = bottom; i >= top && left <= right; i--) matrix[i][left] -= val++;
            left++;
        }
    } else if (task == 6) {


