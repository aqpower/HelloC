#include "stdio.h"
#include "stdlib.h"

void mySort(char str[], int n);

int main()
{
    char str[15];
    gets(str);
    mySort(str,10);
    puts(str);
    system("pause");
    return 0;
}

void mySort(char str[], int n)
{
    int i, j;
    for (i = 0; i < 9; i++)
    {
        for (j = i + 1; j < 10; j++)
        {
            if (str[i] > str[j])
            {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}
