#include <algorithm>
#include <iostream>

using namespace std;

int Partition(int a[], int left, int right)
{
    int temp = a[left];
    while (left < right)
    {
        while (left < right && a[right] > temp)
            right--;
        a[left] = a[right]; // a[left]主元已被记录下来，挖了个坑，放吧
        while (left < right && a[left] <= temp)
            left++;
        a[right] = a[left];
    }
    a[left] = temp;
    return left;
}
void quicksort(int a[], int left, int right)
{
    if (left < right)
    {
        int pos = Partition(a, left, right);
        quicksort(a, left, pos - 1);
        quicksort(a, pos + 1, right);
    }
}

int main()
{
    int a[12] = {40, 41, 17, 52, 98, 66, 24, 91, 69, 93, 52, 45};
    quicksort(a, 0, 11);
    for (int i = 0; i < 12; i++)
        cout << a[i] << ' ';
    return 0;
}