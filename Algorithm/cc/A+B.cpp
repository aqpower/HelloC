#include <cstring>
#include <cstdio>

struct bign
{
    int len;
    int d[1000];
    bign()
    {
        len = 0;
        memset(d, 0, sizeof(d));
    }
};
bign change(char *str)
{
    bign a;
    a.len = strlen(str);
    for (int i = 0; i < a.len; i++)
    {
        a.d[i] = str[a.len - 1 - i] - '0';
    }
    return a;
}
bign add(bign a, bign b)
{
    bign c;
    int carry = 0;
    for (int i = 0; i < a.len || i < b.len; i++)
    {
        int temp = a.d[i] + b.d[i] + carry;
        c.d[c.len++] = temp % 10;
        carry = temp / 10;
    }
    if (carry)
    {
        c.d[c.len++] = carry;
    }
    return c;
}
bign sub(bign a, bign b)
{
    bign c;
    for (int i = 0; i < a.len || i < b.len; i++)
    {
        if (a.d[i] < b.d[i])
        {
            a.d[i + 1]--;
            a.d[i] += 10;
        }
        c.d[c.len++] = a.d[i] - b.d[i];
    }
    while (c.len - 1 >= 1 && c.d[c.len - 1] == 0)
        c.len--;
    return c;
}
bign multi(bign a, int b)
{
    bign c;
    int carry = 0;
    for (int i = 0; i < a.len; i++)
    {
        int temp = a.d[i] * b + carry;
        c.d[c.len++] = temp % 10;
        carry = temp / 10;
    }
    while (carry)
    {
        c.d[c.len++] = carry % 10;
        carry /= 10;
    }
    return c;
}
bign divide(bign a, int b, int &r)
{
    bign c;
    c.len = a.len;
    for (int i = a.len - 1; i >= 0; i--)
    {
        r = r * 10 + a.d[i];
        if (r < b)
        {
            c.d[i] = 0;
        }
        else
        {
            c.d[i] = r / b;
            r = r % b;
        }
    }
    while (c.len - 1 >= 1 && c.d[c.len - 1] == 0)
    {
        c.len--;
    }
    return c;
}
void putbign(bign a)
{
    for (int i = a.len - 1; i >= 0; i--)
        printf("%d", a.d[i]);
    putchar('\n');
}
int main()
{
    char str1[1000], str2[1000];
    scanf("%s%s", str1, str2);
    bign a = change(str1), b = change(str2);
    bign afadd = add(a, b);

    putbign(afadd);

    return 0;
}


