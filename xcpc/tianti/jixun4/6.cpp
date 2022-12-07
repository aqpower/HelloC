#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string a, b;
    getline(cin, a);
    getline(cin, b);
    for (string::iterator it = a.begin(); it < a.end();)
    {
        if (b.find(*it) != string::npos)
        {
            a.erase(it);
        }
        else
        {
            it++;
        }
    }
    cout << a;
    return 0;
}