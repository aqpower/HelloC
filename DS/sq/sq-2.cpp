// 矩阵以三元组顺序表表示，寻找马鞍点,输入矩阵行数和列数
#include <cstring>
#include <iostream>
#include <random>

#define MAX_SIZE 1024
#define ElemType int
using namespace std;

typedef struct {
    int i;
    int j;
    ElemType e;
} Triple;

typedef struct {
    int n;
    int m;
    int nz;
    Triple data[MAX_SIZE];
} Matrix;

int wor[MAX_SIZE][MAX_SIZE];

void ChangeToTriple(Matrix& ma, int n, int m) {
    ma.n = n;
    ma.m = m;
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (wor[i][j]) {
                ma.data[k].i = i;
                ma.data[k].j = j;
                ma.data[k].e = wor[i][j];
                k++;
            }
        }
    }
    ma.nz = k;
}

uniform_int_distribution<int> u(0, 9);
default_random_engine e(time(0));
// 随机生成一个矩阵，并输出其矩阵形式
void CreateSparseMatrix(Matrix& ma, int n = 9, int m = 9) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            wor[i][j] = u(e);
            cout << wor[i][j] << " ";
        }
        cout << '\n';
    }
    ChangeToTriple(ma, n, m);
}

void PrintTriple(Matrix ma) {
    cout << "以三元组顺序表存储:" << '\n';
    for (int i = 0; i < ma.nz; i++) {
        cout << ma.data[i].i << " " << ma.data[i].j << " " << ma.data[i].e
             << '\n';
    }
    cout << ma.n << '\n' << ma.m << '\n' << ma.nz << '\n';
}

int FindSaddlePoint(Matrix a, int n, int m) {
    int sum = 0;
    int mi[a.n + 3];
    fill(mi, mi + a.n + 3, 1e9);
    int ma[a.m + 3];
    fill(ma, ma + a.m + 3, -1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            mi[i] = min(mi[i], wor[i][j]);
            ma[j] = max(ma[j], wor[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (wor[i][j] == mi[i] && wor[i][j] == ma[j]) {
                if (!sum) {
                    cout << "Saddle Point: " << '\n';
                }
                sum++;
                cout << i << " " << j << " " << wor[i][j] << '\n';
            }
        }
    }
    return sum;
}

int main() {
    Matrix a;
    int n, m;
    cin >> n >> m;
    CreateSparseMatrix(a, n, m);
    // PrintTriple(a);
    if (!FindSaddlePoint(a, n, m)) {
        cout << "No Saddle Point!" << '\n';
    }
    return 0;
}