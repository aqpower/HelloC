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
const int maxn = 105;

int n;
int a[maxn], ans[maxn];

void sol(int d, int down, int up, int ind){
    ans[ind] = d;
    int max = -1, ind_max;
    for (int i = down; i < ind;i++){
        if(a[i] > max ){
            max = a[i];
            ind_max = i;
        }
    }
    if(max != -1){
        sol(d + 1, down, ind, ind_max);
    }
    max = -1;
    for (int i = ind + 1; i < up;i++){
        if(a[i] > max ){
            max = a[i];
            ind_max = i;
        }
    }
    if(max != -1){
        sol(d + 1, ind + 1, up, ind_max);
    }
}

int main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        int ma = -1, ind_max;
        for (int i = 0; i < n;i++){
            cin >> a[i];
            if(a[i] == n){
                ind_max = i;
            }
        }
        sol(0, 0, n, ind_max);
        for (int i = 0; i < n;i++){
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
