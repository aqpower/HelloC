#include <iostream>
using namespace std;
int main()
{
    int n, a[100005], t, max = 0, i = 0, j = 1, maxi, maxj;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    while (i < n && j < n)
    {
        if (a[j] > a[j - 1])
        {
            j++;
        }
        else if (a[j] == a[j - 1])
        {
            i = j;
            j = i + 1;
        }
        else
        {
            t = j - i;
            if (t > max)
            {
                max = t;
                maxi = i;
                maxj = j - 1;
            }
            i = j;
            j = i + 1;
        }
    }
    t = j - i;
    if (t > max)
    {
        max = t;
        maxi = i;
        maxj = j - 1;
    }
    if (max == 0)
    {
        maxi = 0;
        maxj = n - 1;
    }
    for (i = maxi; i <= maxj; i++)
    {
        if (i == maxj)
            printf("%d", a[i]);
        else
            printf("%d ", a[i]);
    }
    return 0;
}