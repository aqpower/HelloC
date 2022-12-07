#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string s;
    cin >> n;
    getchar();
    getline(cin, s);
    cout << *(s.end() - 1);
    return 0;
}