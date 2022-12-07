#include "stdio.h"

int myNum(char *a);

int main()
{
    int flag = 1, cnt;
    char str[999];
    gets(str);
    cnt = myNum(str);
    printf("%d\n", cnt);
    return 0;
}

int myNum(char *a)
{
    int flag = 1, sum = 0;
    for (int i = 0; *(a + i) != '\0'; i++)
    {
        if (*(a + i) != ' ')
        {
            if (flag)
            {
                sum++;
                flag = 0;
            }
        }
        else
            flag = 1;
    }
    return sum;
}
