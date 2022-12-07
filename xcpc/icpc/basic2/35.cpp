#include "stdio.h"

struct Student
{
    char num[9];
    char name[99];
    int score;
};

int main()
{
    int sum = 0, i, n;
    struct Student world[99];
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%s%s%d", world[i].num, world[i].name, &world[i].score);
        sum += world[i].score;
    }
    printf("%.2f\n", 1.0 * sum / n);
    for (i = 0; i < n; i++)
    {
        if (world[i].score < (sum / n))
        {
            printf("%s %s\n", world[i].name, world[i].num);
        }
    }

    return 0;
}
