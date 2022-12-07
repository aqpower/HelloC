#include "stdio.h"

typedef struct book
{
    char name[20];
    char bir[20];
    char sex;
    char gu[20];
    char phone[20];
} BOOK;

int main()
{
    int n;
    scanf("%d", &n);
    getchar();
    BOOK a[15];
    for (int i = 0; i < n; i++)
    {
        scanf("%s %s %c %s %s", a[i].name, a[i].bir, &a[i].sex, a[i].gu, a[i].phone);
        getchar();
    }
    int k;
    scanf("%d", &k);
    while (k--)
    {
        int b;
        scanf("%d", &b);
        if (b > n - 1 || b < 0)
            printf("Not Found\n");
        else
        {
            printf("%s %s %s %c %s\n", a[b].name, a[b].gu, a[b].phone, a[b].sex, a[b].bir);
        }
    }

    return 0;
}