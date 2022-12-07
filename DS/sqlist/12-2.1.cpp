// 对非递增有序顺序表去重并且逆置
#include "iostream"
using namespace std;

#define ElemType int
const int maxn = 1e5;
int a[maxn];

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

// 看你前面有几个值相同的元素,直接新建一个新的表的意思
void UniqueList(sqlist &L) {
    int k = 0;
    for (int i = 1; i < L.length; i++) {
        if (L.elem[i] == L.elem[i - 1]) {
            k++;
        } else {
            L.elem[i - k] = L.elem[i];
        }
    }
    L.length -= k;
}

void ReverseList(sqlist &L) {
    int i = 0, j = L.length - 1;
    while (i < j) {
        int t = L.elem[i];
        L.elem[i] = L.elem[j];
        L.elem[j] = t;
        i++;
        j--;
    }
}

int main() {
    sqlist L;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    CreateList(L, a, n);
    cout << "CreateList:" << endl;
    PrintList(L);
    UniqueList(L);
    cout << "UniqueList:" << endl;
    PrintList(L);
    ReverseList(L);
    cout << "ReverseList:" << endl;
    PrintList(L);
    return 0;
}

/*
8
7 6 6 5 1 1 1 1
*/