#include "stdio.h"
#include "stdlib.h"

int date[99], cnt = 0;

int search(int left, int right, int x);

int main()
{
    int i, j, n, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &date[i]);
    }
    scanf("%d", &x);

    printf("%d\n", search(0, n - 1, x));
    printf("%d\n", cnt);
    system("pause");
    return 0;
}

int search(int left, int right, int x)
{
    cnt++;
    int pos;

    int middle = (left + right) / 2;
    if (date[middle] == x)
    {
        pos = middle;
    }
    else if (left == right)
    {
        return -1;
    }
    else if (date[middle] > x)
    {
        pos = search(left, middle - 1, x);
    }
    else
    {
        pos = search(middle + 1, right, x);
    }

    return pos;
}

