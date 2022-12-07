#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        char tar,now;
        ll ow = 0;
        cin >> s >> tar;
        now = s.front();
        s.erase(s.begin());
        ll db = 1;
        if(now == '#'){
            db = 7;
        } else if(now == '$'){
            db = 17;
        } else {
            db = 2;
        }
        ll base = 1;
        for (int i = s.size() - 1; i >= 0;i--){
            ow += (s[i] - 'a') * base;
            base *= db;
        }
        string ans;
        if (tar == '#')
        {
            while (ow)
            {
                ll a = ow % 7;
                ans += ('a' + a);
                ow /= 7;
            }
        } else if(tar == '$'){
                while(ow){
                    ll a = ow % 17;
                    ans += ('a'+ a);
                    ow /= 17;
                }
        } else {
                while(ow){
                    ll a = ow % 2;
                    ans += ('a'+ a);
                    ow /= 2;
                }
        }
        reverse(ans.begin(), ans.end());
        cout << tar << ans << '\n';
    }
    return 0;
}