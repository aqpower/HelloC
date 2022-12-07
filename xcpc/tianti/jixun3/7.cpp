#include <iostream>
using namespace std;
int main()
{
    int n, a[1000], max1 = 0, cnt2 = 0, cnt3 = 0;
    double sam3 = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] % 3 == 0 && a[i] > max1)
            max1 = a[i];
        else if (a[i] % 3 == 1)
            cnt2++;
        else if (a[i] % 3 == 2)
            sam3 += a[i], cnt3++;
    }
    if (max1 == 0)
        cout << "NONE" << ' ';
    else
        cout << max1 << ' ';
    if (cnt2 == 0)
        cout << "NONE" << ' ';
    else
        cout << cnt2 << ' ';
    if (sam3)
        printf("%.1f", sam3 / cnt3);
    else
        printf("NONE");

    return 0;
}