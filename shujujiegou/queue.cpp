#include <iostream>
#include <queue>
#include <string>
using namespace std;
int q[1000], front = -1, rear = -1;
struct fruit {

    string name;
    int price;
    friend bool operator<(fruit f1, fruit f2)
    {
        return f1.price > f2.price;
    }
} f[100];
bool empty()

{
    return front == rear ? true : false;
}
void push(int x)
{
    q[++rear] = x;
}
void pop() //! do it after judge the size or the value of empty
{
    front--;
}
int get_front()
{
    return q[front + 1];
}
int get_rear()
{
    return q[rear];
}
int size()
{
    return rear - front;
}
int main()
{
    queue<int> q;
    priority_queue<fruit> p;
    // priority_queue<int, vector<int>,greater<int>> p;
    for (int i = 0; i < 26; i++) {
        f[i].name = 'a' + i;
        f[i].price = 26 - i;
        p.push(f[i]);
    }
    // for (int i = 1; i <= 5; i++)
    // {
    // q.push(i);
    //     p.push(100 - i);
    // }
    for (int i = 1; i <= 26; i++) {
        // cout << q.back() << ' ';
        // q.pop();
        cout << p.top().name << ' ' << p.top().price << '\n';
        p.pop();
    }
    return 0;
}