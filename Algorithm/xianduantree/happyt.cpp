#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;

int a[N];
int n;

struct Node
{
	int l, r;
	//区间最大值
	int mx;
	int lazy;
}tr[N * 4];

void pushup(int u)
{
	tr[u].mx = max(tr[u << 1].mx, tr[u << 1 | 1].mx);
}

void pushdown(int u)
{
	if (tr[u].lazy)
	{
		tr[u].lazy = 0;
		tr[u << 1].mx = 0;
		tr[u << 1 | 1].mx = 0;
		tr[u << 1].lazy = tr[u << 1 | 1].lazy = 1;
	}
}

void build(int u, int l, int r)
{
	tr[u] = { l, r, 0, 0 };
	if (l == r)
	{
		tr[u].mx = a[l];
		return;
	}
	int mid = l + r >> 1;
	build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
	pushup(u);
}

int query(int u, int l, int r)
{
	if (l <= tr[u].l && r >= tr[u].r)
		return tr[u].mx;
	pushdown(u);
	int mid = tr[u].l + tr[u].r >> 1;
	int res = 0;
	if (l <= mid) res = max(res, query(u << 1, l, r));
	if (r > mid) res = max(res, query(u << 1 | 1, l, r));
	return res;
}

void modify(int u, int l, int r)
{
	if (l <= tr[u].l && r >= tr[u].r)
	{
		tr[u].lazy = 1;
		tr[u].mx = 0;
		return;
	}
	pushdown(u);
	int mid = tr[u].l + tr[u].r >> 1;
	if (l <= mid) modify(u << 1, l, r);
	if (r > mid) modify(u << 1 | 1, l, r);
	pushup(u);
}

int main() {
	// freopen("in.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		int m;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) scanf("%d", a + i);
		build(1, 1, n);
		while (m--) {
			int l, r;
			scanf("%d%d", &l, &r);
			modify(1, l, r);
			int ans = query(1, 1, n);
			printf("%d\n", ans);
		}
	}
	return 0;
}
