#include "stdio.h"
#include "stdlib.h"

void myPut(int n);

int main()
{
    int rand, n, i, t, count = 0;
    scanf("%d%d", &rand, &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &t);
        if (t < 0)
            break;
        count++;
        if (t > rand)
            printf("Too big\n");
        else if (t < rand)
            printf("Too small\n");
        else
        {
            myPut(count);
            system("pause");
            return 0;
        }
    }
    printf("Game Over\n");
    system("pause");
    return 0;
}

void myPut(int n)
{
    if (n == 1)
        printf("Bingo!\n");
    else if (n <= 3)
        printf("Lucky You!\n");
    else
        printf("Good Guess!\n");
}
