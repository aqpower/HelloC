// 利用队列输出杨辉三角

#include <iostream>
using namespace std;

#define elemtype int
#define QUEUE_MAX_SIZE 1024

typedef struct QUEUE {
    elemtype data[QUEUE_MAX_SIZE];
    int front;
    int rear;
    QUEUE() : front(0), rear(0) {}
} Queue;

void PushQueue(Queue& qu, elemtype e) { qu.data[qu.rear++] = e; }
elemtype PopQueue(Queue& qu) { return qu.data[qu.front++]; }

Queue Yanghui;
void InitYanghui(int n) {
    PushQueue(Yanghui, 1);
    PushQueue(Yanghui, 1);
    PushQueue(Yanghui, 1);
    for (int i = 3; i <= n; i++) {
        int tar = i - 2;
        PushQueue(Yanghui, 1);
        while(tar--){
            int indOn = Yanghui.rear - i + 1;
            PushQueue(Yanghui, Yanghui.data[indOn] + Yanghui.data[indOn - 1]);
        }
        PushQueue(Yanghui, 1);
    }
}

int GetValue(int n, int m) { return Yanghui.data[n * (n - 1) / 2 + m - 1]; }

void PrintYanghui(int n) {
    InitYanghui(n);
    for (int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            cout << GetValue(i, j) << '\t';
        }
        cout << '\n';
    }
}

int main() {
    int n;
    cin >> n;
    PrintYanghui(n);
    return 0;
}

// 做得不是很完美，有一种为了用队列而用队列的感觉，因为根本没用到队列的特性吧。
// 我是用线性表