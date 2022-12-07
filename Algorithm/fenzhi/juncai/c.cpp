#include <bits/stdc++.h>
using namespace std;
int dat[(int)1e6 + 5];
int main(){
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n;i++){
        cin >> dat[i];
    }
    sort(dat, dat + n);
    cout << dat[k - 1];
    return 0;
}