#include <bits/stdc++.h>
using namespace std;


int main(){
    int n, t;
    cin >> n;
    int no = 0, nj = 0;
    while(n--){
        cin >> t;
        if(t%2){
            nj++;
        } else {
            no++;
        }
    }

    cout << nj << ' ' << no;

    return 0;
}