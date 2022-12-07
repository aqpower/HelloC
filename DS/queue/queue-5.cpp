// 模拟渡口管理的实验，按照4辆货车一辆客车的顺序上荷载十辆车的船，客车不够则货车全部上船
// 25
#include <iostream>
#include <random>

#define elemtype CAR
#define QUEUE_MAX_SIZE 1024
#define STACK_MAX_SIZE 1024
#define CAR_MAX_SIZE 1024

using namespace std;

typedef struct CAR {
    int type;  // 0 为客车 1 为货车
    int ind;
} Car;

Car carData[CAR_MAX_SIZE];


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
int QueueSize(Queue qu) { return qu.rear - qu.front; }
void PushStack(Stack& st, elemtype e) { st.data[st.top++] = e; }
elemtype PopStack(Stack& st) { return st.data[--st.top]; }
bool IsEmptyStack(Stack& st) { return st.top == 0; }

string s[2] = {"客车", "货车"};
void InitCarData(int n) {
    uniform_int_distribution<int> u(0, 1);
    default_random_engine e(time(0));
    cout << "随机生成的车流:" << endl;
    for (int i = 0; i < n; i++) {
        carData[i].ind = i;
        carData[i].type = u(e);
        cout << carData[i].ind << "-" << s[carData[i].type] << ' ';
        if (i % 5 == 4) {
            cout << '\n';
        }
    }
}

void TravelQueue(Queue qu) {
    cout << "模拟渡口管理上车顺序如下：" << '\n';
    for (int i = qu.front; i < qu.rear; i++) {
        cout << qu.data[i].ind << "-" << s[qu.data[i].type] << '\n';
    }
}

void Solution(int n) {
    Queue quBus, quGoods;
    for (int i = 0; i < n; i++) {
        if (carData[i].type == 0) {
            PushQueue(quBus, carData[i]);
        } else {
            PushQueue(quGoods, carData[i]);
        }
    }
    while (!IsEmptyQueue(quBus) || !IsEmptyQueue(quGoods)) {
        Queue Boat;
        while (QueueSize(Boat) < 10 &&
               (!IsEmptyQueue(quBus) || !IsEmptyQueue(quGoods))) {
            int BUSPRI = 4, GOOD = 1;
            while (!IsEmptyQueue(quBus) && BUSPRI && QueueSize(Boat) < 10) {
                PushQueue(Boat, PopQueue(quBus));
                BUSPRI--;
            }
            while (!IsEmptyQueue(quGoods) && BUSPRI && QueueSize(Boat) < 10) {
                PushQueue(Boat, PopQueue(quGoods));
                BUSPRI--;
            }
            while (!IsEmptyQueue(quGoods) && GOOD && QueueSize(Boat) < 10) {
                PushQueue(Boat, PopQueue(quGoods));
                GOOD--;
            }
        }
        TravelQueue(Boat);
    }
}

int main() {
    int n;
    cin >> n;
    InitCarData(n);
    Solution(n);
    return 0;
}