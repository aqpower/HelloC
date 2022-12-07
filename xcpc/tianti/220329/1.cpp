#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,t,nz = 0,nc = 0;
    cin >> n >> t;
    nz = n;
    while(t--){
        if(nz){
            nc = nz;
            nz = 0;
        } else {
            nz = nc * 2;
            nc = 0;
        }
    }
    if(nz){
        cout << 0 << ' ' <<  nz << '\n';
    } else {
        cout << 1 << ' ' << nc << '\n';
    }
    return 0;
}