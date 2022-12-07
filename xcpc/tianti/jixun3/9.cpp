#include <iostream>
using namespace std;

int main()
{
    int te, n, a[1005], n1, n2, c;
    char t, s2[1005];
    cin >> n;
    c = n - 2;
    n1 = n - 1;
    n2 = n - 2;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    getchar();
    for (int i = 0; i < n - 1; i++)
    {
        scanf("%c%c", &s2[i], &t);
    }
    while (c >= 0)
    {
        switch (s2[c])
        {
        case '+':
            te = a[n2] + a[n1];
            break;
        case '-':
            te = a[n2] - a[n1];
            break;
        case '*':
            te = a[n2] * a[n1];
            break;
        case '/':
            if (a[n1] == 0)
            {
                printf("ERROR: %d/0", a[n2]);
                cout << a[n2] << endl;
                return 0;
            }
            te = a[n2] / a[n1];
            break;
        }
        a[n2] = te;
        n2--;
        n1--;
        c--;
    }
    cout << a[0] << endl;

    return 0;
}