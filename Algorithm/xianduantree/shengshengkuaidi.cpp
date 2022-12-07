#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int c[maxn], tree[maxn];
int n, q;
bool isselct[maxn];
inline int getMid(int l, int r) { return ((r - l) >> 1) + l; }
inline int ls(int p) { return p << 1; }
inline int rs(int p) { return p << 1 | 1; }
inline void push_up(int p){
    tree[p] = min(tree[ls(p)], tree[rs(p)]);
}
struct NOD{
    int from;
    int to;
    int cost;
}nod[maxn];
void build_tree(int l = 1, int r = n - 1, int p = 1){
    if(l == r) {
        return void(tree[p] = c[l]);
    }
    int mid = getMid(l, r);
    build_tree(l, mid, ls(p));
    build_tree(mid + 1, r, rs(p));
    push_up(p);
}
int query(int l, int r, int p = 1, int nl = 1, int nr = n - 1){
    if(nl >= l && nr <= r ){
        return tree[p];
    }
    int ans = 1e9;
    int mid = getMid(nl, nr);
    if(mid >= l){
        ans = min(ans, query(l, r, ls(p), nl, mid));
    }
    if(mid < r){
        ans = min(ans, query(l, r, rs(p), mid + 1, nr));
    }
    return ans;
}
bool cmp(NOD a, NOD b){
    return a.cost > b.cost;
}
int main(){
    cin >> n >> q;
    for (int i = 1; i < n;i++){
        cin >> c[i];
    }
    build_tree(1, n - 1, 1);
    for (int i = 0; i < q;i++){
        cin >> nod[i].from >> nod[i].to;
        if(nod[i].from > nod[i].to){
            swap(nod[i].from, nod[i].to);
        }
        nod[i].cost = query(nod[i].from + 1, nod[i].to);
    }
    sort(nod, nod + q, cmp);
    int ans = 0;
    for (int i = 0; i < q;i++){
        bool fg = true;
        for (int j = nod[i].from + 1; j <= nod[i].to;j++){
            if(isselct[j]){
                fg = false;
                break;
            }
        }
        if(!fg){
            continue;
        } else {
            fill(isselct + nod[i].from + 1, isselct + nod[i].to + 1, true);
            ans += nod[i].cost;
        }
    }
    printf("%d", ans);
    return 0;
}