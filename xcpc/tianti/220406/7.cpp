#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, t;
    double ave = 0;
    map<string, int> a;
    string nam;
    cin >> n;
    getchar();
    for (int i = 0; i < n;i++){
        cin >> nam >> t;
        ave += t;
        a[nam] = t;
    }
    int iave = (int)(ave / n) / 2;
    string ans;
    int min = 200;
    for (auto i = a.begin(); i != a.end();i++){
        if(abs((*i).second - iave) < min){
            ans = (*i).first;
            min = abs((*i).second - iave);
        }
    }
    cout << iave << ' ' << ans;
    return 0;
}