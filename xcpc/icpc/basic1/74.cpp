#include "stdio.h"
#include "stdlib.h"

int main()
{
    int meter;
    scanf("%d", &meter);
    double foot, inch;
    for (foot = 1;; foot += 0.1)
    {
        for (inch = 1; inch <= 11; inch += 0.1)
        {
            if (meter - (foot + inch / 12.0) * 30.48 <= 0.1)
            {
                printf("%.0f %.0f\n", foot, inch);
                system("pause");
                return 0;
            }
        }
    }
}
去·