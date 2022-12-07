#include <iostream>
using namespace std;
const int MAXN = 10;

int Benarysearch(int a[], int left, int right, int x)
{
    int mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (a[mid] == x)
            return mid;
        else if (a[mid] > x)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}

int main()
{
    int x, n, a[MAXN];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> x;
    int idex = Benarysearch(a, 0, n - 1, x);
    cout << idex;

    return 0;
}
