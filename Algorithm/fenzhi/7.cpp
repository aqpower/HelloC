#include "stdio.h"

int date[100000];

int main()
{
    int n, l;
    scanf("%d%d", &n, &l);
    for (int i = 0; i < n; i++)
        scanf("%d", &date[i]);

    return 0;
}

double max_average(int left, int right)
{
    double ave = 0, l = 0, r = 0;
    for (int i = left; i <= right; i++)
        ave += date[i];
    ave /= (right - left + 1);
    int middle = (left + right) / 2;
    for (int i = left; i <= middle; i++)
        l += date[i];
    for (int i = middle; i <= right; i++)
        r += date[i];
    l /= (middle - left + 1);
    r /= (right - middle + 1);
    if (ave >= l && ave >= r)
    {
        return ave;
    }
}