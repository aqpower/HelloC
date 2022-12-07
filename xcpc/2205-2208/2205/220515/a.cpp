#include <bits/stdc++.h>
using namespace std;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int n, m;
inline bool judge(int a, int b){
    if(a > 0 && a <= n && b > 0 && b <= m){
        return true;
    }
    return false;
} 
int main(){
    cin >> n >> m;
    int a,b;
    cin >> a >> b;
    int ans = 0;
    for (int i = 0; i < 4;i++){
        if(judge(a + dx[i], b + dy[i])){
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}