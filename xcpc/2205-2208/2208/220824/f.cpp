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

int main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    int n;
    cin >> n;
    if(n <= 2){
        cout << 0 << '\n';
    } else {
        cout << n / 2 - (1 - n % 2) << '\n';
    }

    return 0;
}
