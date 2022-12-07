#include "stdio.h"

char dic[10] = {'0', '1', '2','3','4','5','6','7','8','9'};
int ans[10] = {0};

int main()
{
    char world[1005];
    scanf("%s", world);
    for (int i = 0; world[i] != '\0';i++)
    {
        for (int j = 0; j < 10;j++)
        {
            if(world[i]==dic[j])
            {
                ans[j]++;
            }
        }
    }
    for (int i = 0; i < 10;i++)
    {
        if(ans[i])
            printf("%d:%d\n", i, ans[i]);
    }

        return 0;
}