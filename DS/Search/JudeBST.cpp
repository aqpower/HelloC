/* 判断一棵树是否为二叉排序树
 Input:1 2 # # 3 # #
 Output:It is NOT a Binary Search Tree!!!

 Input:2 1 # # 3 # #
 Output:It is a Binary Search Tree!!!
*/
#include <string>
#include <iostream>
using namespace std;

typedef int elemtype;
typedef struct NODE {
    elemtype data;
    struct NODE* lchild;
    struct NODE* rchild;
} Node, *node;

node BuildTreebyPre(node& root) {
    char x;
    cin >> x;
    if (x != '#') {
        root = (node)malloc(sizeof(Node));
        root->data = x - '0';
        root->lchild = BuildTreebyPre(root->lchild);
        root->rchild = BuildTreebyPre(root->rchild);
    } else {
        root = NULL;
    }
    return root;
}

bool fg = true;
elemtype pre = -1e9;
void Inorder(node root) {
    if (root) {
        Inorder(root->lchild);
        if (root->data <= pre) {
            fg = false;
        } else {
            pre = root->data;
        }
        Inorder(root->rchild);
    }
}

bool JudgeBST(node root) {
    Inorder(root);
    return fg;
}

int main() {
    node root;
    BuildTreebyPre(root);
    cout << "It is ";
    if (!JudgeBST(root)) {
        cout << "NOT ";
    }
    cout << "a Binary Search Tree!!!" << endl;
    return 0;
}