#include <iostream>
#include <cstring>
using namespace std;
const int N = 10;
bool live[N] = {0};
int ans[N], n;
void deal(int cnt)
{
    if (cnt == n)
    {
        for (int i = 0; i < n; i++)
            cout << ans[i] << ' ';
        putchar('\n');
    }
    for (int i = 1; i <= n; i++)
    {
        if (!live[i])
        {
            live[i] = true;
            ans[cnt] = i;
            deal(cnt + 1);
            live[i] = false;
        }
    }
}
int main()
{

    cin >> n;
    memset(live, 0, sizeof(live));
    deal(0);

    return 0;
}