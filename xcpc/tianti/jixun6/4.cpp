#include <bits/stdc++.h>
using namespace std;
int pa, pb, pa1 = 0, pb1 = 0;

int main(){
    cin >> pa >> pb;
    int t;
    while(cin >> t){
        if(t){
            pb1++;
        } else {
            pa1++;
        }
    }
    if(pa > pb && pa1){
        cout << "The winner is a: " << pa << " + " << pa1 << "";
    } else if(pa1 == 3) {
        cout << "The winner is a: " << pa << " + " << pa1 << "";
    } else {
        cout << "The winner is b: " << pb << " + " << pb1 << "";
    }



    return 0;
}