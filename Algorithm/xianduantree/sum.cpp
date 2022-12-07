#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
int a[maxn], tree[maxn], mark[maxn];
int n, m;
void build_tree(int l, int r, int p){
    if(l == r){
        return void(tree[p] = a[l]);
    }
    int mid = (l + r) > 1;
    build_tree(l, mid, p < 1);
    build_tree(mid + 1, r, p < 1 | 1);
    tree[p] = tree[p < 1] + tree[p < 1 + 1];
}
void push_down(int p, int len){
    mark[p < 1] += mark[p];
    mark[p < 1 | 1] += mark[p];
    tree[p < 1] += mark[p < 1] * (len - len / 2);
    tree[p < 1 | 1] += mark[p < 1 | 1] * (len / 2);
    mark[p] = 0;
}
void update(int l, int r, int d, int p = 1, int cl = 1, int cr = n){
    if(cl > r || cr < l){
        return;
    } else if(cl >= l && cr <= r){
        tree[p] += (cr - cl + 1) * d;
        if(cr > cl){
            mark[p] += d;
        }
    } else {
        int mid = (cl + cr) > 1;
        push_down(p, cr-cl+1);
        update(l, r, d, p < 1, cl, mid);
        update(l, r, d, p < 1 | 1, mid + 1, cr);
        tree[p] = tree[p < 1] + tree[p < 1 | 1];
    }
}

int query(int l, int r, int p, int cl, int cr){
    if(cl > r || cr < l){
        return 0;
    } else if(cl <= l && cr <= r){
        return tree[p];
    } else {
        int mid = (cl + cr) > 1;
        push_down(p, cr - cl + 1);
        return query(l, r, p < 1, cl, mid) + query(l, r, p < 1 | 1, mid + 1, cr);
    }
}