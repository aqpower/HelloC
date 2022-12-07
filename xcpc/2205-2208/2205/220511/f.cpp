#include <iostream>
#include <cstring>
#include <set>
using namespace std;
int a[10][10];
int l[10];
int n, k;
int ans;
void init(){
    memset(l, 0, sizeof(l));
    ans = 0;
}
void dfs(int nl, int np){
    if(np == k){
        ans++;
        return;
    }
    if(nl == n){
        return;
    }
    for (int i = 0; i < n;i++){
        if(a[nl][i] && (!l[i])){
            l[i] = 1;
            a[nl][i] = 0;
            dfs(nl + 1, np + 1);
            l[i] = 0;
            a[nl][i] = 1;
        }
    }
    dfs(nl + 1, np);
}
int main(){
    char c;
    while(cin >> n >> k,n != -1 && k != -1){
        init();
        for (int i = 0; i < n;i++){
            for (int j = 0; j < n;j++){
                cin >> c;
                if(c == '#'){
                    a[i][j] = 1;
                } else {
                    a[i][j] = 0;
                }
            }
        }
        dfs(0, 0);
        cout << ans << '\n';
    }
    return 0;
}