#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n, m;
int a[maxn], tree[maxn << 2], tag[maxn << 2];
inline int ls(int p) {return p << 1;}
inline int rs(int p) { return p << 1 | 1; }
inline int getMid(int l, int r) { return ((r - l) >> 1) + l; }
inline void push_up(int p){
    tree[p] = max(tree[ls(p)], tree[rs(p)]);
}
inline void f(int p, int l, int r){ 
    tag[p] = 1;
    tree[p] = 0;
}
inline void push_down(int p, int l, int r){
    if(tag[p]){
        tag[p] = 0;
        int mid = getMid(l, r);
        f(ls(p), l, mid);
        f(rs(p), mid + 1, r);
    }
}
void build_tree(int l = 1, int r = n, int p = 1){
    if(l == r) { return void(tree[p] = a[l]);}
    int mid = getMid(l, r);
    build_tree(l, mid, ls(p));
    build_tree(mid + 1, r, rs(p));
    push_up(p);
}

// l and r is the target segment
void update(int l, int r, int d, int p = 1, int nl = 1, int nr = n){ //todo change_value
    if(nl >= l && nr <= r){
        tag[p] = 1;
        tree[p] = d;
        return;
    }
    push_down(p, nl, nr);
    int mid = getMid(nl, nr);
    if(mid >= l){
        update(l, r, d, ls(p), nl, mid);
    }
    if(mid < r){
        update(l, r, d, rs(p), mid + 1, nr);
    }
    push_up(p);
}
int query(int l, int r, int p = 1, int nl = 1, int nr = n){
    if(nl >= l && nr <= r){
        return tree[p];
    }
    push_down(p, nl, nr);
    int ans = -1;
    int mid = getMid(nl, nr);
    if(mid >= l){
        ans = max(ans, query(l, r, ls(p), nl, mid));
    }
    if(mid < r){
        ans = max(ans, query(l, r, rs(p), mid + 1, nr));
    }
    return ans;
};
int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n;i++){
            scanf("%d", &a[i]);
        }
        build_tree();
        while(m--){
            int l, r;
            scanf("%d%d", &l, &r);
            update(l, r, 0);
            printf("%d\n", query(1, n));
        }
    }
    return 0;
}