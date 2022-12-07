// 表达式求值
#include <iostream>

using namespace std;

#define elemtype char
#define MAXSIZE 100

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

bool isnum(char c) { return (c >= '0' && c <= '9'); }

bool PushStack(sqStack &st, int e) {
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

int GetOptId(char opt) {
    for (int i = 0; i < optind.length(); i++) {
        if (optind[i] == opt) {
            return i;
        }
    }
    return 0;
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

int Calu(string s) {
    sqStack num, opt;
    int len = s.length();
    for (int i = 0; i < len; i++) {
        if (isnum(s[i])) {
            PushStack(num, s[i]);
        } else {
            if (!EmptyStack(opt)) {
                char pri = Prior[GetOptId(TopStack(opt))][GetOptId(s[i])];
                if (pri == '<') {
                    PushStack(opt, s[i]);
                } else if (pri == '=') {
                    PopStack(opt);
                } else {
                    while (Prior[GetOptId(TopStack(opt))][GetOptId(s[i])] ==
                           '>') {
                        int num1 = PopStack(num) - '0';
                        int num2 = PopStack(num) - '0';
                        char nowopt = PopStack(opt);
                        int ans = LittleCalu(num2, num1, nowopt);
                        char cc = char(ans + '0');
                        PushStack(num, cc);
                    }
                    if (Prior[GetOptId(TopStack(opt))][GetOptId(s[i])] == '=') {
                        PopStack(opt);
                    } else {
                        PushStack(opt, s[i]);
                    }
                }
            } else {
                PushStack(opt, s[i]);
            }
        }
    }
    return (TopStack(num)-'0');
}

int main() {
    string s;
    cin >> s;
    cout << Calu(s) << '\n';
    return 0;
}