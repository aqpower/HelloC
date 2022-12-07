#include <bits/stdc++.h>
using namespace std;
int mi(int a, int n){
    int base = a;
    int res = 1;
    while(n){
        if(n & 1){
            res *= base;
            res %= 7;
        }
        base *= base;
        base %= 7;
        n >>= 1;
    }
    return res;
}
int main(){
    int a, b, day = 7;
    cin >> a >> b;
    day = mi(a,b);
    string dic[8] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    cout << dic[day];

    return 0;
}