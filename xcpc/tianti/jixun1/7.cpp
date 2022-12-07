#include "stdio.h"

int dic[100];

int main()
{
    int n, line, dn;
    char ch;
    dic[0] = 1;
    scanf("%d %c", &n, &ch);
    for (int i = 1; i < 100; i++)
    {
        dic[i] = dic[i - 1] + (2 * i + 1) * 2;
    }
    for (int i = 0; i < 100; i++)
    {
        if (n == dic[i])
        {
            dn = 0;
            line = i + 1;
            break;
        }
        else if (n < dic[i])
        {
            dn = n - dic[i - 1];
            line = i;
            break;
        }
    }
    for (int i = line; i > 0; i--)
    {
        int j = 2 * i - 1;
        int k = line - i;
        while (k--)
            printf(" ");
        while (j--)
            printf("%c", ch);
        printf("\n");
    }
    for (int i = 1; i < line; i++)
    {
        int j = 2 * i + 1;
        int k = line - i - 1;
        while (k--)
            printf(" ");
        while (j--)
            printf("%c", ch);
        printf("\n");
    }
    printf("%d\n", dn);

    return 0;
}