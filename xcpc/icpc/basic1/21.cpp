#include "stdio.h"
#include "stdlib.h"

int main()
{
    printf("[1] apple\n\
[2] pear\n\
[3] orange\n\
[4] grape\n\
[0] exit\n");

    int num[20], temp;
    for (int i = 0; i < 5; i++)
        scanf("%d ", &num[i]);
    for (int i = 0; i < 5; i++)
    {
        temp = num[i];
        if (temp == 0)
            break;
        printf("price = %.2f\n", temp == 1 ? 3.00 : temp == 2 ? 2.50
                                                : temp == 3   ? 4.10
                                                : temp == 4   ? 10.20
                                                              : 0.00);
    }

    system("pause");
    return 0;
}
