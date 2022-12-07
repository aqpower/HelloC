#include <bits/stdc++.h>
using namespace std;
int dat[135][135];
int n, m;
void solu(int now){
    if(now > n){
        return;
    }
    dat[now][0] = now;
    bool used[135];
    // fill(used, used + 135, 0);
    memset(used, 0,sizeof(used));
    for (int i = 1; i < n;i++){
        if(!dat[now][i]){
            for (int j = 1; j <= n;j++){
                if(j == now){
                    continue;
                }
                if(!dat[j][i] && !used[j]){
                    used[j] = true;
                    dat[j][i] = now;
                    dat[now][i] = j;
                    break;
                }
            }
        }
    }
    solu(now + 1);
}
int main(){
    cin >> m;
    n = pow(2, m);
    solu(1);
    for (int i = 1; i <= n;i++){
        for (int j = 0; j < n;j++){
            cout << dat[i][j] << ' ';
            // if(j != n - 1){
            //     cout << ' ';
            // }
        }
        cout << '\n';
    }
    return 0;
}