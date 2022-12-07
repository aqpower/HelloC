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
int a[100];
int b[100];

int main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        memset(b, 0, sizeof(b));
        int n;
        cin >> n;
        for (int i = 0; i < n;i++){
            cin >> a[i];
            if(a[i] > n){
                while(a[i] > n){
                    a[i] /= 2;
                }
            }
            b[a[i]] += 1;
        }
        for (int i = 0; i < n;i++){
            if(b[a[i]] > 1){
                int re = a[i];
                while(b[a[i]] != 0 && a[i]){
                    a[i] /= 2;
                }
                if(a[i] > 0){
                    b[re]--;
                    b[a[i]]++;
                }
            }
        }
        bool fg = true;
        for (int i = 1; i <= n;i++){
            if(b[i] != 1){
                fg = false;
            }
        }
        if(fg){
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}
