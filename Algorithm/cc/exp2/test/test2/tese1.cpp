#include "stdio.h"
#include "string.h"
#include "stdlib.h"
int main()
{
    char a[]="abc";
    char b[]={'a','b','c'};
    printf("%d\n",strlen(a));
    printf("%d\n",strlen(b));
    printf("%s\n",b);
    system("pause");
    return 0;
}