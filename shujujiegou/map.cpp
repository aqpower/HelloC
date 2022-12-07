#include <iostream>
#include <map>
#include <string>
using namespace std;
int main()
{
    map<char, int> m;
    for (int i = 0; i < 26; i++)
    {
        char t = 97 + i;
        // m[t] = 97 + i;
        // m.insert(pair<char, int>(t, 97 + i));
        m.insert(make_pair(t, 97 + i));
    }
    for (map<char, int>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << it->first << ' ' << it->second << '\n';
    }

    return 0;
}