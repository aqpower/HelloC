#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    if (n / 100000)
    {
        printf("%02d-%02d\n", n / 100, n % 100);
    }
    else
    {
        if (n / 100 < 22)
        {
            printf("20%02d-%02d\n", n / 100, n % 100);
        }
        else
        {
            printf("19%02d-%02d\n", n / 100, n % 100);
        }
    }
    return 0;
}