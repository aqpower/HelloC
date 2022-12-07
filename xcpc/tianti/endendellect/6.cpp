#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string a;
    getline(cin, a);
    cin >> n;
    while(n--){
        a += *a.begin();
        a.erase(a.begin());
    }
    cout << a;

    return 0;
}