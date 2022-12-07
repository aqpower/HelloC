// 一元稀疏多项式计算器
#include <algorithm>
#include <iostream>
using namespace std;

typedef struct node {
    int ind;
    int exp;
    struct node *next;
} node, *linklist;

// 打印多项式
void PrintCalu(linklist h) {
    linklist q = h->next;
    if (!q) {
        cout << "0";
    }
    while (q) {
        if (q->ind != 1) {
            cout << q->ind;
        }
        cout << "x";
        if (q->exp != 1) {
            cout << "^" << q->exp;
        }
        if (q->next && q->next->ind > 0) {
            cout << "+";
        }
        q = q->next;
    }
    cout << endl;
}

linklist NewNode(int ind, int exp) {
    linklist p = (linklist)malloc(sizeof(node));
    p->ind = ind;
    p->exp = exp;
    return p;
}

// 通过字符串创建多项式链表
void CreateLinklist(linklist &h, string s) {
    h = (linklist)malloc(sizeof(node));
    h->next = NULL;
    linklist p = h;
    int length = s.size();
    for (int i = 0; i < length; i++) {
        if (s[i] == 'x') {
            string sind;
            string sexp;
            int iind = i;
            while (iind - 1 >= 0 && s[iind - 1] != '+' && s[iind - 1] != '-') {
                sind += s[iind - 1];
                iind--;
            }
            if (iind - 1 >= 0 && s[iind - 1] == '-') {
                sind += '-';
            }
            iind = i;
            while (iind + 1 < length && s[iind + 1] != '+' &&
                   s[iind + 1] != '-') {
                if (s[iind + 1] != '^') {
                    sexp += s[iind + 1];
                }
                iind++;
            }
            if (sind.empty()) {
                sind += "1";
            }
            if (sind.size() == 1 && sind[0] == '-') {
                sind += "1";
            } else {
                reverse(sind.begin(), sind.end());
            }
            if (sexp.empty()) {
                sexp += "1";
            }
            p->next = NewNode(stoi(sind), stoi(sexp));
            p = p->next;
        }
    }
    p->next = NULL;
}

// 返回值为两个多项式相加的链表
linklist ADD(linklist h1, linklist h2) {
    linklist h = (linklist)malloc(sizeof(node));
    h->next = NULL;
    linklist p = h;
    linklist qa = h1->next;
    linklist qb = h2->next;
    while (qa && qb) {
        if (qa->exp == qb->exp) {
            if (qa->ind + qb->ind) {
                p->next = NewNode(qa->ind + qb->ind, qa->exp);
                p = p->next;
            }
            qa = qa->next;
            qb = qb->next;
        } else if (qa->exp < qb->exp) {
            p->next = NewNode(qa->ind, qa->exp);
            qa = qa->next;
            p = p->next;
        } else {
            p->next = NewNode(qb->ind, qb->exp);
            qb = qb->next;
            p = p->next;
        }
    }
    while (qa) {
        p->next = NewNode(qa->ind, qa->exp);
        qa = qa->next;
        p = p->next;
    }
    while (qb) {
        p->next = NewNode(qb->ind, qb->exp);
        qb = qb->next;
        p = p->next;
    }
    p->next = NULL;
    return h;
}

// 返回值为两个多项式相减的链表
linklist MINUS(linklist h1, linklist h2) {
    linklist h = (linklist)malloc(sizeof(node));
    h->next = NULL;
    linklist p = h;
    linklist qa = h1->next;
    linklist qb = h2->next;
    while (qa && qb) {
        if (qa->exp == qb->exp) {
            if (qa->ind - qb->ind) {
                p->next = NewNode(qa->ind - qb->ind, qa->exp);
                p = p->next;
            }
            qa = qa->next;
            qb = qb->next;
        } else if (qa->exp < qb->exp) {
            p->next = NewNode(qa->ind, qa->exp);
            p = p->next;
            qa = qa->next;
        } else {
            p->next = NewNode(-qb->ind, qb->exp);
            p = p->next;
            qb = qb->next;
        }
    }
    while (qa) {
        p->next = NewNode(qa->ind, qa->exp);
        qa = qa->next;
        p = p->next;
    }
    while (qb) {
        p->next = NewNode(-qb->ind, qb->exp);
        qb = qb->next;
        p = p->next;
    }
    p->next = NULL;
    return h;
}

int main() {
    string spx, sqx;
    cin >> spx >> sqx;
    linklist px, qx;
    CreateLinklist(px, spx);
    CreateLinklist(qx, sqx);
    cout << "CreateLinklist Successfully: " << endl;
    cout << "Pn(X): ";
    PrintCalu(px);
    cout << "Qm(X): ";
    PrintCalu(qx);
    linklist addList = ADD(px, qx);
    cout << "Pn(X)+Qm(x): ";
    PrintCalu(addList);
    linklist minusList = MINUS(px, qx);
    cout << "Pn(X)-Qm(x): ";
    PrintCalu(minusList);
    return 0;
}

/*
x+2x^3+4x^6
x+2x^3+4x^6

x^2+2x^3+4x^6
x+3x^2+3x^3

-x^2+2x^3+4x^6
x+x^2-3x^3

x^99
x-6x^4
*/