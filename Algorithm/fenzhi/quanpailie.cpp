#include <iostream>

using namespace std;

int n, p[20];
int judge[20] = {false};

void printquan(int index) //填第index个数
{
    if (index == n + 1) //递归边界
    {
        for (int i = 1; i <= n; i++)
            cout << p[i] << ' ';
        putchar('\n');
        return;
    }
    for (int i = 1; i <= n; i++) //枚举1....n填入这个位置
    {
        if (judge[i] == false)
        {
            p[index] = i;
            judge[i] = true;
            printquan(index + 1);
            judge[i] = false;
        }
    }
}

int main()
{
    n = 3;
    printquan(1);

    return 0;
}