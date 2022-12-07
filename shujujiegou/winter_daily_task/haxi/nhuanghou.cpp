#include <iostream>
#include <cstring>
using namespace std;
const int N = 12;
bool world[N][N];
bool live[N];
int n;
void print()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (world[i][j])
            {
                putchar('Q');
            }
            else
            {
                putchar('.');
            }
        }
        putchar('\n');
    }
    putchar('\n');
}
bool judge(int x, int y)
{
    int t = x, m = y;
    while (x - 1 > 0 && y - 1 > 0)
    {
        if (world[--x][--y])
        {
            return false;
        }
    }
    while (t - 1 >= 1 && m + 1 <= n)
    {
        if (world[--t][++m])
        {
            return false;
        }
    }
    return true;
}
void deal(int cnt)
{
    if (cnt > n)
    {
        print();
    }
    for (int i = 1; i <= n; i++)
    {
        if (!live[i] && judge(cnt, i))
        {
            live[i] = true;
            world[cnt][i] = true;
            deal(cnt + 1);
            live[i] = false;
            world[cnt][i] = false;
        }
    }
}
int main()
{

    cin >> n;
    memset(live, 0, sizeof(live));
    memset(world, 0, sizeof(world));
    deal(1);

    return 0;
}