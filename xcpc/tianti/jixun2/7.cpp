#include "stdio.h"
#include "string.h"

int main()
{
    char code[40];
    while (1)
    {
        gets(code);
        if (strlen(code) == 1 && code[0] == ' ')
            break;
        
    }

    return 0;
}