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
const int maxn = 1e2 + 5;
int a[maxn];

int main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n, n1 = 0, n2 = 0, nsum = 0;
        cin >> n;
        for (int i = 0; i < n;i++){
            cin >> a[i];
            if(a[i] == 1){
                n1++;
            } else {
                n2++;
            }
            nsum += a[i];
        }
        if(nsum % 2){
            cout << "NO" << '\n';
        } else {
            int ta = nsum / 2;
            bool fg = false;
            for (int i = 0; i <= n1;i++){
                for (int j = 0; j <= n2;j++){
                    if(i + j * 2 == (n1 - i + (n2 - j) * 2)){
                        fg = true;
                        break;
                    }
                }
            }
            if(fg){
                cout << "YES" << '\n';
            } else {
                cout << "NO" << '\n';
            }
        }
    }
    return 0;
}
