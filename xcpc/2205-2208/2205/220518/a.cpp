#include <bits/stdc++.h>
using namespace std;
int dat[105][105];
int ans = 1;
int n;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
bool judge(int i, int j){
    if(i >=1 && i <= n && j >= 1 && j <= n){
        if(!dat[i][j]){
            return true;
        }
    }
    return false;
}
void solu(int i, int j, int dic){
    if(ans == n*n+1){
        return;
    }
    // cout << i << ' ' << j << ' ' << dic << '\n';
    dat[i][j] = ans++;
    if (!judge(i + dx[dic], j + dy[dic]))
    {
        dic = (dic + 1) % 4;
        solu(i + dx[dic], j + dy[dic], dic);
        } else {
            solu(i + dx[dic], j + dy[dic], dic);
        }
}


int main(){
    cin >> n;
    solu(1, n, 0);
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= n;j++){
            cout << dat[i][j] << ' ';
        }
        cout << '\n';
    }

        return 0;
}