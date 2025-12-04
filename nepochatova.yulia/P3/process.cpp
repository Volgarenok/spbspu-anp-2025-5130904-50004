#include "io.h"

void Nepochatova::transformMatrixSpiral(int** arr, int n, int m) {
    int top = 0;
    int bottom = n - 1;
    int left = 0;
    int right = m-1;
    int increment = 1;
    while (top <= bottom && left <= right) {
        for (int j = left; j <= right; j++) {
            arr[bottom][j] += increment;
            increment++;
        }
        bottom--;
        for (int i = bottom; i >= top; i--) {
            arr[i][right] += increment;
            increment++;
        }
        right--;
        if (top <= bottom) {
            for (int j = right; j >= left; j--) {
                arr[top][j] += increment;
                increment++;
            }
            top++;
        }
        if (left <= right) {
            for (int i = top; i <= bottom; i++) {
                arr[i][left] += increment;
                increment++;
            }
            left++;
        }
    }
}

void Nepochatova::transformMatrixCircular(int** arr, int n, int m) {
    int layer = 1;
    int top = 0, bottom = n - 1, left = 0, right = m - 1;

    while (top <= bottom && left <= right) {

        for (int j = left; j <= right; j++)
            arr[top][j] += layer;

        for (int i = top + 1; i <= bottom; i++)
            arr[i][right] += layer;

        if (top < bottom) {
            for (int j = right - 1; j >= left; j--)
                arr[bottom][j] += layer;
        }

        if (left < right) {
            for (int i = bottom - 1; i > top; i--)
                arr[i][left] += layer;
        }

        top++; bottom--; left++; right--;
        layer++;
    }

}
