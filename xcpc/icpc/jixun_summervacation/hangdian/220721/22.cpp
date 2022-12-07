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
    for (int i = 0; 7 * i <= 996;i++){
        for (int j = 0; 7 * i + 31 * j <= 996;j++){
            for (int k = 0; 7 * i + 31 * j + 365 * k <= 996;k++){
                if(7 * i + 31 * j + 365 * k == 996){
                    cout << i << ' ' << j << ' ' << k << '\n';
                }
            }
        }
    }
        return 0;
}
