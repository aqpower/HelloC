#include "stdio.h"
#include "math.h"

int main()
{
    int h, m, a, b, dh;
    scanf("%d%d", &a, &b);
    h = a / 100;
    m = a % 100;
    if (b / 60)
    {
        dh = b / 60;
        b -= dh * 60;
    }
    if (m + b >= 60)
    {
        h += dh + 1;
        m = m - 60 + b;
    }
    else if (m + b >= 0)
    {

        h += dh;
        m += b;
    }
    else
    {
        h = h + dh - 1;
        m = m + 60 + b;
    }
    printf("%d%d", h, m);

    return 0;
}