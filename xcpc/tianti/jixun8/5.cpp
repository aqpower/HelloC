#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, u, d;
    cin >> n >> u >> d;
    int min = 0;
    while(n > 0){
        n -= u;
        min ++;
        if(n > 0){
            n += d;
            min++;
        }
    }
    cout << min;

    return 0;
}