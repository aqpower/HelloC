#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e7;
int d, i;
int tree[maxn];
int go(int p, int nl){
    if(nl == d){
        return p;
    }
    if(tree[p] == 1){
        tree[p] = -tree[p];
        go(p * 2, nl + 1);
    } else {
        tree[p] = -tree[p];
        go(p * 2 + 1, nl + 1);
    }
}
int main(){
    while(cin >> d >> i, d != 0 && i != 0){
        fill(tree, tree + maxn, 1);
        int ans = 0;
        while(i--){
            int nl = 1, p = 1;
            while(nl != d){
                if(tree[p] == 1){
                    tree[p] = -tree[p];
                    p = p << 1;
                } else {
                    tree[p] = -tree[p];
                    p = p << 1 | 1;
                }
                nl++;
            }
            ans = p;
        }
        cout << ans << '\n';
    }
    return 0;
}