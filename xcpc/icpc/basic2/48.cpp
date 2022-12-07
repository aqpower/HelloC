#include "stdio.h"

int main()
{
    int N;
    scanf("%d", &N);
    getchar();

    while (N--)
    {
        char sex;
        double h;
        scanf("%c %lf", &sex, &h);
        getchar();
        printf("%.2f\n", sex == 'F' ? h * 1.09 : h / 1.09);
    }
    return 0;
}