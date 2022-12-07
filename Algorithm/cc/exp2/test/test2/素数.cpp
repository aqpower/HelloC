#include "stdio.h"
#include "stdlib.h"
int main()
{
    int a,i;
    scanf("%d",&a);
    for(i=2;i<a;i++)
    {
        if(a%i==0)
        {printf("not prime");}
        else
        {printf("prime");}
    }
    system("pause");
    return 0;
}