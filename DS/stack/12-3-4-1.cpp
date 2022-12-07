// 将一个中缀表达式转换为后缀表达式，并通过后缀表达式求值

/*
6/3+(1*2-0*2)*3
*/

#include <iostream>
using namespace std;

#define elemtype char
#define MAXSIZE 1000

typedef struct stack {
    elemtype data[MAXSIZE];
    int top;
    stack() { top = 0; }
} sqStack;

string optind = "+-*/()#";
char Prior[8][8] = {
    {">><<<>>"}, {">><<<>>"}, {">>>><>>"}, {">>>><>>"},
    {"<<<<<= "}, {">>>> >>"}, {"<<<<< ="},
};

bool isnum(char c) { return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z'); }

int GetOptId(char opt) {
    for (int i = 0; i < optind.length(); i++) {
        if (optind[i] == opt) {
            return i;
        }
    }
    return 0;
}

bool PushStack(sqStack &st, elemtype e) {
    if (st.top >= MAXSIZE) {
        return false;
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

string change(string s) {
    string ans;
    sqStack opt;
    for (int i = 0; i < s.size(); i++) {
        if (isnum(s[i])) {
            ans += s[i];
        } else {
            if (EmptyStack(opt)) {
                PushStack(opt, s[i]);
                continue;
            }
            if (s[i] == '(') {
                PushStack(opt, s[i]);
            } else if (s[i] == ')') {
                while (TopStack(opt) != '(') {
                    ans += PopStack(opt);
                }
                PopStack(opt);
            } else {
                char pri = Prior[GetOptId(TopStack(opt))][GetOptId(s[i])];
                while (pri == '>' || pri == '=') {
                    ans += PopStack(opt);
                    if (EmptyStack(opt)) {
                        break;
                    }
                    pri = Prior[GetOptId(TopStack(opt))][GetOptId(s[i])];
                }
                PushStack(opt, s[i]);
            }
        }
    }
    while (!EmptyStack(opt)) {
        ans += PopStack(opt);
    }
    return ans;
}

int LittleCalu(int a, int b, char opt) {
    if (opt == '-') {
        return a - b;
    } else if (opt == '+') {
        return a + b;
    } else if (opt == '*') {
        return a * b;
    } else {
        return a / b;
    }
}

int GetExpressionValue(string s) {
    sqStack num;
    for (int i = 0; i < s.length(); i++) {
        if (isnum(s[i])) {
            PushStack(num, s[i]);
        } else {
            int e1 = PopStack(num) - '0';
            int e2 = PopStack(num) - '0';
            char ans = LittleCalu(e2, e1, s[i]) + '0';
            PushStack(num, ans);
        }
    }
    return TopStack(num) - '0';
}

int main() {
    string s;
    cin >> s;
    string suffix = change(s);
    cout << "后缀表达式: " << suffix << '\n';
    cout << s << " = " << GetExpressionValue(suffix) << '\n';
    return 0;
}
