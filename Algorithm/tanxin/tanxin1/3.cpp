#include "stdio.h"

struct BREAD
{
    int num;
    int total_price;
    double unit_price;
} bread[1000];

int main()
{
    int N, D;
    scanf("%d%d", &N, &D);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &bread[i].num);
    }
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &bread[i].total_price);
        bread[i].unit_price = 1.0 * bread[i].total_price / bread[i].num;
    }
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (bread[i].unit_price < bread[j].unit_price)
            {
                BREAD t = bread[i];
                bread[i] = bread[j];
                bread[j] = t;
            }
        }
    }
    int i = 0;
    double maximum_benefit;
    while (D > 0)
    {
        if (D >= bread[i].num)
        {
            maximum_benefit += bread[i].total_price;
            D -= bread[i].num;
            i++;
        }
        
        else
        {
            maximum_benefit += bread[i].unit_price * D;
            break;
        }
    }
    printf("%.2f\n", maximum_benefit);

    return 0;
}