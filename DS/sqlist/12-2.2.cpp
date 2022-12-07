// 合并两个有序递增顺序表为另一个有序递减顺序表
#include "iostream"
using namespace std;

#define ElemType int
const int maxn = 1e5;
int a[maxn], b[maxn];

typedef struct {
    ElemType *elem;
    int length;
    int listsize;
} sqlist;

void CreateList(sqlist &L, int *a, int length) {
    L.length = length;
    L.elem = (ElemType *)malloc(L.length * 2 * sizeof(ElemType));
    L.listsize = length * 2;
    for (int i = 0; i < L.length; i++) {
        L.elem[i] = a[i];
    }
}

void PrintList(sqlist &L) {
    for (int i = 0; i < L.length; i++) {
        cout << L.elem[i] << ' ';
    }
    cout << '\n';
}

void ReverseList(sqlist &L) {
    int i = 0, j = L.length - 1;
    while (i < j) {
        int t = L.elem[i];
        L.elem[i++] = L.elem[j];
        L.elem[j--] = t;
    }
}

void Unionlist(sqlist A, sqlist B, sqlist &C) {
    C.length = A.length + B.length;
    C.elem = (ElemType *)malloc(sizeof(ElemType) * C.length * 2);
    C.listsize = C.length * 2;
    int i = 0, j = 0, k = 0;
    while (i < A.length && j < B.length) {
        if (A.elem[i] < B.elem[j]) {
            C.elem[k++] = A.elem[i++];
        } else {
            C.elem[k++] = B.elem[j++];
        }
    }
    while (i < A.length) {
        C.elem[k++] = A.elem[i++];
    }
    while (j < B.length) {
        C.elem[k++] = B.elem[j++];
    }
    ReverseList(C);
}

int main() {
    int na, nb;
    cin >> na;
    for (int i = 0; i < na; i++) {
        cin >> a[i];
    }
    cin >> nb;
    for (int i = 0; i < nb; i++) {
        cin >> b[i];
    }
    sqlist A, B, C;
    CreateList(A, a, na);
    cout << "Creat sqlist A:" << '\n';
    PrintList(A);
    CreateList(B, b, nb);
    cout << "Creat sqlist B:" << '\n';
    PrintList(B);
    Unionlist(A, B, C);
    cout << "Unionlist:" << '\n';
    PrintList(C);
    return 0;
}

/* 
4
2 3 3 5
5
2 5 6 8 9
 */