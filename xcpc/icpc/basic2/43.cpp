#include "stdio.h"

char Jiujiu[10][9] = {
    {' ', '0'},
    {'!', '1', ',', '.', '?'},
    {'C', '2', 'A', 'B'},
    {'F', '3', 'D', 'E'},
    {'I', '4', 'G', 'H'},
    {'L', '5', 'J', 'K'},
    {'O', '6', 'M', 'N'},
    {'S', '7', 'P', 'Q', 'R'},
    {'V', '8', 'T', 'U'},
    {'Z', '9', 'W', 'X', 'Y'}};
int numjiu[10] = {2, 5, 4, 4, 4, 4, 4, 5, 4, 5};

int main()
{
    char input[999], temp;
    gets(input);
    int n, t = 0;
    for (int i = 0; input[i] != '\0'; i++)
    {

        if (input[i] != ' ')
        {
            n = input[i] - '0';
            temp = input[i];
        }
        if (input[i + 1] == '\0')
            printf("%c", Jiujiu[n][(t + 1) % numjiu[n]]);
        if (input[i] == temp)
        {
            t++;
        }
        else
        {
            printf("%c", Jiujiu[n][t % numjiu[n]]);
            t = 0;
        }
    }
    return 0;
}
