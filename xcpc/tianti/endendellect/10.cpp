#include <bits/stdc++.h>
using namespace std;
int findfather(int a){
    return a / 2;
}
int main(){
    int n;
    cin >> n;
    int a[n + 3];
    for (int i = 1; i <= n;i++){
        cin >> a[i];
    }
    bool ifn = false;
    if(!a[1]){
        ifn = true;
    }
    int ii, jj;
    cin >> ii >> jj;
    if(!a[ii]){
        cout << "ERROR: T[" << ii << "] is NULL" << '\n';
        return 0;
    } else {
        if(!a[jj]){
            cout << "ERROR: T[" << jj << "] is NULL" << '\n';
            return 0;
        }
    }
    while(ii!=jj){
        if(ii > jj){
            ii = findfather(ii);
        } else {
            jj = findfather(jj);
        }
    }
    cout << ii << ' ' << a[ii];

    return 0;
}