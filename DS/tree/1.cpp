/*
    实现后序建树并求出单分支数目，双分支数目，并交换左右子树
    前序：CEI#J##F#GK##H##D##
    后序：###JI###K##HGFE##DC
*/

#include <conio.h>

#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define INFEASIBLE -2
#define Max_Tree_SIZE 20

typedef int Status;
typedef char TElemType;
typedef struct BiTNode {
    TElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;
typedef BiTree SElemType;
typedef BiTree QElemType;

Status InitBiTree(BiTree*);
Status CreateBiTree(BiTree*);
Status CreateBiTreebyPost(BiTree& BT, string s);
Status PreOrder(BiTree);
Status InOrder(BiTree);
Status PostOrder(BiTree);
Status LeverOrder(BiTree);
Status NRPreOrder(BiTree);
int TreeDepth(BiTree);
int LeafNumber(BiTree);
int SingleBranchNumber(BiTree BT);
int DoubleBranchNumber(BiTree BT);
Status SwapSubtree(BiTree BT);

typedef struct QUEUE {
    QElemType data[Max_Tree_SIZE];
    int front;
    int rear;
    QUEUE() : front(0), rear(0) {}
} Queue;

typedef struct STACK {
    SElemType data[Max_Tree_SIZE];
    int top;
    STACK() : top(0) {}
} Stack;

void EnQueue(Queue& qu, QElemType e) { qu.data[qu.rear++] = e; }
QElemType DeQueue(Queue& qu) { return qu.data[qu.front++]; }
QElemType QueueFront(Queue qu) { return qu.data[qu.front]; }
bool QueueEmpty(Queue& qu) { return qu.front == qu.rear; }
void PushStack(Stack& st, SElemType e) { st.data[st.top++] = e; }
SElemType PopStack(Stack& st) { return st.data[--st.top]; }
SElemType TopStack(Stack st) { return st.data[st.top - 1]; }
bool StackEmpty(Stack& st) { return st.top == 0; }

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
    BiTree BT;
    int flag = 1, select;
    cout << '\n';
    cout << "To Create Binary Tree, Please Input PostOrder with `#`:";
    string s;
    cin >> s;
    CreateBiTreebyPost(BT, s);
    // cout << "To Create Binary Tree, Please Input PreOrder with `#`:";
    // CreateBiTree(&BT);
    cout << "1.PreOrder Traversal" << '\n';
    cout << "2.InOrder Traversal" << '\n';
    cout << "3.PostOrder Traversal" << '\n';
    cout << "4.LeverOrder Traversal" << '\n';
    cout << "5.NRPOrder Traversal" << '\n';
    cout << "6.TreeDepth" << '\n';
    cout << "7.LeafNumber" << '\n';
    cout << "8.SingleBranchNumber" << '\n';
    cout << "9.DoubleBranchNumber" << '\n';
    cout << "10.SwapSubtree" << '\n';
    cout << "11.PrintTree" << '\n';
    cout << "12.Exit" << '\n';
    while (flag) {
        cout << "Please select:" << endl;
        cin >> select;
        switch (select) {
            case 1:
                cout << '\n' << "The PreOrder Traversal of Binary Tree is: ";
                PreOrder(BT);
                break;
            case 2:
                cout << '\n' << "The InOrder Traversal of Binary Tree is: ";
                InOrder(BT);
                break;
            case 3:
                cout << '\n' << "The PostOrder Traversal of Binary Tree is ";
                PostOrder(BT);
                break;
            case 4:
                cout << '\n' << "The LeverOrder Traversal of Binary Tree is ";
                LeverOrder(BT);
                break;
            case 5:
                cout << '\n' << "The NRPreOrder Traversal of Binary Tree is ";
                NRPreOrder(BT);
                break;
            case 6:
                cout << '\n'
                     << "The Depth of Binary Tree is: " << TreeDepth(BT);
                break;
            case 7:
                cout << '\n' << "The Number of Leaf is: " << LeafNumber(BT);
                break;
            case 8:
                cout << '\n'
                     << "The SingleBranchNumber of Binary Tree is: "
                     << SingleBranchNumber(BT);
                break;
            case 9:
                cout << '\n'
                     << "The DoubleBranchNumber of Binary Tree is: "
                     << DoubleBranchNumber(BT);
                break;
            case 10:
                cout << '\n' << "Swap left and right subtrees Successfully!";
                SwapSubtree(BT);
                break;
            case 11: TreePrint(BT, 0); break;
            default:
                flag = 0;
                cout << "Press any key to exit!\n";
                _getch();
        }
        cout << '\n';
    }

    return 0;
}

Status InitBiTree(BiTree* BT) {
    *BT = NULL;
    return OK;
}

