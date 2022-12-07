// 建立带头节点单向循环链表，其中元素非递增有序
// 删除所有值大于mink且小于maxk的元素
// 并将链表分解为两个链表，分别含奇数和偶数

#include <iostream>
using namespace std;

typedef struct node {
    int data;
    struct node* next;
} node, *linklist;

linklist NewNode(int e) {
    linklist h = (linklist)malloc(sizeof(node));
    h->data = e;
    h->next = NULL;
    return h;
}

// 头插法建立单向循环链表非递增有序
void CreateLinkList(linklist& h) {
    h = (linklist)malloc(sizeof(node));
    h->next = h;
    int elem;
    linklist p = h->next;
    int n;
    cout << "please enter thr lengths: " << endl;
    cin >> n;
    while (n--) {
        cin >> elem;
        h->next = NewNode(elem);
        h->next->next = p;
        p = h->next;
    }
}

// 打印单向循环链表
void PrintCircleLinkList(linklist& h) {
    linklist q = h->next;
    while (q != h) {
        cout << q->data << ' ';
        q = q->next;
    }
    cout << '\n';
}

// 删除元素
void delk(linklist& h, int mink = 3, int maxk = 6) {
    linklist p = h, q = h->next;
    while (q != h) {
        if (q->data > mink && q->data < maxk) {
            linklist k = p, r = q;
            while (r->data > mink && r->data < maxk && r != h) {
                k = r;
                r = r->next;
                free(k);
            }
            p->next = r;
            break;
        } else {
            p = q;
            q = q->next;
        }
    }
}

void ApartList(linklist& h, linklist& a, linklist& b) {
    a = (linklist)malloc(sizeof(node));
    b = (linklist)malloc(sizeof(node));
    a->next = NULL;
    b->next = NULL;
    linklist q = h->next;
    linklist pa = a, pb = b;
    while (q != h) {
        if (q->data & 1) {
            pa->next = q;
            pa = pa->next;
        } else {
            pb->next = q;
            pb = pb->next;
        }
        q = q->next;
    }
    pa->next = a;
    pb->next = b;
}

int main() {
    linklist h;
    CreateLinkList(h);
    cout << "Link list created!" << endl;
    cout << "L: ";
    PrintCircleLinkList(h);
    delk(h, 3, 6);
    cout << "Link list finish the delete operation:" << endl;
    cout << "L: ";
    PrintCircleLinkList(h);
    linklist L1, L2;
    ApartList(h, L1, L2);
    cout << "Linklist is aparted:" << endl;
    cout << "L1: ";
    PrintCircleLinkList(L1);
    cout << "L2: ";
    PrintCircleLinkList(L2);
    return 0;
}

/*
10
2 3 4 4 5 5 7 8 9 9
*/