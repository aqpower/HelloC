#include "stdio.h"
#include "stdlib.h"

int main()
{
    int v, limv;
    scanf("%d%d", &v, &limv);

    double rate = 100.0 * (v - limv) / limv;
    if (rate < 10)
        printf("OK\n");
    else if (rate < 50)
        printf("Exceed %.0f%%. Ticket 200\n", rate);
    else
        printf("Exceed %.0f%%. License Revoked\n", rate);

    system("pause");
    return 0;
}
