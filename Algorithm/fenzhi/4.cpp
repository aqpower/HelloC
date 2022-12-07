#include "stdio.h"

int mySearch(int left, int right, int x);
int findmax(int n, int x);
int date[100000];

int main()
{
    int n, x;
    scanf("%d%d", &n, &x);
    for (int i = 0; i < n; i++)
        scanf("%d", &date[i]);
    int ans = mySearch(0, n, x);
    if (ans != -1)
    {
        printf("%d %d\n", ans, ans);
    }
    else
    {
        int index = findmax(n, x);
        if (index == 0)
        {
            printf("-1 0\n");
        }
        else if (index == -1)
        {
            printf("%d %d\n", n - 1, n);
        }
        else
        {
            printf("%d %d\n", index - 1, index);
        }
    }

    return 0;
}

int mySearch(int left, int right, int x)
{
    int pos;

    int middle = (left + right) / 2;
    if (date[middle] == x)
        pos = middle;
    else if (left == right)
        pos = -1;
    else if (date[middle] > x)
        pos = mySearch(0, middle - 1, x);
    else
        pos = mySearch(middle + 1, right, x);
    return pos;
}

int findmax(int n, int x)
{
    int i = 0;
    for (; i < n; i++)
    {
        if (date[i] > x)
            return i;
    }
    return -1;
}