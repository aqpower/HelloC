#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, temp;
    scanf("%d", &n);
    int a[n];
    for (int k = 0; k < n; k++)
        scanf("%d", &a[k]);

    for (i = 0; i < n - 1; i++)
    {
        for (j = i; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    system("pause");
    return 0;
}
