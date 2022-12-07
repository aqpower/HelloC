#include <bits/stdc++.h>
using namespace std;

int main(){
    int t = 5;
    while(t--){
        int n;
        cin >> n;
        int dn = n;
        string ans;
        bool f = false;
        if(n < 0){
            f = true;
            n = -n;
        }
        do{
            ans += ('0' + n % 2);
            n /= 2;
        } while (n);
        reverse(ans.begin(), ans.end());
        if(f){
            ans.insert(ans.begin(), '-');
        }
        cout << dn << "-->" << ans << '\n';
    }
    return 0;
}