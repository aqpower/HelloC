#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn], b[maxn];
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        bool fg = false;
        for (int i = 1; i <= n;i++){
            scanf("%d", &a[i]);
            if(a[i] == n){
                if(i != 1 && i != n){
                    fg = true;
                }
            }
        }
        if(fg){
            cout << -1 << '\n';
            continue;
        }
        vector<int> c;
        int l = 1, r = n;
        for (;l <= r;){
            if(a[l] > a[r]){
                c.insert(c.begin(), a[l]);
                l++;
            } else {
                c.insert(c.end(), a[r]);
                r--;
            }
        }
        for (int i = 0; i < c.size();i++){
            printf("%d ", c[i]);
        }
        putchar('\n');
    }
    return 0;
}