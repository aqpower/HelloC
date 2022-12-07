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
char a[55][55];

int main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n, m, r, c;
        cin >> n >> m >> r >> c;
        bool fg = false;
        for (int i = 0; i < n;i++){
            for (int j = 0; j < m;j++){
                cin >> a[i][j];
                if(a[i][j] == 'B'){
                    fg = true;
                }
            }
        }
        if(!fg){
            cout << -1 << '\n';
            continue;
        }
        r--, c--;
        if(a[r][c] == 'B'){
            cout << 0 << '\n';
            continue;
        }
        bool ffg = false;
        for (int i = 0; i < n;i++){
            if(a[i][c] == 'B'){
                ffg = true;
            }
        }
        for (int i = 0; i < m;i++){
            if(a[r][i] == 'B'){
                ffg = true;
            }
        }
        if(ffg){
            cout << 1 << '\n';
        } else {
            cout << 2 << '\n';
        }
    }
    return 0;
}
