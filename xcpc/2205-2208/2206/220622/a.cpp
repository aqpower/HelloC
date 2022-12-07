#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int a[10];
        int b[5];
        for (int i = 0; i < 7;i++){
            cin >> a[i];
        }
        b[0] = a[0];
        b[1] = a[4] - a[0];
        b[2] = a[6] - b[0] - b[1];
        for (int i = 0; i < 3;i++){
            cout << b[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}