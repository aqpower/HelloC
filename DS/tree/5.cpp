/*
将表达式树转为为中缀表达式
Input:
*+A##B##*C##-#D##
Output:
(A+B)*(C*(-D))
*/

#include <iostream>
using namespace std;

#define Max_Tree_SIZE 20

typedef char TElemType;
typedef struct BiTNode {
    TElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

BiTree CreateBiTree(BiTree &root) {
    TElemType ch;
    cin >> ch;
    if (ch != '#') {
        root = new BiTNode;
        root->data = ch;
        root->lchild = CreateBiTree(root->lchild);
        root->rchild = CreateBiTree(root->rchild);
    } else {
        root = NULL;
    }
    return root;
}

void BTreeToExp(BiTree &root, int deep) {
    if (!root) {
        return;
    } else if ((!root->lchild) && (!root->rchild)) {
        cout << root->data;
    } else {
        if (deep > 1) {
            cout << "(";
        }
        BTreeToExp(root->lchild, deep + 1);
        cout << root->data;
        BTreeToExp(root->rchild, deep + 1);
        if (deep > 1) {
            cout << ")";
        }
    }
}

void BTreeToE(BiTree &root) { BTreeToExp(root, 1); }

void TreePrint(BiTree T, int level) {
    if (!T) {
        return;
    }
    TreePrint(T->rchild, level + 1);
    for (int i = 0; i < level; i++) {
        printf("   ");
    }
    cout << T->data << '\n';
    TreePrint(T->lchild, level + 1);
}

int main() {
    BiTree root;
    CreateBiTree(root);
    TreePrint(root, 0);
    cout << "To Exp: ";
    BTreeToE(root);
    return 0;
}