#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
string a[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for (int i = 0; i < n;i++){
            cin >> a[i];
        }
        string po;
        cin >> po;
        int cnt = 0;
        for (int i = 0; i < n;i++){
            if(po.find(a[i]) != -1){
                cnt++;
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}