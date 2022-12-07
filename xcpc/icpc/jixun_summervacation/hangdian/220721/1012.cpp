#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> P;
const int maxn = 1e5 + 5;

int ans;
void sol(int n, int num){
    int m7 = n % 7;
    int m31 = n % 31;
    int m365 = n % 365;
    if(m7 == 0){
        ans = min(ans, num + n / 7);
    } 
    if(m31 == 0){
        ans = min(ans, num + n / 31);
    } else if(m31 >= 7 && n >= 31){
        if(n % 31 % 7 == 0){
            sol(n % 31, num + n / 31);
        } else if((n % 31 + 31) % 7 == 0 && n >= 2 * 31){
            sol(n % 31 + 31, num + n / 31 - 1);
        } else if((n % 31 + 2 * 31) % 7 == 0 && n >= 3 * 31){
            sol(n % 31 + 31, num + n / 31 - 1);
        }else if((n % 31 + 3 * 31) % 7 == 0 && n >= 4 * 31){
            sol(n % 31 + 31, num + n / 31 - 1);
        }else if((n % 31 + 4 * 31) % 7 == 0 && n >= 5 * 31){
            sol(n % 31 + 31, num + n / 31 - 1);
        } else if((n % 31 + 5 * 31) % 7 == 0 && n >= 6 * 31){
            sol(n % 31 + 31, num + n / 31 - 1);
        }
    }
    if(m365 == 0){
        ans = min(ans, num + n / 365);
    } else if(m365 >= 7 && n >= 365){
        sol(n % 365, num + n / 365);
    } 
}

int main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        ans = 1e9;
        ll n;
        cin >> n;
        sol(n, 0);
        if(ans == 1e9){
            ans = -1;
        }
        cout << ans << '\n';
    }
    return 0;
}
