#include "io.h"
#include "io.cpp"

void Nepochatova::transformMatrixSpiral(int* arr, int n, int m) {
    int layers = (std::min(n, m) + 1) / 2;
    int count = 1;

    for (int layer = 0; layer < layers; ++layer) {
        int startRow = layer;
        int endRow = n - layer - 1;
        int startCol = layer;
        int endCol = m - layer - 1;

        for (int col = startCol; col <= endCol; ++col) {
            arr[startRow * m + col] -= count;
        }
        count++;

        for (int row = startRow + 1; row <= endRow; ++row) {
            arr[row * m + endCol] -= count;
        }
        count++;

        if (endRow > startRow) {
            for (int col = endCol - 1; col >= startCol; --col) {
                arr[endRow * m + col] -= count;
            }
            count++;
        }

        if (endCol > startCol) {
            for (int row = endRow - 1; row > startRow; --row) {
                arr[row * m + startCol] -= count;
            }
            count++;
        }
    }
}

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
