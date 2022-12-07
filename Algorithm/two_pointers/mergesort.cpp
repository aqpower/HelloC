#include <iostream>

using namespace std;

const int MAXN = 100;
void merge(int a[], int L1, int R1, int L2, int R2)
{
    int i = L1, j = L2; // two pointers begins to return and
    int temp[MAXN], index = 0;
    while (i <= R1 && j <= R2)
    {
        if (a[i] < a[j])
        {
            temp[index++] = a[i++];
        }
        else
        {
            temp[index++] = a[j++];
        }
    }
    while (i <= R1)
    {
        temp[index++] = a[i++];
    }
    while (j <= R2)
    {
        temp[index++] = a[j++];
    }
    for (int i = 0; i < index; i++)
    {
        a[L1 + i] = temp[i];
    }
}
void mergesort(int a[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergesort(a, left, mid); //! reduce the size of the problem
        mergesort(a, mid + 1, right);
        merge(a, left, mid, mid + 1, right);
    }
}

int main()
{
    int a[9] = {2, 45, 3, 2, 54, 67, 4, 7, 9};
    mergesort(a, 0, 8);
    for (int i = 0; i < 9; i++)
        cout << a[i] << ' ';

    return 0;
}