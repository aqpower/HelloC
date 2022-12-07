#include <bits/stdc++.h>
using namespace std;
bool a[105];
int main(){
    int n, m;
    cin >> n >> m;
    while(n--){
        int x, y;
        cin >> x >> y;
        for (int i = x; i <= y;i++){
            a[i] = true;
        }
    }
    int ans = 0;
    int p[105];
    for (int i = 1; i <= m;i++){
        if(!a[i]){
            p[ans++] = i;
        }
    }
    cout << ans << '\n';
    for (int i = 0; i < ans;i++){
        cout << p[i] << ' ';
    }
    return 0;
}