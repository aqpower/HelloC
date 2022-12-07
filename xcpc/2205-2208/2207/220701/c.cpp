#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int k;
        cin >> k;
        int i = 1;
        while(i * i < k){
            i++;
        }
        int de = i * i - k;
        int x, y;
        if(de == 0){
            x = 1, y = i;
        } else {
            x = 1, y = i;
            while(de--){
                if(x < i){
                    x++;
                } else {
                    y--;
                }
            }
        }
        cout << y << ' ' << x << '\n';
    }
    return 0;
}