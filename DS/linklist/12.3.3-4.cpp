// L(a1,a2,...,an-1,an) 转换为 L'=(a1,an,a2,an-1,a3,an-2,...)
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

void CreateLinklist(linklist &h, int *a, int length) {
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

// 逆置h之后的链表
void Reverse(linklist &h) {
    linklist p = h->next, q = NULL;
    h->next = NULL;
    while (p) {
        h->next = p;
        p = p->next;
        h->next->next = q;
        q = h->next;
    }
}

// void Reverse(linklist &L) {
//     linklist p = L->next, r = p->next;
//     p->next = NULL;
//     while (r) {
//         p = r;
//         r = r->next;
//         p->next = L->next;
//         L->next = p;
//     }
// }

int GetLength(linklist h) {
    linklist q = h->next;
    int len = 0;
    while (q) {
        len++;
        q = q->next;
    }
    return len;
}

void Solution(linklist &h) {
    int length = GetLength(h);
    length /= 2;
    linklist mid = h, q = h->next, pre;
    while (length--) {
        if (length == 1) {
            pre = q;
        }
        mid = q;
        q = q->next;
    }
    Reverse(mid);
    // PrintLinklist(h);
    linklist k = mid->next;
    mid->next = NULL;
    linklist p = h->next;
    h->next = NULL;
    q = h;
    while (p && k) {
        q->next = p;
        p = p->next;
        q = q->next;
        q->next = k;
        k = k->next;
        q = q->next;
    }
}

int main() {
    linklist h;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    CreateLinklist(h, a, n);
    cout << "L(a1,a2,...,an-1,an)" << endl;
    PrintLinklist(h);
    cout << "L'=(a1,an,a2,an-1,a3,an-2,...)" << endl;
    Solution(h);
    PrintLinklist(h);
    return 0;
}

/*
8
1 2 3 4 5 6 7 8
*/