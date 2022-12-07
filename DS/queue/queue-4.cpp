/*
利用栈和队列判断字符串是否是回文序列

Input1:
ababa

Input2:
abcdebac
*/
#include <iostream>
using namespace std;

#define elemtype char
#define QUEUE_MAX_SIZE 1024
#define STACK_MAX_SIZE 1024

typedef struct QUEUE {
    elemtype data[QUEUE_MAX_SIZE];
    int front;
    int rear;
    QUEUE() : front(0), rear(0) {}
} Queue;

typedef struct STACK {
    elemtype data[STACK_MAX_SIZE];
    int top;
    STACK() : top(0) {}
} Stack;

void PushQueue(Queue& qu, elemtype e) { qu.data[qu.rear++] = e; }
elemtype PopQueue(Queue& qu) { return qu.data[qu.front++]; }
bool IsEmptyQueue(Queue& qu) { return qu.front == qu.rear; }
void PushStack(Stack& st, elemtype e) { st.data[st.top++] = e; }
elemtype PopStack(Stack& st) { return st.data[--st.top]; }
bool IsEmptyStack(Stack& st) { return st.top == 0; }

bool judge(char* s) {
    Stack st;
    Queue qu;
    for (int i = 0; s[i] != '\0'; i++) {
        PushQueue(qu, s[i]);
        PushStack(st, s[i]);
    }
    while (!IsEmptyStack(st)) {
        if (PopStack(st) != PopQueue(qu)) {
            return false;
        }
    }
    return true;
}

int main() {
    char s[100];
    cin >> s;
    if(judge(s)){
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n';
    }
    return 0;
}