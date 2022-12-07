#include "stdio.h"
#include "string.h"

int delete_sub_str(const char *world, const char *del, char *result)
{
    int i, j = 0, time = 0, flag = 0, dindex = 0, index[99] = {0};
    for (i = 0; i < 99; i++)
        index[i] = 99;
    for (i = 0; world[i] != '\0'; i++)
    {
        if (world[i] == del[j])
        {
            int di = i, dj = j;
            while (world[++di] == del[++dj])
            {
                if (del[dj + 1] == '\0')
                {
                    flag = 1;
                }
            }
        }
        if (flag)
        {
            index[dindex++] = i;
            time++;
            flag = 0;
        }
    }
    for (i = 0; world[i] != '\0'; i++)
    {
        if (i == index[j])
        {
            i += strlen(del) - 1;
            j++;
            continue;
        }
        printf("%c", world[i]);
    }
    return time;
}

int main()
{
    char world[200];
    char del[200], result[200];
    gets(world);
    gets(del);

    int time = delete_sub_str(world, del, result);

    printf("\n%d", time);

    return 0;
}