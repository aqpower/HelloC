#include <bits/stdc++.h>
using namespace std;
const int maxn = 2005;
int a[2005][2005];
int q[2005][2005];
int main(){
    fill(a[0], a[0] + maxn * maxn, 0);
    memset(q, 0, sizeof(q));
    int n, x, y, w;
    cin >> n;
    while(n--){
        cin >> x >> y >> w;
        a[x+1][y+1] += w;
    }
    q[1][1] = a[1][1];
    for (int i = 2; i < maxn;i++){
        q[1][i] = q[1][i - 1] + a[1][i];
        q[i][1] = q[i - 1][1] + a[i][1];
    }
    for (int i = 2; i < maxn;i++){
        for (int j = 2; j < maxn;j++){
            q[i][j] = q[i - 1][j] + q[i][j - 1] - q[i - 1][j - 1] + a[i][j];
        }
    }
    
    int t, x1, x2, y1, y2;
    cin >> t;
    while (t--) {
        int ans;
        cin >> x1 >> y1 >> x2 >> y2;
        x1++, x2++, y1++, y2++;
        ans = q[x2][y2] - q[x2][y1 - 1] - q[x1 - 1][y2] + q[x1 - 1][y1 - 1];
        cout << ans << '\n';
    }
    return 0;
}