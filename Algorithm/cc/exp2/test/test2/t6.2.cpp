#include "stdio.h"
#include "stdlib.h"
int main()
{
    int a,b,yve,bei,t;
    scanf("%d%d",&a,&b);
    while(a%b!=0)
    {
        t=a%b;
        a=b;
        b=t;
    }
    if (a%b==0)
    {
        yve = b;
        printf("%d\n",yve);
        bei = a*b / yve;
        printf("%d\n",bei);
    }
    system("pause");

    return 0;
}