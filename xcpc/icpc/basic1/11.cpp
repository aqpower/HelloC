#include "stdio.h"
#include "stdlib.h"
#include "math.h"

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i <= n; i++)
    {
        printf("pow(3,%d) = %.0f\n", i, pow(3, i));
    }

    system("pause");
    return 0;
}

//原来pow使用后类型自动转化为了浮点型！！！
