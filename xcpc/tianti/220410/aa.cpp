#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    getline(cin, s);
    s.erase(s.end() - 1);
    s.insert(0, "0");
    cout << s << '\n';
    return 0;
}