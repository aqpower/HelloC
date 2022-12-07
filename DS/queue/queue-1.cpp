// 用带头节点的循环链表实现队列，且仅设有一个尾指针
#include <iostream>
using namespace std;

#define elemtype int

typedef struct node {
    elemtype data;
    struct node* next;
} node;

typedef struct Queue {
    node* end;
} Queue;

node* NewNode(elemtype e) {
    node* p = (node*)malloc(sizeof(node));
    p->data = e;
    p->next = NULL;
    return p;
}

void InitQueue(Queue& qu) {
    qu.end = (node*)malloc(sizeof(node));
    qu.end->next = qu.end;
    qu.end->data = -1;
}

void PushQueue(Queue& qu, elemtype data) {
    cout << data << " enQueue" << endl;
    node* p = qu.end->next;
    qu.end->next = NewNode(data);
    qu.end = qu.end->next;
    qu.end->next = p;
}

bool IsEmptyQueue(Queue qu) {
    if (qu.end->next == qu.end) {
        return true;
    }
    return false;
}

bool PopQueue(Queue& qu) {
    cout << qu.end->next->next->data << " deQueue" << endl;
    if (IsEmptyQueue(qu)) {
        return false;
    } else {
        node* h = qu.end->next;
        node* q = h->next;
        if (qu.end == h->next) {
            qu.end = h;
        }
        h->next = q->next;
        free(q);
        return true;
    }
}

void visit(node* q) { printf("%d ", q->data); }

void TraversalQueue(Queue qu) {
    cout << "Traversal Queue: ";
    if(IsEmptyQueue(qu)) {
        cout << "The Queue is empty" << '\n';
        return;
    }
    node* q = qu.end->next->next;
    while (q != qu.end->next) {
        visit(q);
        q = q->next;
    }
    cout << '\n';
}

int main() {
    Queue qu;
    InitQueue(qu);
    
    TraversalQueue(qu);
    PushQueue(qu, 3);
    TraversalQueue(qu);
    PushQueue(qu, 4);
    TraversalQueue(qu);
    PushQueue(qu, 8);
    TraversalQueue(qu);
    PopQueue(qu);
    TraversalQueue(qu);
    PushQueue(qu, 3);
    PushQueue(qu, 3);
    TraversalQueue(qu);
    PopQueue(qu);
    TraversalQueue(qu);
    PopQueue(qu);
    TraversalQueue(qu);
    PopQueue(qu);
    TraversalQueue(qu);
    PopQueue(qu);
    TraversalQueue(qu);
    return 0;
}
