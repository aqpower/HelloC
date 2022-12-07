#include <bits/stdc++.h>
using namespace std;
int dat[(int)1e8];
int main(){
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n;i++){
        cin >> dat[i];
    }
    int l = 0, r = n - 1;
    int i, j;
    bool flag = true;
    while(l <= r){
        int mid = (l + r) / 2;
        if(dat[mid] == x){
            flag = false;
            i = j = mid;
            break;
        } else if(dat[mid] > x){
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    if(flag){
        j = l;
        i = r;
    }
    cout << i << ' ' << j << '\n';
    return 0;
}