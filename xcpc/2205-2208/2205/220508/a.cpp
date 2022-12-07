#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c, d, e, f, x;
    cin >> a >> b >> c >> d >> e >> f >> x;
    int al = 0,sa = 0,ab = 0,sb=0;
    bool con = true,cb = true;
    for (int i = 1; i <= x;i++){
        if(con){
            sa+=b;
            al++;
            if(al == a){
                al = 0;
                con = false;
            }
        } else {
            al++;
            if(al == c){
                al = 0;
                con = true;
            }
        }
    }
    for (int i = 1; i <= x;i++){
        if(cb){
            sb+=e;
            ab++;
            if(ab == d){
                ab = 0;
                cb = false;
            }
        } else {
            ab++;
            if(ab == f){
                ab = 0;
                cb = true;
            }
        }
    }
    if(sa == sb){
        cout << "Draw" << '\n';
    } else if(sa > sb){
        cout << "Takahashi" << '\n';
    } else {
        cout << "Aoki" << '\n';
    }

    return 0;
}