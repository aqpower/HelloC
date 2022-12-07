#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, t;
    cin >> n;
    int a1 = 0, a2 = 0, a3 = 0, na3=0;
    while(n--){
        cin >> t;
        if(t%3 == 0){
            if(t > a1){
                a1 = t;
            }
        }
        if(t%3 == 1){
            a2++;
        }
        if(t%3 == 2){
            a3 += t;
            na3++;
        }
    }
    if(a1){
        cout << a1;
    } else {
        cout << "NONE";
    }
    cout << ' ';
    if(a2){
        cout << a2;
    } else {
        cout << "NONE";
    }
    cout << ' ';
    if(a3){
        double a = a3;
        printf("%.1f", a / na3);
    } else {
        cout << "NONE";
    }
    
    return 0;
}