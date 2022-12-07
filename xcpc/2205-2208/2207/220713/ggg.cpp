#include <bits/stdc++.h>
using namespace std;

int f(int mid, int x, int y){
    int dx = mid / x;
    int dy = mid / y;
    int dd = mid / x / y;
    return mid - (dx + dy - dd);
}

int main(){
    ios::sync_with_stdio(false);
    int cnt1, cnt2, x, y;
    cin >> cnt1 >> cnt2 >> x >> y;
    int left = 1, right = (int)1e10;
    while(left < right){
        int mid = left + ((right - left) >> 1);
        int va = f(mid, x, y);
        if(va >= cnt1 + cnt2){
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    cout << left << '\n';
    return 0;
}