#include "io.h"

void Nepochatova::transformMatrixSpiral(int* arr, int n, int m)

void Nepochatova::transformMatrixCircular(int* arr, int n, int m) {
    int layers = (n < m ? n : m) / 2;

    for (int layer = 0; layer < layers; ++layer) {
        int increment = layer + 1;

        for (int col = layer; col < m - layer; ++col) {
            arr[layer * m + col] += increment;
            arr[(n - layer - 1) * m + col] += increment;
        }

        for (int row = layer + 1; row < n - layer - 1; ++row) {
            arr[row * m + layer] += increment;
            arr[row * m + (m - layer - 1)] += increment;
        }
    }
}
