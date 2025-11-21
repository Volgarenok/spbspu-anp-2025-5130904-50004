#include <iostream>
#include <fstream>
#include <cstdlib>
int main(int argc, char* argv[]) {
    if (argc != 4) return 1;
    std::ifstream fun(argv[2]);
    std::ofstream fout(argv[3]);
    int n, m;
    fun >> n >> m;
    int** a = static_cast<int**>(std::malloc(n * sizeof(int*)));
    for (int i = 0; i < n; i++) {
        a[i] = static_cast<int*>(std::malloc(m * sizeof(int)));
        for (int j = 0; j < m; j++) {
            fun >> a[i][j];
        }
    }
    int variant = std::atoi(argv[1]);
    int t = 0, b = n - 1, l = 0, r = m - 1;
    int k = 1;
    if (variant == 5) {
        while (t <= b && l <= r) {
            for (int j = l; j <= r; j++) a[t][j] = k++;
            t++;
            for (int i = t; i <= b; i++) a[i][r] = k++;
            r--;
            for (int j = r; j >= l && t <= b; j--) a[b][j] = k++;
            b--;
            for (int i = b; i >= t && l <= r; i--) a[i][l] = k++;
            l++;
        }
    } else if (variant == 6) {
        while (t <= b && l <= r) {
            for (int i = t; i <= b; i++) a[i][l] = k++;
            l++;
            for (int j = l; j <= r; j++) a[b][j] = k++;
            b--;
            for (int i = b; i >= t && l <= r; i--) a[i][r] = k++;
            r--;
            for (int j = r; j >= l && t <= b; j--) a[t][j] = k++;
            t++;
        }
    }
    fout << n << " " << m << "\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fout << a[i][j];
            if (j < m - 1) fout << " ";
        }
        fout << "\n";
    }
    for (int i = 0; i < n; i++) std::free(a[i]);
    std::free(a);
    return 0;
}
