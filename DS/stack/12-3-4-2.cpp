// 利用栈将十进制数转换为二进制数
#include <iostream>

#define elemtype int
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

string DecimalToBinary(int n) { string ans;
    sqStack st;
    while(n){
        PushStack(st, n % 2);
        n /= 2;
    }
    while(!EmptyStack(st)) {
        ans += char(PopStack(st) + '0');
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    cout << DecimalToBinary(n) << endl;
    return 0;
}


/* 
9
 */