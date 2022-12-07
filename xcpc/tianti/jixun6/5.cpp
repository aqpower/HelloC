#include <bits/stdc++.h>
using namespace std;
int w[25][25];
int m, n;
int x[4] = {0, 0, 1, -1};
int y[4] = {1,-1,0,0};

int attack(int a,int b){
    int ans = 0;
    if(w[a][b]){
        w[a][b] = 0;
        ans++;
    }
    int na, nb;
    for (int i = 0; i < 4;i++){
        na = a + x[i];
        nb = b + y[i];
        if(na >= 0 && na < m && nb >= 0 && nb < n){
            if(w[na][nb]){
                w[na][nb]--;
                if(!w[na][nb]){
                    ans++;
                }
            }
        }
    }
    return ans;
}


int main(){
    cin >> m >> n;
    memset(w, 0, sizeof(w));
    getchar();
    char t;
    for (int i = 0; i < m;i++){
        for (int j = 0; j < n;j++){
            cin >> t;
            if(t == '#'){
                w[i][j] = 2;
            }
        }
        getchar();
    }
    int k,a,b;
    cin >> k;
    while(k--){
        cin >> a >> b;
        cout << attack(a, b) << '\n';
    }

    return 0;
}