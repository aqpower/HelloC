#include <iostream>
#include <string>
using namespace std;
struct ti
{
    string a;
    bool easy;
};
bool ini(string b)
{
    if (b.find("easy") != string::npos || b.find("qiandao") != string::npos)
    {
        return true;
    }
    return false;
}
int main()
{
    int n, m, i, cnt = 0;
    cin >> n >> m;
    getchar();
    ti t[35];
    for (i = 0; i < n; i++)
    {
        getline(cin, t[i].a);
        t[i].easy = ini(t[i].a);
    }
    for (i = 0; i < n; i++)
    {
        if (!t[i].easy)
            cnt++;
        if (cnt == m + 1)
        {
            cout << t[i].a << endl;
            return 0;
        }
    }
    puts("Wo AK le");
    return 0;
}