#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int adj[maxn][6];
int n, x, y;
int sum;
int main(){
    cin >> n;
    for (int i = 0; i < n;i++){
        cin >> x >> y;
        adj[x][y] = 1;
    }
    adj[0][0] = 1;
    for (int i = 0; i < maxn;i++){
        for (int j = 0; j < maxn;j++){
            if(adj[i][j]){
                sum += (i-x)*(i-x) + (j-y)*(j-y);
                x = i, y = j;
            }
        }
    }
    cout << sum;
    return 0;
}