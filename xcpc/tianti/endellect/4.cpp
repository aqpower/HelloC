#include <bits/stdc++.h>
using namespace std;


int main(){
    int a, b,da = 0,db = 0;
    cin >> a >> b;
    int n = 3;
    int t;
    while(n--){
        cin >> t;
        if(t){
            db++;
        } else {
            da++;
        }
    }
    if(a>b){
        if(da){
            cout << "The winner is a: " << a << " + " << da;
            return 0;
        } else {
            cout << "The winner is b: " << b << " + " << db;

        }
    } else {
        if(db == 3){
            cout << "The winner is b: " << b << " + " << db;
        } else {
            cout << "The winner is a: " << a << " + " << da;
        }

    }
    

    return 0;
}