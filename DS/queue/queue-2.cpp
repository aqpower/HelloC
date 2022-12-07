// 随机生成迷宫，并通过队列实现广度优先搜索进而实现迷宫算法求最短路径
// 9 9 
#include <ctime>
#include <iostream>
#include <random>
using namespace std;

#define elemtype Point
#define QUEUE_MAX_SIZE 1024
#define STACK_MAX_SIZE 1024

typedef struct POINT {
    int i;
    int j;
    int pre;
    POINT(int i_ = 0, int j_ = 0, int pre_ = 0) : i(i_), j(j_),  pre(pre_) {}
} Point;

typedef struct QUEUE {
    elemtype data
        [QUEUE_MAX_SIZE];  // 记得提供POINT的无参构造函数，或者说是提供缺省值，否则会出错
    int front;
    int rear;
    QUEUE() {
        front = 0;
        rear = 0;
    }
} Queue;

typedef struct STACK {
    elemtype data[STACK_MAX_SIZE];
    int top;
    STACK() : top(0) {}
} Stack;

int MAZE[1005][1005];
int MARK[1005][1005];
int Direction[8][2] = {{0, 1},  {1, 1},   {1, 0},  {1, -1},
                       {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};

bool IsEmptyQueue(Queue qu) {
    if (qu.front == qu.rear) {
        return true;
    }
    return false;
}

void PushQueue(Queue& qu, elemtype e) { qu.data[qu.rear++] = e; }
elemtype PopQueue(Queue& qu) { return qu.data[qu.front++]; }
elemtype FrontQueue(Queue qu) { return qu.data[qu.front]; }
int GetFrontIndex(Queue qu) { return qu.front; }
void PushStack(Stack& st, elemtype e) { st.data[st.top++] = e; }
elemtype PopStack(Stack& st) { return st.data[--st.top]; }
bool IsEmptyStack(Stack st) { return st.top == 0; }
int StackSize(Stack st) { return st.top; }

void PaintMAZE(int m, int n) {
    uniform_int_distribution<int> u(0, 1);
    default_random_engine e(time(0));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            MAZE[i][j] = u(e);
        }
    }
    MAZE[1][1] = 0, MAZE[m][n] = 0;
    for (int i = 0; i < m + 2; i++) {
        MAZE[i][0] = 1;
        MAZE[i][n + 1] = 1;
    }
    for (int j = 0; j < n + 2; j++) {
        MAZE[0][j] = 1;
        MAZE[m + 1][j] = 1;
    }
}

void PrintMAZE(int m, int n) {
    cout << "随机生成模拟迷宫如下图：" << endl;
    for (int i = 0; i < m + 2; i++) {
        for (int j = 0; j < n + 2; j++) {
            cout << MAZE[i][j];
        }
        cout << '\n';
    }
}

void PrintPoint(Point p) { cout << "(" << p.i << "," << p.j << ")"; }

Stack BackTrace(int m, int n, int id, Queue& qu) {
    Stack st;
    PushStack(st, Point(m, n));
    while (id != -1) {
        PushStack(st, qu.data[id]);
        id = qu.data[id].pre;
    }
    return st;
}
void TraversalStack(Stack st) {
    int cnt = 0;
    while (!IsEmptyStack(st)) {
        PrintPoint(PopStack(st));
        cnt++;
        if (cnt % 3 == 0) {
            cout << '\n';
        }
    }
}

void FindRoad(int m, int n) {
    int mins = 1e9;
    Stack ansSt;
    Queue qu;
    PushQueue(qu, Point(1, 1, -1));
    while (!IsEmptyQueue(qu)) {
        Point top = PopQueue(qu);
        int nx = top.i, ny = top.j;
        MARK[nx][ny] = 1;
        for (int i = 0; i < 8; i++) {
            int tox = nx + Direction[i][0];
            int toy = ny + Direction[i][1];
            if (tox == m && toy == n) {
                Stack t = BackTrace(m, n, GetFrontIndex(qu) - 1, qu);
                int size = StackSize(t);
                if (size < mins) {
                    mins = size;
                    ansSt = t;
                }
            }
            if (MAZE[tox][toy] == 0 && MARK[tox][toy] == 0) {
                PushQueue(qu, Point(tox, toy, GetFrontIndex(qu) - 1));
            }
        }
    }
    if (mins != 1e9) {
        cout << "存在长度为" << mins << "的最短路径:" << '\n';
        TraversalStack(ansSt);
    } else {
        cout << "No path!" << '\n';
    }
}

int main() {
    int m, n;
    cin >> m >> n;
    PaintMAZE(m, n);
    PrintMAZE(m, n);
    FindRoad(m, n);
    return 0;
}