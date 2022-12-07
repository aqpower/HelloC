#include "stdio.h"

int main()
{
    char a = 'z', b = 'z', c = 'z';
    int l, n, fa = 0, fb = 0, fc = 0;
    scanf("%d%d", &l, &n);
    n--;
    while (n--)
    {
        if (fc < 25)
        {
            c -= 1;
            fc++;
        }
        else
        {
            if (fb == 25)
            {
                b = 'z';
                fb = 0;
                fa++;
                a -= 1;
            }
            else
            {

                b -= 1;
                fb++;
            }
            fc = 0;
            c = 'z';
        }
    }
    printf("%c%c%c\n", a, b, c);

    return 0;
}