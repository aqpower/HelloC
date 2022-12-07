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
        if(s.size() % 2 == 0){
            string b = s.substr(0, s.size() / 2);
            // cout << b << '\n';
            b = b + b;
            if(s == b){
                cout << "YES" << '\n';
            } else {
                cout << "NO" << '\n';
            }
        } else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}
