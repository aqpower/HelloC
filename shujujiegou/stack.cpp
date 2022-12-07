#include <iostream>
using namespace std;
int a[10000], TOP = -1;
void clear()
{
    TOP = -1;
}
int size()
{
    return TOP + 1;
}
bool empty()
{
    return TOP == -1 ? true : false;
}
void push(int x)
{
    a[++TOP] = x;
}
void pop()
{
    TOP--;
}
int top()
{
    return a[TOP];
}
int main()
{
    for (int i = 0; i < 26; i++)
    {
        push(i);
    }
    cout << size() << endl;
    for (int i = 0; i < 26; i++)
    {
        if (!empty())
        {
            cout << top() << '\n';
            pop();
        }
    }
    return 0;
}