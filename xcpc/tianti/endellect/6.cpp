#include <bits/stdc++.h>
using namespace std;

int main(){
    int la, lb, na = 0, nb = 0;
    cin >> la >> lb;
    int a, da, b, db;
    int n;
    cin >> n;
    while(n--){
        cin >> a >> da >> b >> db;
        if(da == db){
            continue;
        }
        int t = a + b;
        if(da == t){
            la--;
            na++;
        }
        if(db == t){
            lb--;
            nb++;
        }
        if(la < 0 || lb < 0){
            if(la < 0){
                cout << 'A' << '\n'
                     << nb;
            } else {
                cout << 'B' << '\n'
                     << na;
            }
            break;
        }
    }

    return 0;
}