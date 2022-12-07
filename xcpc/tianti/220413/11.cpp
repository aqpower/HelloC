#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
typedef long long ll;
int main(){
    ll n, a[maxn];
    ll  qu[maxn];
    cin >> n;
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 0; i < n;i++){
        if(i){
            qu[i] = qu[i - 1] + a[i];
        } else {
            qu[i] = a[i];
        }
    }
    int mid = n / 2;
    printf("Outgoing #: %d\n\
Introverted #: %d\n\
Diff = %d\n",n - mid,mid,qu[n - 1] - 2*qu[mid - 1]);
    return 0;
}