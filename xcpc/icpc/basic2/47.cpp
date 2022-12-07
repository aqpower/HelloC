#include "stdio.h"

int value[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
char check[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};

int main()
{
    int n, pass = 0;
    scanf("%d", &n);
    getchar();

    int record = n;

    while (n--)
    {
        char ident[25];
        gets(ident);
        int z, sum = 0;
        for (int i = 0; i < 18; i++)
        {
            if (i < 17)
            {
                if (ident[i] < '0' || ident[i] > '9')
                {
                    puts(ident);
                    break;
                }
                sum += (ident[i] - '0') * value[i];
            }
            else
            {
                z = sum % 11;
                if (ident[i] == check[z])
                {
                    pass++;
                    break;
                }
                else
                {
                    puts(ident);
                }
            }
        }
    }

    if (pass == record)
        printf("All passed\n");

    return 0;
}