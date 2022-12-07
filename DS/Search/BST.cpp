// 二叉链表建立二叉排序树，实现增加和删除功能
// NO Input
#include <iostream>
using namespace std;

typedef int elemtype;

typedef struct NODE {
    struct NODE* lchild;
    struct NODE* rchild;
    elemtype data;
} Node, *node;

node NewNode(elemtype data) {
    node a = (node)malloc(sizeof(Node));
    a->data = data;
    a->lchild = NULL;
    a->rchild = NULL;
    return a;
}

void insert(node& root, elemtype x) {
    if (!root) {
        root = NewNode(x);
    } else {
        if (x > root->data) {
            insert(root->rchild, x);
        } else if (x < root->data) {
            insert(root->lchild, x);
        }
    }
}

node FindMax(node root) {
    while (root->rchild) {
        root = root->rchild;
    }
    return root;
}

node FindMin(node root) {
    while (root->lchild) {
        root = root->lchild;
    }
    return root;
}

void DeleteNode(node& root, elemtype x) {
    if (root == NULL) {
        return;
    }
    if (root->data == x) {
        if (!root->lchild && !root->rchild) {
            root = NULL;
        } else if (root->lchild) {
            node pre = FindMax(root->lchild);
            root->data = pre->data;
            DeleteNode(root->lchild, pre->data);
        } else {
            node next = FindMin(root->rchild);
            root->data = next->data;
            DeleteNode(root->rchild, next->data);
        }

    } else if (root->data > x) {
        DeleteNode(root->lchild, x);
    } else {
        DeleteNode(root->rchild, x);
    }
}

void BuiltTree(node& root, elemtype a[], int length) {
    root = NULL;
    for (int i = 0; i < length; i++) {
        insert(root, a[i]);
    }
}

void InOrder(node root) {
    if (root == NULL) {
        return;
    }
    InOrder(root->lchild);
    cout << root->data << ' ';
    InOrder(root->rchild);
}

void PrintTree(node root) {
    cout << "InOrder: ";
    InOrder(root);
    cout << endl;
}

int main() {
    node root = NULL;
    elemtype a[10] = {3, 1, 5, 4, 2, 9, 12};
    BuiltTree(root, a, 7);
    cout << "Successfully build a Binary Search Tree!" << endl;
    PrintTree(root);
    cout << "delete 4:" << endl;
    DeleteNode(root, 4);
    PrintTree(root);
    cout << "delete 1:" << endl;
    DeleteNode(root, 1);
    PrintTree(root);
    cout << "delete 12:" << endl;
    DeleteNode(root, 12);
    PrintTree(root);


    cout << "insert 12:" << endl;
    insert(root, 12);
    PrintTree(root);

    return 0;
}