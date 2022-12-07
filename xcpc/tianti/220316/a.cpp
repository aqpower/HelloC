#include <bits/stdc++.h>
using namespace std;

int main(){
    string a, b;
    cin >> a;
    getchar();
    cin >> b;
    int cnt = 0;
    auto it = 0;
    while(a.find(b, it) != string::npos){
        it = a.find(b, it) + 1;
        cnt++;
    }
    cout << cnt;
    return 0;
}