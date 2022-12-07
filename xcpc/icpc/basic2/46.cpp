#include "stdio.h"
#include "math.h"

struct Student
{
    int sex;
    char name[9];
    int condition = 1;
};

int main()
{
    int sum = 0, n, need = 0;
    scanf("%d", &n);

    struct Student stu[99];

    for (int i = 0; i < n; i++)
    {
        scanf("%d %s", &stu[i].sex, stu[i].name);
    }


    for (int i = 0; sum < n / 2; i++)
    {
        need = fabs(stu[i].sex - 1);
        for (int j = n - 1;; j--)
        {
            if (stu[j].sex == need && stu[j].condition)
            {
                sum++;
                printf("%s %s\n", stu[i].name, stu[j].name);
                stu[j].condition = 0;
                break;
            }
        }
    }

    return 0;
}