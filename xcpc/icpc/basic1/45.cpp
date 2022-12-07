#include "stdio.h"
#include "stdlib.h"

int main()
{
    int start, end;
    scanf("%d%d", &start, &end);

    int h1, h2, m1, m2;
    h1 = start / 100;
    h2 = end / 100;
    m1 = start % 100;
    m2 = end % 100;

    if (m2 > m1)

        printf("%02d:%02d\n", h2 - h1, m2 - m1);

    else if (m2 == m1)
        printf("%02d:%02d\n", h2 - h1, 0);
    else
    {
        if (h1 == h2)
            printf("%02d:%02d\n", h2 - h1, m2 - m1);
        else
        {

            printf("%02d:%02d\n", h2 - h1 - 1, m2 + 60 - m1);
        }
    }
    system("pause");
    return 0;
}