Status CreateBiTree(BiTree* BT) {
    InitBiTree(BT);
    TElemType ch;
    Stack S;
    cin >> ch;
    if (ch != '#') {
        (*BT) = (BiTree)malloc(sizeof(BiTNode));
        (*BT)->data = ch;
        (*BT)->lchild = (*BT)->rchild = NULL;
        PushStack(S, *BT);
    }
    bool isleft = true;
    while (!StackEmpty(S)) {
        BiTree temp;
        cin >> ch;
        temp = (BiTree)malloc(sizeof(BiTNode));
        temp->data = ch;
        temp->lchild = temp->rchild = NULL;
        if (isleft) {
            if (ch != '#') {
                TopStack(S)->lchild = temp;
                PushStack(S, temp);
            } else {
                isleft = false;
            }
        } else {
            if (ch != '#') {
                TopStack(S)->rchild = temp;
                PopStack(S);
                PushStack(S, temp);
                isleft = true; //!
            } else {
                PopStack(S);
            }
        }
    }
    return OK;
}

Status CreateBiTreebyPost(BiTree& BT, string s) {
    static int count = s.size();
    char item = s[count - 1];
    count--;
    if (item == '#') {
        BT = NULL;
    } else {
        BT = (BiTree)malloc(sizeof(BiTNode));
        BT->data = item;
        CreateBiTreebyPost(BT->rchild, s);
        CreateBiTreebyPost(BT->lchild, s);
    }
    return OK;
}

Status PreOrder(BiTree BT) {
    if (!BT) {
        return ERROR;
    }
    cout << BT->data;
    PreOrder(BT->lchild);
    PreOrder(BT->rchild);
    return OK;
}

Status InOrder(BiTree BT) {
    if (!BT) {
        return ERROR;
    }
    InOrder(BT->lchild);
    cout << BT->data;
    InOrder(BT->rchild);
    return OK;
}
Status PostOrder(BiTree BT) {
    if (!BT) {
        return ERROR;
    }
    PostOrder(BT->lchild);
    PostOrder(BT->rchild);
    cout << BT->data;
    return OK;
}
Status LeverOrder(BiTree BT) {
    Queue Q;
    if (BT) {
        EnQueue(Q, BT);
    }
    while (!QueueEmpty(Q)) {
        BiTree top = QueueFront(Q);
        cout << top->data;
        DeQueue(Q);
        if (top->lchild) {
            EnQueue(Q, top->lchild);
        }
        if (top->rchild) {
            EnQueue(Q, top->rchild);
        }
    }
    return OK;
}
Status NRPreOrder(BiTree BT) {
    Stack S;
    if (BT) {
        cout << BT->data;
        PushStack(S, BT);
    }
    bool isleft = true;
    while (!StackEmpty(S)) {
        if (isleft) {
            if (TopStack(S)->lchild) {
                cout << TopStack(S)->lchild->data;
                PushStack(S, TopStack(S)->lchild);
            } else {
                isleft = false;
            }
        } else {
            if (TopStack(S)->rchild) {
                cout << TopStack(S)->rchild->data;
                BiTree temp = TopStack(S)->rchild;
                PopStack(S);
                PushStack(S, temp);
                isleft = true;
            } else {
                PopStack(S);
            }
        }
    }
    return OK;
}
int TreeDepth(BiTree BT) {
    if (!BT) {
        return 0;
    } else {
        return max(TreeDepth(BT->lchild) + 1, TreeDepth(BT->rchild) + 1);
    }
}
int LeafNumber(BiTree BT) {
    if (!BT) {
        return 0;
    } else {
        if ((!BT->lchild) && (!BT->rchild)) {
            return 1;
        } else {
            return LeafNumber(BT->lchild) + LeafNumber(BT->rchild);
        }
    }
}

int SingleBranchNumber(BiTree BT) {
    if (!BT) {
        return 0;
    }
    if ((BT->lchild && !BT->rchild) || (!BT->lchild && BT->lchild)) {
        return DoubleBranchNumber(BT->lchild) + DoubleBranchNumber(BT->rchild) +
               1;
    } else {
        return DoubleBranchNumber(BT->lchild) + DoubleBranchNumber(BT->rchild);
    }
}

int DoubleBranchNumber(BiTree BT) {
    if (!BT) {
        return 0;
    }
    if (BT->lchild && BT->rchild) {
        return DoubleBranchNumber(BT->lchild) + DoubleBranchNumber(BT->rchild) +
               1;
    } else {
        return DoubleBranchNumber(BT->lchild) + DoubleBranchNumber(BT->rchild);
    }
}

Status SwapSubtree(BiTree BT) {
    if (BT == NULL)
        return ERROR;
    else {
        BiTree temp = BT->lchild;
        BT->lchild = BT->rchild;
        BT->rchild = temp;
        SwapSubtree(BT->lchild);
        SwapSubtree(BT->rchild);
    }
    return OK;
}