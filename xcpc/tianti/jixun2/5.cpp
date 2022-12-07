#include "stdio.h"

int myfind(int n, int x);
int addfind(int n, int x);

struct NUM
{
    int base;
    int index;
} num1[20], num2[20], multip[40], add[40];

int main()
{
    int n, m, di = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &num1[i].base, &num1[i].index);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &num2[i].base, &num2[i].index);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int t = di;
            multip[t].index = num1[i].index + num2[j].index;
            int ins = myfind(di, multip[t].index);
            if (ins == -1)
            {
                multip[t].base += num1[i].base * num2[j].base;
                di++;
            }
            else
            {
                multip[ins].base += num1[i].base * num2[j].base;
            }
        }
    }
    for (int i = 0; i < di - 1; i++)
    {
        for (int j = i + 1; j < di; j++)
        {
            if (multip[i].index < multip[j].index)
            {
                NUM t = multip[i];
                multip[i] = multip[j];
                multip[j] = t;
            }
        }
    }
    for (int i = 0; i < di; i++)
    {
        if (multip[i].base == 0)
            multip[i].index = 0;
        if (i == di - 1)
        {

            printf("%d %d", multip[i].base, multip[i].index);
        }
        else
            printf("%d %d ", multip[i].base, multip[i].index);
    }

    di = n;
    for (int i = 0; i < n; i++)
    {
        add[i] = num1[i];
    }
    for (int i = 0; i < m; i++)
    {
        int t = di;
        int ins = addfind(di, num2[i].index);
        if (ins == -1)
        {
            add[t].index = num2[i].index;
            add[t].base = num2[i].base;
            di++;
        }
        else
        {
            add[ins].base += num2[i].base;
        }
    }
    for (int i = 0; i < di - 1; i++)
    {
        for (int j = i + 1; j < di; j++)
        {
            if (add[i].index < add[j].index)
            {
                NUM t = add[i];
                add[i] = add[j];
                add[j] = t;
            }
        }
    }
    printf("\n");
    for (int i = 0; i < di; i++)
    {
        if (add[i].base == 0)
            add[i].index = 0;
        if (i == di - 1)
            printf("%d %d", add[i].base, add[i].index);
        else
            printf("%d %d ", add[i].base, add[i].index);
    }

    return 0;
}

int myfind(int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (multip[i].index == x)
            return i;
    }
    return -1;
}

int addfind(int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (add[i].index == x)
            return i;
    }
    return -1;
}