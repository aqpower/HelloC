/*
按中序序列建立两棵二叉树的二叉链表结构，判断两颗树是否相等
input:
123####
123####

*/

#include <iostream>
using namespace std;

typedef char TElemType;
typedef struct BiTNode {
    TElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

BiTree CreateBiTree(BiTree& root) {
    TElemType ch;
    cin >> ch;
    if (ch != '#') {
        root = new BiTNode;
        root->lchild = CreateBiTree(root->lchild);
        root->data = ch;
        root->rchild = CreateBiTree(root->rchild);
    } else {
        root = NULL;
    }
    return root;
}

void InOrder(BiTree BT) {
    if (!BT) {
        return;
    }
    InOrder(BT->lchild);
    cout << BT->data;
    InOrder(BT->rchild);
}

bool Cmp(BiTree a, BiTree b) {
    if (!a && !b) {
        return true;
    }
    if (!a || !b) {
        return false;
    }
    if (a->data == b->data) {
        return Cmp(a->lchild, b->lchild) && Cmp(a->rchild, b->rchild);
    } else {
        return false;
    }
}

int main() {
    BiTree ta,tb;
    CreateBiTree(ta);
    CreateBiTree(tb);
    if(Cmp(ta,tb)){
        cout << "Equal" << '\n';
    } else {
        cout << "Not Equal" << '\n';
    }
    return 0;
}