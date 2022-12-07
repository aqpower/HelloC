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
typedef pair<int, int> P;
const int maxn = 1e5 + 5;

bool ispre(ll n)
{
    if(n == 1){
        return false;
    }
    for (ll i = 2;i <= n / i;i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

int main()
{
    cin.tie(0)->ios::sync_with_stdio(false);
    int n;
    cin >> n;
    while (n--)
    {
        ll x;
        cin >> x;
        for (ll i = x;; i++)
        {
            if (ispre(i)){
                cout << i << '\n';
                break;
            }
        }
    }
    return 0;
}
