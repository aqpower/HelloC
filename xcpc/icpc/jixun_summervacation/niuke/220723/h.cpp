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
int b[maxn];
int main(){
    b[1] = 1;
    for (int i = 2; i < maxn;i++){
        b[i] = b[i - 1] + i;
    }
    cin.tie(0)->ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int a[maxn];
        for (int i = 0; i < n;i++){
            cin >> a[i];
        }
        sort(a, a + n);
        int ind = lower_bound(b, b + maxn, k) - b;
        cout << a[n - ind - 1] << '\n';
    }
    return 0;
}
