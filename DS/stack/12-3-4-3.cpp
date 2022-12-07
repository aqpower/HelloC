// 括号匹配问题

/* 

7*{2+[6-2*(3+5)]}-9+8

*/
#include <iostream>

#define elemtype char
#define MAXSIZE 1000

using namespace std;

typedef struct stack {
    elemtype *data;
    int top;
    stack() {
        top = 0;
        data = (elemtype *)malloc(sizeof(elemtype) * MAXSIZE);
    }
} sqStack;

bool PushStack(sqStack &st, elemtype e) {
    if (st.top >= MAXSIZE) {
        st.data = (elemtype *)realloc(st.data, sizeof(elemtype) * MAXSIZE);
    }
    st.data[st.top++] = e;
    return true;
}

elemtype TopStack(sqStack st) {
    if (st.top) {
        return st.data[st.top - 1];
    } else {
        return -1;
    }
}

elemtype PopStack(sqStack &st) {
    if (st.top) {
        return st.data[--st.top];
    } else {
        return -1;
    }
}

bool EmptyStack(sqStack st) { return (st.top == 0); }

bool judge(string s) {
    sqStack OPTR;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            PushStack(OPTR, s[i]);
        }
        if (s[i] == ')') {
            if (TopStack(OPTR) == '(') {
                PopStack(OPTR);
            } else {
                return false;
            }
        }
        if (s[i] == ']') {
            if (TopStack(OPTR) == '[') {
                PopStack(OPTR);
            } else {
                return false;
            }
        }
        if (s[i] == '}') {
            if (TopStack(OPTR) == '{') {
                PopStack(OPTR);
            } else {
                return false;
            }
        }
    }
    if (EmptyStack(OPTR)) {
        return true;
    }
    return false;
}

int main() {
    string s;
    cin >> s;
    if (judge(s)) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }
    return 0;
}

