#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, now, pre, maxv = -1;
    cin >> n;
    for (int i = 1; i <= n;i++){
        if(i != 1){
            pre = now;
        }
        cin >> now;
        if(i != 1){
            int d = abs(now - pre);
            if(d > maxv) {
                maxv = d;
            }
        }
    }
    cout << maxv;

    return 0;
}