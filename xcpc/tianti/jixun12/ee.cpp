#include <bits/stdc++.h>
using namespace std;
const int maxn = 2005;
int a[2005][2005];
int q[2005][2005];
int main(){
    memset(a, 0, sizeof(a));
    memset(q, 0, sizeof(q));
    int n, x, y, w;
    cin >> n;
    while(n--){
        cin >> x >> y >> w;
        a[x][y] = w;
    }
    q[0][0] = a[0][0];
    for (int i = 1; i < maxn;i++){
        q[0][i] = q[0][i - 1] + a[0][i];
        q[i][0] = q[i - 1][0] + a[i][0];
    }
    for (int i = 1; i < maxn;i++){
        for (int j = 1; j < maxn;j++){
            q[i][j] = q[i - 1][j] + q[j - 1][i] - q[j - 1][i - 1] + a[i][j];
        }
    }
    cout << q[1][1];
    int q, x1, x2, y1, y2;
    cin >> q;
    while (q--)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        int a = a[x1][y1];
        // int ans = q[xx2][y2] - q[xx1][y2] - q[xx2][y1] + q[xx1][y1];
        // cout << ans << '\n';
    }
    return 0;
}