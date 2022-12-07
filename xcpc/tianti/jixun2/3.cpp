#include "stdio.h"
#include "string.h"

int main()
{
    int n;
    scanf("%d", &n);
    while (n--)
    {
        int dnum = 0, dlet = 0, dright = 1;
        char pass[85];
        scanf("%s", pass);
        if (strlen(pass) < 6)
        {
            printf("Your password is tai duan le.\n");
        }
        else
        {
            for (int i = 0; pass[i] != '\0'; i++)
            {
                if (pass[i] >= '0' && pass[i] <= '9')
                {
                    dnum = 1;
                }
                else if(pass[i]>='a'&&pass[i]<='z'||pass[i]>='A'&&pass[i]<='Z')
                {
                    dlet = 1;
                }
                else if(pass[i]!='.')
                {
                    dright = 0;
                }
            }
            if(!dright)
            {
                printf("Your password is tai luan le.\n");
            }
            else if(!dnum)
            {
                printf("Your password needs shu zi.\n");
            }
            else if(!dlet)
            {
                printf("Your password needs zi mu.\n");
            }
            else
            {
                printf("Your password is wan mei.\n");
            }
        }
    }

    return 0;
}