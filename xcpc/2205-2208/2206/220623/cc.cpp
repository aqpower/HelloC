#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e5 + 5;
int dat[maxn];
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, k, t, ans = 0;
        scanf("%d%d", &n, &k);
        for (int i = 0; i < k;i++){
            scanf("%d", &dat[i]);
        }
        sort(dat, dat + k);
        int mao = 0;
        for (int i = k - 1; i >= 0;i--){
            if(mao >= dat[i]){
                break;
            }
            mao += n - dat[i];
            ans++;
        }
            cout << ans << '\n';
    }
    return 0;
}