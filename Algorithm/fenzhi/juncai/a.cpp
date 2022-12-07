#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, dat[1005];
    cin >> n;
    for (int i = 0; i < n;i++){
        cin >> dat[i];
    }
    int x;
    cin >> x;
    int cnt = 0, l = 0, r = n - 1;
    while(l <= r){
        cnt++;
        int mid = (l + r) / 2;
        if(dat[mid] == x){
            cout << mid << '\n'
                 << cnt << '\n';
            return 0;
        } else if(dat[mid] > x){
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << -1 << '\n'
         << cnt << '\n';
    return 0;
}