#include "stdio.h"
#include "algorithm"

using namespace std;

int date[100000];

int main()
{
    int n, x,tar=-1;
    scanf("%d%d", &n, &x);
    for (int i = 0; i < n;i++)
    {
        scanf("%d", &date[i]);
    }
    sort(date, date + n);
    for (int i = 0; i < n;i++)
    {
        if(date[i]>x)
        {
            tar = i;
            break;
        }
    }
    if(tar==-1)
    {
        printf("%d\n", date[n - 1]);
    }
    else if(!tar) 
    {
        printf("%d\n", date[0]);
    }
    else
    {
        if((date[tar]-x)>(x-date[tar-1]))
        {
            printf("%d\n", date[tar - 1]);
        }
        else
        {
            printf("%d\n", date[tar]);
        }
    }

        return 0;
}