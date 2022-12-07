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
const ll maxn = 1e5 + 5;
struct PER{
    ll a;
    ll b;
    ll cnt;
} p[maxn];

bool cmp(PER a, PER b){
    return a.a < b.a;
}

int main(){
    ll t;
    scanf("%lld", &t);
    while(t--){
        ll a, b, n, num = 0;
        cin >> a >> b >> n;
        for (ll i = 0; i < n;i++){
            scanf("%lld", &p[i].a);
        }
        for (ll i = 0; i < n;i++){
            scanf("%lld", &p[i].b);
            p[i].cnt = p[i].b / a;
            if(p[i].b % a){
                p[i].cnt++;
            }
        }
        sort(p, p + n, cmp);
        for (ll i = 0; i < n;i++){
            b -= p[i].a * p[i].cnt;
            if (b <= 0)
            {
                b += p[i].a * p[i].cnt;
                if (b - p[i].a * (p[i].cnt - 1) > 0)
                {
                    num++;
                }
                break;
            }
            num++;
        }
        if(num == n){
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
