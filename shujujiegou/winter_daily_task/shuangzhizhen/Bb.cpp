#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, date[305], ans[305];
        scanf("%d", &n);
        int i = 0, j = n - 1;
        for (int k = 0; k < n; k++)
        {
            scanf("%d", &date[k]);
        }
        for (int k = 0; k < n; k++)
        {
            if (k % 2)
            {
                ans[k] = date[j];
                j--;
            }
            else
            {
                ans[k] = date[i];
                i++;
            }
        }

        for (int k = 0; k < n; k++)
        {
            printf("%d ", ans[k]);
        }
        printf("\n");
    }

    return 0;
}