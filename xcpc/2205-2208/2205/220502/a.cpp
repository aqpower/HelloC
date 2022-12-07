#include <bits/stdc++.h>
using namespace std;

int main(){
    int m, n;
    cin >> m >> n;
    int ji, tu;
    for (ji = 0; ji <= m;ji++){
        tu = m - ji;
        if (ji * 2 + tu * 4 == n)
        {
            cout << ji << ' ' << tu << '\n';
            return 0;
        }
    }
    return 0;
}