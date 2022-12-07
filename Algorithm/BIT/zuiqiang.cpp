#include <bits/stdc++.h>
using namespace std;
#define lowbit(x) (x)&(-x)
const int maxn = 1e5 + 5;
int n, m, a[maxn], c[maxn];
void update(int x, int v){
    for (int i = x; i <= n;i+=lowbit(i)){
        if(v > c[i]){
            c[i] = v;
        }
    }
}
void getmax(int l, int r){
    int max = 0;
    
}
int main(){
    cin >> n >> m;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
        update(i, a[i]);
    }
    int x, l, r;
    while(m--){
        cin >> x >> l >> r;
        if(x){
            cout << 1;
        }
    }
    
    return 0;
}