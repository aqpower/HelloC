#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
int ans = 0;
void dfs(int n, int a, int b, int now, vector<P> wor){
    if(find(wor.begin(), wor.end(), P(a, b)) != wor.end()){
        return;
    }
    if(now == n){
        ans++;
        return;
    }
    wor.push_back(P(a, b));
    dfs(n, a - 1, b, now + 1, wor);
    dfs(n, a + 1, b, now + 1, wor);
    dfs(n, a, b + 1, now + 1, wor);
}
int main(){
    for (int n = 20; n <= 20;n++){
        vector<P> t;
        dfs(n, 0, 0, 0, t);
        cout << ans << '\n';
        ans = 0;
    }

    return 0;
}