#include <bits/stdc++.h>
using namespace std;
bool isleap(int y){
    return ((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0);
}
int main(){
    int y, m, d;
    int a[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    cin >> y >> m >> d;
    if(isleap(y)){
        a[2]++;
    }
    if(d - 1 == 0){
        if(m - 1 == 0){
            y--;
            m = 12;
            d = 31;
        } else {
            m -= 1;
            d = a[m];
        }
    } else {
        d -= 1;
    }
    cout << y << ' ' <<  m  << ' ' << d;

    return 0;
}