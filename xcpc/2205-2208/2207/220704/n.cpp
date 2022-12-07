#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <iostream>
using namespace std;
bool judge(int x)
{
    if (x == 2 || x == 3)
        return true;
    else
    {
        for (int i = 2; i <= sqrt(x); i++)
        {
            if (x % i == 0)
                return false;
        }
        return true;
    }
}
int main()
{
    int n, m, i, j, k;
    while (scanf("%d", &n) != EOF)
    {
        if (judge(n))
            printf("1\n%d\n", n);
        else if (judge(n - 2))
            printf("2\n2 %d\n", n - 2);
        else if (judge(n - 4))
            printf("3\n2 2 %d\n", n - 4);
        else
        {
            for (i = n - 3; i >= n - 300 && i >= 1; i--)
            {
                if (judge(i))
                {
                    k = i;
                    break;
                }
            }
            m = n - i;
            if (judge(m))
                printf("2\n%d %d", m, k);
            else
            {
                for (i = 2; i <= m; i++)
                {
                    if (judge(i) && judge(m - i))
                    {
                        printf("3\n%d %d %d\n", i, m - i, k);
                        break;
                    }
                }
            }
        }
    }
    return 0;
}