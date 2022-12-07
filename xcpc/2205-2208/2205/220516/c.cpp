#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
int w[maxn], father[maxn];
int n, m;
int find_father(int a){
    if(a == father[a]){
        return a;
    }
    return father[a] = find_father(father[a]);
}
void union_father(int a, int b){
    int fa = find_father(a);
    int fb = find_father(b);
    if(a !=  b){
        father[fa] = fb;
    }
}
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n;i++){
        father[i] = i;
        scanf("%d", &w[i]);
    }
    int c;
    while(m--){
        scanf("%d", &c);
        if(c == 1){
            int a, b;
            scanf("%d%d", &a, &b);
            union_father(a, b);
        } else {
            int a;
            scanf("%d", &a);
            int ans = 0;
            int fa = find_father(a);
            for (int i = 1; i <= n;i++){
                if(find_father(i) == fa){
                    ans += w[i];
                }
            }
            printf("%d\n",ans);
        }
    }
    
    return 0;
}