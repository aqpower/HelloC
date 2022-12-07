#include <stdio.h>
#include <string.h>
int judge(char *str);

typedef struct ti
{
    char des[505];
    int easy;
} ti;
char x1[5] = "easy", x2[8] = "qiandao";
int main()
{
    int i, n, m, cnt = 0;
    ti str[30];
    scanf("%d%d", &n, &m);
    getchar();
    for (i = 0; i < n; i++)
    {
        gets(str[i].des);
        str[i].easy = judge(str[i].des);
    }
    for (i = 0; i < n; i++)
    {
        if (!str[i].easy)
            cnt++;
        if (cnt == m)
        {
            i++;
            break;
        }
    }
    for (; i < n; i++)
    {
        if (!str[i].easy)
        {
            puts(str[i].des);
            return 0;
        }
    }
    puts("Wo AK le");
    return 0;
}

int judge(char *str)
{
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        int j = 0;
        while (str[i] == x1[j])
        {
            if (str[i + 1] == '\0')
                return 0;
            i++, j++;
            if (j == 4)
                return 1;
        }
        j = 0;
        while (str[i] == x2[j])
        {
            if (str[i + 1] == '\0')
                return 0;
            i++, j++;
            if (j == 7)
                return 1;
        }
    }
    return 0;
}