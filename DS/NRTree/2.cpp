/*
按层次遍历二叉树，打印节点所在层次，并求出二叉树的宽度
input:
CEI#J##F#GK##H##D##
K
*/
#include <iostream>
using namespace std;

typedef char TElemType;
typedef struct BiTNode {
    TElemType data;
    struct BiTNode *lchild, *rchild;
    int lawer;
} BiTNode, *BiTree;

typedef BiTree SElemType;
typedef BiTree QElemType;

#define Max_Tree_SIZE 20

typedef struct QUEUE {
    QElemType data[Max_Tree_SIZE];
    int front;
    int rear;
} Queue;

void InitQueue(Queue& qu) { qu.front = qu.rear = 0; }
void EnQueue(Queue& qu, QElemType e) { qu.data[qu.rear++] = e; }
void DeQueue(Queue& qu, QElemType& e) { e = qu.data[qu.front++]; }
QElemType QueueFront(Queue qu) { return qu.data[qu.front]; }
bool QueueEmpty(Queue& qu) { return qu.front == qu.rear; }


void InitBiTree(BiTree* BT) { *BT = NULL; }

BiTree NewNode(TElemType e) {
    BiTree p = (BiTree)malloc(sizeof(BiTNode));
    p->data = e;
    p->lchild = p->rchild = NULL;
    p->lawer = 1;
    return p;
}

void CreateTree(BiTree* root) {
    char ch;
    cin >> ch;
    if (ch == '#') {
        *root = NULL;
    } else {
        (*root) = NewNode(ch);
        CreateTree(&(*root)->lchild);
        CreateTree(&(*root)->rchild);
    }
}

// 返回树的宽度和e节点所在层数，同时输出层序遍历。
int Lever(BiTree root, TElemType e, int& ind) {
    int a[20];
    for (int i = 0; i < 20; i++) {
        a[i] = 0;
    }
    Queue qu;
    InitQueue(qu);
    EnQueue(qu, root);
    while (!QueueEmpty(qu)) {
        BiTree top;
        DeQueue(qu, top);
        a[top->lawer]++;
        cout << top->data;
        if (top->data == e) {
            ind = top->lawer;
        }
        if (top->lchild) {
            top->lchild->lawer = top->lawer + 1;
            EnQueue(qu, top->lchild);
        }
        if (top->rchild) {
            top->rchild->lawer = top->lawer + 1;
            EnQueue(qu, top->rchild);
        }
    }
    int treeWidth = -1;
    for (int i = 1; i < 20; i++) {
        treeWidth = max(treeWidth, a[i]);
    }
    return treeWidth;
}

int main() {
    BiTree root;
    CreateTree(&root);
    char c;
    cin >> c;
    int ind;
    cout << "LeverOrder:";
    int width = Lever(root, c, ind);
    printf("\nThe width of the tree is %d\n", width);
    cout << "The lever of " << c << " is " << ind << '\n';
    return 0;
}