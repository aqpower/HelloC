#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'L') {
            continue;
        }
        if (!i) {
            if (s.size() == 1) {
                s[i] = 'C';
            }
            if (i + 1 < s.size() && s[i + 1] != 'L') {
                s[i] = 'C';
            }
            continue;
        }
        if (i == s.size() - 1) {
            if (i - 1 >= 0 && s[i - 1] != 'L') {
                s[i] = 'C';
            }
            continue;
        }
        if (s[i - 1] != 'L' && s[i + 1] != 'L') {
            s[i] = 'C';
        }
    }
    cout << s << endl;
    return 0;
}