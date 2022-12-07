#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, dic[1005], ser = 0, dim = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &dic[i]);
    }
    int flag = 1, i = 0, j = n - 1;
    while (i <= j)
    {
        if (dic[i] > dic[j])
        {
            if (flag % 2)
            {
                ser += dic[i];
            }
            else
            {
                dim += dic[i];
            }
            i++;
            flag++;
        }
        else
        {
            if (flag % 2)
            {
                ser += dic[j];
            }
            else
            {
                dim += dic[j];
            }
            j--;
            flag++;
        }
    }

    printf("%d %d\n", ser, dim);

    system("pause");
    return 0;
}
