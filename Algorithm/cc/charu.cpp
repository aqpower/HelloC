#include "stdio.h"

int main()
{
    int i, n, a[99];
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (int i = 1; i < n; i++) //写了一个插入排序，权当巩固学习成果吧，什么时候写个归并排序来...
    {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }

    return 0;
}