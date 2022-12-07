#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int dat[maxn], sm[maxn], bi[maxn];
int main(){
    memset(bi, 0,sizeof(bi));
    fill(sm, sm + maxn, 1e9);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n;i++){
        cin >> dat[i];
        if(i > 1){
            sm[i] = min(sm[i - 1], dat[i]);
            bi[i] = max(bi[i - 1], dat[i]);
        } else {
            sm[i] = dat[i];
            bi[i] = dat[i];
        }
    }
    while(q--){
        int x;
        cin >> x;
        cout << bi[x] - sm[x] << ' ';
    }
    return 0;
}