#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        int dat[50];
        set<int> se;
        cin >> n;
        int mi = 1e9;
        for (int i = 0; i < n;i++){
            cin >> dat[i];
            mi = min(mi, dat[i]);
        }
        for (int i = 0; i < n;i++){
                se.insert(dat[i] - mi);
        }
        if(se.size() == 1){
            cout << -1 << '\n';
            continue;
        }
        int a = *(se.begin());
        for (auto i = se.begin();i!=se.end();i++){
            a = __gcd(a, (*i));
        }
        cout << a << '\n';
    }
    return 0;
}