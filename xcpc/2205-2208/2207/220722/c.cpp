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
int a[maxn], b[maxn], fi[maxn];
int main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    fi[0] = 0;
    fi[1] = 1;
    for (int i = 2; i < maxn;i++){
        fi[i] = fi[i - 1] + fi[i - 2];
    }
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
    }
    for (int i = 1; i <= n;i++){
        cin >> b[i];
    }
    for (int i = 0; i < m;i++){
        int l, r, k;
        cin >> l >> r >> k;
        for (int j = l; j <= r;j++){
            a[j] = (fi[k + 1] * a[j] %1000000007 + fi[k] * b[j]%1000000007) %1000000007;
            b[j] = (fi[k] * a[j] %1000000007+ fi[k-1] * b[j]%1000000007) %1000000007;
        }
    for (int i = 1; i <= n;i++){
        cout << a[i] << ' ';
    }
    cout << '\n';
    for (int i = 1; i <= n;i++){
        cout << b[i] << ' ';
    }
    cout << '\n';
    }
    return 0;
}
