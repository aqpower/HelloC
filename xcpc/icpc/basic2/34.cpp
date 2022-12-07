#include "stdio.h"

struct Information
{
    char name[20];
    double basic;
    double variety;
    double pay;
};

int main()
{
    struct Information world[500] = {0};
    int i, n;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%s%lf%lf%lf", world[i].name, &world[i].basic, &world[i].variety, &world[i].pay);
    }
    for (i = 0; i < n; i++)
    {
        printf("%s %.2f\n", world[i].name, world[i].basic + world[i].variety - world[i].pay);
    }
    return 0;
}
