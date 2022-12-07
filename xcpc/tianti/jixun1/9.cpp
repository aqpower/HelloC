#include "stdio.h"

struct THING
{
    int size;
    int live = 0;
} thing[1005];

int main()
{
    int n, full = 100, dbox = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &thing[i].size);
    while (1)
    {
        for (int i = 0; i < n; i++)
        {
            if (thing[i].size <= full && thing[i].live == 0)
            {
                thing[i].live = dbox;
                full -= thing[i].size;
            }
        }

        int flag = 1;
        for (int i = 0; i < n; i++)
        {
            if (thing[i].live == 0)
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            break;
        }
        dbox++;
        full = 100;
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d %d\n", thing[i].size, thing[i].live);
    }
    printf("%d\n", dbox);

    return 0;
}
