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
        string s, ts, res;
        cin >> s;
        int a[50];
        memset(a, 0, sizeof(a));
        for (int i = 0; i < s.size();i++){
            a[s[i] - 'a']++;
        }
        for (int i = 0; i < 26;i++){
            if(a[i] == 1){
                ts += char('a' + i);
            } else if(a[i] == 2){
                res += char('a' + i);
            }
        }
        cout << res <<  res << ts << '\n';
    }
    return 0;
}
