// 判断一个带头节点单向链表是否是8非递增有序
// 如果是去重并且就地逆置
// 如果不是那么提示信息
#include <iostream>
using namespace std;
#define maxlength 100005
int a[maxlength];

typedef struct node {
    int data;
    struct node *next;
} node, *linklist;

linklist NewNode(int e) {
    linklist p = (linklist)malloc(sizeof(node));
    p->data = e;
    p->next = NULL;
    return p;
}

void CreateList(linklist &h, int *a, int length) {
    h = (linklist)malloc(sizeof(node));
    h->next = NULL;
    linklist p = h;
    for (int i = 0; i < length; i++) {
        p->next = NewNode(a[i]);
        p = p->next;
    }
    p->next = NULL;
}

void PrintLinklist(linklist &h) {
    linklist q = h->next;
    while (q) {
        cout << q->data << ' ';
        q = q->next;
    }
    cout << '\n';
}

bool judge(linklist h) {
    linklist p = h, q = p->next;
    int pre = 1e9;
    while (q) {
        if (q->data <= pre) {
            pre = q->data;
            p = q;
            q = q->next;
        } else {
            return false;
        }
    }
    return true;
}

void Union(linklist &h) {
    linklist p = h->next, q = p->next;
    while (q) {
        if (q->data == p->data) {
            p->next = q->next;
            free(q);
            q = p->next;
        } else {
            p = q;
            q = q->next;
        }
    }
}

void Reverse(linklist &h) {
    linklist p = h->next;
    h->next = NULL;
    linklist q = NULL;
    while (p) {
        h->next = p;
        p = p->next;
        h->next->next = q;
        q = h->next;
    }
}

int main() {
    linklist h;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    CreateList(h, a, n);
    cout << "Created Successfully!" << endl;
    cout << "Linklist: ";
    PrintLinklist(h);
    if (judge(h)) {
        cout << "链表是非递增有序！" << '\n';
        Union(h);
        cout << "去重后:" << '\n';
        PrintLinklist(h);
        Reverse(h);
        cout << "就地逆置后:" << '\n';
        PrintLinklist(h);
    } else {
        cout << "链表不是非递增有序！" << '\n';
    }
    return 0;
}

/*
9
8 8 7 6 5 4 3 3 2
*/