#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    double h, w;
    while(n--){
        cin >> h >> w;
        double in = (h - 100) * 1.8;
        if(abs(w-in) < in * 0.1){
            cout << "You are wan mei!";
        } else if(w > in){
            cout << "You are tai pang le!";
        } else {
            cout << "You are tai shou le!";
        }
        cout << '\n';
    }

    return 0;
}