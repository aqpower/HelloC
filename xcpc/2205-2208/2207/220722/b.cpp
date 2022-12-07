#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int,int> P;
const int maxn = 1e5 + 5;

int a[10000001],c[10000002][2], n, m;
unsigned int rd;
inline int rnd(int mod,int seed)
{
    rd^=(1<<13);
    rd^=(rd>>7);
    rd^=(rd<<20);
    rd^=(rd>>3);
    rd^=(rd<<10);
    rd^=(rd<<5);
    rd^=(1<<2);
    return rd%mod+seed;
}
// 生成序列 a
void make_sequence()
{
    for(int i=1;i<=n;i++)
    {
        a[i]=i-1;
    }
    for(int i=1;i<=n;i++)
    {
        swap(a[i],a[rnd(n,1)]);
    }
}
// 生成一个询问，表示查询区间 [l,r] 的 mex 
pair<int,int> make_query()
{
    int l=rnd(n,1);
    int r=rnd(n+1-l,l);
    return make_pair(l,r);
}

int main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    cin >> n >> m;
    make_sequence();
    ll ans = 0;
    while(m--){
        P to = make_query();
    }
    return 0;
}
