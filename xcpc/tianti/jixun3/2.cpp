#include <iostream>
using namespace std;
int main()
{
    int hour[24];
    for (int i = 0; i < 24; i++)
        cin >> hour[i];
    int h;
    while (cin >> h, h <= 23 && h >= 0)
    {
        cout << hour[h] << ' ' << (hour[h] > 50 ? "Yes" : "No") << endl;
    }
    return 0;
}