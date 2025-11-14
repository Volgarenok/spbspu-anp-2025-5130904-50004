#include <iostream>
#include <fstream>

int main(int argc, char* argv[]) {
     if (argc != 4) return 1;
    ifstream fin(argv[2]);
    ofstream fout(argv[3]);
    int n, m;
    fin >> n >> m;
    int** a = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        a[i] = (int*)malloc(m * sizeof(int));
        for (int j = 0; j < m; j++) {
            fin >> a[i][j];
        }
    }
    int variant = stoi(argv[1]);
    int t = 0, b = n - 1, l = 0, r = m - 1;
    int k = 1;
    if (variant == 5) {
       while (t <= b && l <= r) {
           for (int j = l; j <= r; j++) a[t][j] -= k++;
           t++;
           for (int i = t; i <= b; i++) a[i][r] -= k++;
           r--;
           for (int j = r; j >= l && t <= b; j--) a[b][j] -= k++;
           b--;
           for (int i = b; i >= t && l <= r; i--) a[i][l] -= k++;
           l++;
       }
   }
   else if (variant == 6) {
        while (t <= b && l <= r) {
            for (int i = t; i <= b; i++) a[i][l] += k++;
            l++;
            for (int j = l; j <= r; j++) a[b][j] += k++;
            b--;
            for (int i = b; i >= t && l <= r; i--) a[i][r] += k++;
            r--;
            for (int j = r; j >= l && t <= b; j--) a[t][j] += k++;
            t++;
        }
    }
    fout << n << " " << m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fout << " " << a[i][j];
        }
    }
    for (int i = 0; i < n; i++) free(a[i]);
    free(a);
    return 0;
}
