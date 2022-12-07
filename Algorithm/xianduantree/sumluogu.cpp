#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e5 + 5;
typedef long long ll;
ll n;
ll a[maxn], mark[maxn], tree[maxn];
void build_tree(ll l, ll r, ll p){
    if(l == r){
        return void(tree[p] = a[l]);
    }
    ll mid = (l + r) / 2;
    build_tree(l, mid, 2 * p);
    build_tree(mid + 1, r, 2 * p + 1);
    tree[p] = tree[p * 2] + tree[p * 2 + 1];
}
void push_down(ll p, ll len){
    mark[p * 2] += mark[p];
    mark[p * 2 + 1] += mark[p];
    tree[p * 2] += mark[p] * (len - len / 2);
    tree[p * 2 + 1] += mark[p] * (len / 2);
    mark[p] = 0;
}
void update(ll l, ll r, ll d, ll p = 1, ll cl = 1, ll cr = n){
    if(cl > r || cr < l){
        return;
    } else if(cl >= l && cr <= r){
        tree[p] += d * (cr - cl + 1);
        if(cr > cl){
            mark[p] += d;
        }
    } else {
        ll mid = (cl + cr) / 2;
        push_down(p, cr - cl + 1);
        update(l, r, d, 2 * p, cl, mid);
        update(l, r, d, 2 * p + 1, mid + 1, cr);
        tree[p] = tree[p * 2] + tree[p * 2 + 1];
    }
}

ll query(ll l, ll r, ll p = 1, ll cl = 1, ll cr = n){
    if(cl > r || cr < l){
        return 0;
    } else if(cl >= l && cr <= r){
        return tree[p];
    } else {
        ll mid = (cl + cr) / 2;
        push_down(p, cr - cl + 1);
        return query(l, r, 2 * p, cl, mid) + query(l, r, 2 * p + 1, mid + 1, cr);
    }
}
int main(){
    int m;
    scanf("%lld%d", &n, &m);
    for (int i = 1; i <= n;i++){
        scanf("%lld", &a[i]);
    }
    build_tree(1, n, 1);
    while(m--){
        ll swi, x, y, k;
        scanf("%lld", &swi);
        if(swi == 1){
            scanf("%lld%lld%lld", &x, &y, &k);
            update(x, y, k);
        } else {
            scanf("%lld%lld", &x, &y);
            printf("%lld\n", query(x, y));
        }
    }
    return 0;
}