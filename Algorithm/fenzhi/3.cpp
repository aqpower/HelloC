#include "stdio.h"
#include "algorithm"

using namespace std;

int adjustment(int *a, int l, int r);
void quicksort(int *a, int l, int r);

int main()
{
    int i, n, k, date[10000];
    scanf("%d%d", &n, &k);
    for (i = 0; i < n; i++)
        scanf("%d", &date[i]);

    // quicksort(date, 0, n - 1);
    sort(date, date + n);

    printf("%d\n", date[k - 1]);

    return 0;
}

int adjustment(int *a, int l, int r)
{
    int i = l, j = r;
    int key = a[i];
    while (i < j)
    {

        while (i < j && a[j] >= key)
            j--;
        if (i < j)
        {
            a[i] = a[j];
            i++;
        }
        while (i < j && a[i] < key)
            i++;
        if (i < j)
        {
            a[j] = a[i];
            j--;
        }
    }
    a[i] = key;
    return i;
}

void quicksort(int *a, int l, int r)
{
    if (l < r)
    {
        int i = adjustment(a, l, r);
        quicksort(a, l, i - 1);
        quicksort(a, i + 1, r);
    }
}
