#include "stdio.h"

int main()
{
    int card, n, coin = 0;
    scanf("%d%d", &card, &n);

    for (int i = 1; i <= n; i++)
    {
        if (i % 2)
        {
            coin = card;
            card = 0;
        }
        else
        {
            card = coin * 2;
            coin = 0;
        }
    }
    if (card)
    {
        printf("0 %d", card);
    }
    else
    {
        printf("1 %d", coin);
    }

    return 0;
}