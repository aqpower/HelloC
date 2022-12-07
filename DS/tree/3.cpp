/*
将线性表存储的完全二叉树用二叉链表存储
8 
1 2 3 4 5 6 7 8
*/
#include <iostream>
using namespace std;

#define Max_Tree_SIZE 20
typedef int TElemType;
typedef int LElemType;
typedef struct BiTNode {
    TElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

typedef struct {
    LElemType elem[Max_Tree_SIZE];
    int length;
    int listsize;
} sqlist;

void InitList(sqlist &L) {
    L.length = 0;
    L.listsize = Max_Tree_SIZE;
}

void CreatebyList(BiTree &root, sqlist &L, int ind) {
    if (ind <= L.length) {
        root = new BiTNode;
        root->lchild = root->rchild = NULL;
        root->data = L.elem[ind];
        CreatebyList(root->lchild, L, ind * 2);
        CreatebyList(root->rchild, L, ind * 2 + 1);
    }
}
void CreateBiTree(BiTree &root, sqlist &L) { CreatebyList(root, L, 1); }

void TreePrint(BiTree T, int level) {
    if (!T)  
    {
        return;
    }
    TreePrint(T->rchild, level + 1);  
    for (int i = 0; i < level; i++)   
    {
        printf("   ");
    }
    cout << T->data << '\n';
    TreePrint(T->lchild, level + 1); 
}

void CreateList(sqlist &L, int a[], int length) {
    for (int i = 1; i <= length; ++i) {
        L.elem[i] = a[i];
    }
    L.length = length;
}

int main() {
    sqlist L;
    InitList(L);
    int n;
    cin >> n;
    int a[Max_Tree_SIZE];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    CreateList(L, a, n);
    BiTree root;
    CreateBiTree(root, L);
    cout << "Create Binary Successfully!" << endl;
    cout << endl;
    TreePrint(root,0);
    cout << endl;
    return 0;
}