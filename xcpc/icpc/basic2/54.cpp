#include "stdio.h"
#include "string.h"

int main()
{
    int n, i;

    char pass[99];
    scanf("%d", &n);
    getchar();

    while (n--)
    {
        int dnum = 1, dlet = 1, dpoint = 1, dfal = 0;
        gets(pass);
        if (strlen(pass) < 6)
        {
            printf("Your password is tai duan le.\n");
            continue;
        }
        for (i = 0; pass[i] != '\0'; i++)
        {
            if (pass[i] >= 'A' && pass[i] <= 'Z' || pass[i] >= 'a' && pass[i] <= 'z')
                dlet = 0;
            else if (pass[i] >= '0' && pass[i] <= '9')
                dnum = 0;
            else if (pass[i] == '.')
                dpoint = 0;
            else
                dfal = 1;
        }
        if (dfal)
        {
            printf("Your password is tai luan le.\n");
        }
        else if (dnum)
        {
            printf("Your password needs shu zi.\n");
        }
        else if (dlet)
        {
            printf("Your password needs zi mu.\n");
        }
        else
        {
            printf("Your password is wan mei.\n");
        }
    }

    return 0;
}