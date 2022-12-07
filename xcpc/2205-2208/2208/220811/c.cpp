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
        string s;
        cin >> s;
        for (int i = 0; i < s.size();i++){
            if(i & 1){
                s[i] = s[i] == 'z' ? 'y' : 'z';
            } else {
                s[i] = s[i] == 'a' ? 'b' : 'a';
            }
        }
        cout << s << '\n';
    }
    
    return 0;
}
