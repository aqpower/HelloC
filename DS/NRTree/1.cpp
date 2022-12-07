/*
通过树的广义表形式建树
Input：A(B(D,E(G,)),C(,F))#
*/
#include <iostream>
using namespace std;

typedef char TElemType;
typedef struct BiTNode {
    TElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

typedef BiTree SElemType;

#define Max_Tree_SIZE 20

typedef struct STACK {
    SElemType data[Max_Tree_SIZE];
    int top;
} Stack;

void InitStack(Stack& st) { st.top = 0; }
void PushStack(Stack& st, SElemType e) { st.data[st.top++] = e; }
SElemType PopStack(Stack& st) { return st.data[--st.top]; }
SElemType TopStack(Stack st) { return st.data[st.top - 1]; }
bool StackEmpty(Stack& st) { return st.top == 0; }

void InitBiTree(BiTree* BT) { *BT = NULL; }

BiTree NewNode(TElemType e)
{
    BiTree p = (BiTree)malloc(sizeof(BiTNode));
    p->data = e;
    p->lchild = p->rchild = NULL;
    return p;
}

void CreateTree(BiTree* root, string s)
{
    InitBiTree(root);
    Stack st;
    InitStack(st);
    int k = 0;
    BiTree p;
    for (int i = 0; i < int(s.size()); i++) {
        switch (s[i]) {
        case '(':
            PushStack(st, p);
            k = 0;
            break;
        case ')':
            PopStack(st);
            break;
        case ',':
            k = 1;
            break;
        case '#':
            break;
        default:
            p = NewNode(s[i]);
            if (*root == NULL) {
                *root = p;
            } else {
                if (k) {
                    TopStack(st)->rchild = p;
                } else {
                    TopStack(st)->lchild = p;
                }
            }
        }
    }
}

int NodeNum(BiTree root)
{
    if (root) {
        return NodeNum(root->lchild) + NodeNum(root->rchild) + 1;
    } else {
        return 0;
    }
}


void TreePrint(BiTree T, int level)
{
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

int main()
{
    string s;
    cin >> s;
    BiTree root;
    CreateTree(&root, s);
    cout << "Build Tree Successfully!" << '\n';
    TreePrint(root, 0);
    cout << "The sum node of the tree is " << NodeNum(root);
    return 0;
}