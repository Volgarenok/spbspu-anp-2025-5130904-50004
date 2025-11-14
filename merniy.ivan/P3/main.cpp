#include <tream>
#include <fsream>

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


