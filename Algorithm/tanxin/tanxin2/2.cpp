#include <iostream>
using namespace std;
struct SHUI
{
    int n;
    int g;
    int w;
};
int main()
{
    int v, t;
    cin >> t;
    SHUI s[105];
    while (t--)
    {
        cin >> v;
        for (int i = 0; i < 5; i++)
        {
            cin >> s[i].n >> s[i].g >> s[i].w;
        }
    }
    return 0;
}