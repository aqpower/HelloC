/*
 实现稀疏矩阵A和B的逆置和相加得到矩阵C
 并分别输出其矩阵形式和三元组顺序表形式
 Input:
 10 10
*/
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

void ChangeToMatrix(Matrix ma) {
    int temp[ma.n + 3][ma.m + 3];
    memset(temp, 0, sizeof(temp));
    for (int i = 0; i < ma.nz; i++) {
        temp[ma.data[i].i][ma.data[i].j] = ma.data[i].e;
    }
    for (int i = 0; i < ma.n; i++) {
        for (int j = 0; j < ma.m; j++) {
            cout << temp[i][j] << " ";
        }
        cout << '\n';
    }
}

void PrintTriple(Matrix ma) {
    cout << "以三元组顺序表存储:" << '\n';
    for (int i = 0; i < ma.nz; i++) {
        cout << ma.data[i].i << " " << ma.data[i].j << " " << ma.data[i].e
             << '\n';
    }
    cout << ma.n << '\n' << ma.m << '\n' << ma.nz << '\n';
}

uniform_int_distribution<int> u(0, 19);  // 0表示为有数值，非零表示为零
uniform_int_distribution<int> g(1, 9);  // 有数值时候的取值范围
default_random_engine e(time(0));
// 随机生成一个稀疏矩阵，并输出其矩阵形式
void CreateSparseMatrix(Matrix& ma, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (u(e) == 0) {
                wor[i][j] = g(e);
            } else {
                wor[i][j] = 0;
            }
            cout << wor[i][j] << " ";
        }
        cout << '\n';
    }
    ChangeToTriple(ma, n, m);
}

void TransposeMatrix(Matrix ma, Matrix& ta) {
    int a[ma.m + 3];
    int b[ma.m + 3];
    memset(a, 0, sizeof(a));
    b[0] = 0;
    for (int i = 0; i < ma.nz; i++) {
        a[ma.data[i].j]++;
    }
    for (int i = 1; i < ma.m; i++) {
        b[i] = b[i - 1] + a[i - 1];
    }
    ta.m = ma.n;
    ta.n = ma.m;
    ta.nz = ma.nz;
    for (int i = 0; i < ma.nz; i++) {
        int ind = b[ma.data[i].j]++;
        ta.data[ind] = ma.data[i];
        int t = ta.data[ind].i;
        ta.data[ind].i = ta.data[ind].j;
        ta.data[ind].j = t;
    }
}

bool MatrixPlus(Matrix a, Matrix b, Matrix& c) {
    if (a.n != b.n || a.m != b.m) {
        return false;
    }
    int i = 0, j = 0, k = 0;
    while (i < a.nz && j < b.nz) {
        if (a.data[i].i == b.data[j].i && a.data[i].j == b.data[j].j) {
            c.data[k].i = a.data[i].i;
            c.data[k].j = a.data[i].j;
            c.data[k].e = a.data[i].e + b.data[j].e;
            k++, i++, j++;
        } else if (a.data[i].i < b.data[j].i ||
                   (a.data[i].i == b.data[j].i && a.data[i].j < b.data[j].j)) {
            c.data[k] = a.data[i];
            k++, i++;
        } else {
            c.data[k] = b.data[j];
            k++, j++;
        }
    }
    while (i < a.nz) {
        c.data[k] = a.data[i];
        k++, i++;
    }
    while (j < b.nz) {
        c.data[k] = b.data[j];
        k++, j++;
    }
    c.n = a.n;
    c.m = a.m;
    c.nz = k;
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    Matrix a, ta, b, c;
    cout << "随机生成稀疏矩阵A如下:" << '\n';
    CreateSparseMatrix(a, n, m);
    PrintTriple(a);

    cout << "随机生成稀疏矩阵B如下:" << '\n';
    CreateSparseMatrix(b, n, m);
    PrintTriple(b);

    cout << "将矩阵A转置:" << '\n';
    TransposeMatrix(a, ta);
    ChangeToMatrix(ta);
    PrintTriple(ta);

    cout << "矩阵 C = A + B:" << '\n';
    MatrixPlus(a, b, c);
    ChangeToMatrix(c);
    PrintTriple(c);
    return 0;
}