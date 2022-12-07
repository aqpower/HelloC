#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        map<char, int> mp;
        char ch;
        for (int i = 1; i <= 26;i++){
            cin >> ch;
            mp[ch] = i;
        }
        string s;
        cin >> s;
        int ans = 0;
        for (int i = 1; i < s.size();i++){
            ans += abs(mp[s[i]] - mp[s[i - 1]]);
        }
        cout << ans << '\n';
    }
    return 0;
}

/*#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;
    cin >> t;
    while(t--){
        ll x, n;
        cin >> x >> n;
        if(n & 1){
            if(x & 1){
                x += n;
            } else {
                
            }
        } else {
            if(x & 1){
                x--;
            } else {
                x++;
            }
        }
        cout << x << '\n';
    }
    return 0;
}
*/