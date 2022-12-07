#include "stdio.h"
#include "string.h"

int main()
{
    char num[55];
    scanf("%s", num);
    double flag_fu = 1, flag_even = 1;
    int sum = 0, num_2 = 0;
    if (num[0] == '-')
        flag_fu = 1.5;
    else
        sum++;
    for (int i = 0; num[i] != '\0'; i++)
    {
        if (num[i + 1] == '\0')
        {
            int t = num[i] - '0';
            if (t & 2)
                flag_even = 2;
        }
        if (num[i] == '2')
        {
            num_2++;
        }
        if (i != 0)
            sum++;
    }
    printf("%.2f%%\n", 100.0 * num_2 / sum * flag_fu * flag_even);

    return 0;
}