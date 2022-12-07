#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int,int> P;
const int maxn = 1e5 + 5;

int main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        string a, s;
        string b;
        cin >> a >> s;
        int is = 0, ia = 0;
        reverse(a.begin(), a.end());
        reverse(s.begin(), s.end());
        bool fg = true;
        for (; is < s.size() && ia < a.size();is++,ia++){
            int na = a[ia] - '0';
            int ns = s[is] - '0';
            if(na > ns){
                if(is < s.size() - 1){
                    ns += (s[++is] - '0') * 10;
                } else {
                    fg = false;
                    break;
                }
                if(ns - na  <= 9){
                    b += char('0' + ns - na);
                } else {
                    fg = false;
                    break;
                }
            } else if(na == ns){
                b += '0';
            } else {
                b += char('0' + ns - na);
            }
        }
        if(fg == false){
            cout << -1 << '\n';
            continue;
        }
        while(is < s.size()){
            b += s[is++];
        }
        // cout << a.size() << ' ' << s.size() << '\n';
        // cout << "ia: "<< ia << " is: " << is << '\n';
        reverse(b.begin(), b.end());
        while(b[0] == '0' && b.size() > 1){
            b.erase(b.begin());
        }
        // cout << b << '\n';
        if(ia >= a.size() && is >= s.size()){
            cout << b << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
    return 0;
}
