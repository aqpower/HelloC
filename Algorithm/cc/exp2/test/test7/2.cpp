#include "stdio.h"
#include "stdlib.h"

int main()
{
    char f1[99], f2[99];
    gets(f1);
    gets(f2);
    FILE *fp1 = NULL;
    FILE *fp2 = NULL;
    fp1 = fopen(f1, "a");
    fp2 = fopen(f2, "r");
    if (fp1 == NULL || fp2 == NULL)
    {
        printf("open error\n");
    }
    fseek(fp1, 0, SEEK_END);
    int ch;
    while ((ch = fgetc(fp2)) != EOF)
    {
        fputc(ch, fp1);
    }
    fclose(fp1);
    fclose(fp2);
    fp1 = NULL;
    fp2 = NULL;
    return 0;
}