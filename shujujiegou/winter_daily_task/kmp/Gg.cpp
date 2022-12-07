#include <cstdio>
#include <cstring>

char nam[65][20];
bool a[65];

int main()
{

    int i, n, w, s;
    scanf("%d", &n);
    getchar();
    for (i = 1; i <= n; i++)
        gets(nam[i]);
    scanf("%d,%d", &w, &s);
    memset(a, 0, sizeof(a));
    int all = n, cnt = 0;
    while (all)
    {
        if (!a[w])
            cnt++;
        if (cnt == s)
        {
            a[w] = true;
            puts(nam[w]);
            cnt = 0;
            all--;
        }
        w++;
        if (w > n)
            w = 1;
    }

    return 0;
}