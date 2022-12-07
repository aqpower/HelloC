#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        int a[105],pow[105];
        map<int, int, greater<int>> mp;
        cin >> n >> m;
        for (int i = 0; i < n;i++){
            cin >> a[i];
        }
        for (int i = 0; i < n;i++){
            if(!i){
                pow[i] = a[i + 1];
            } else if(i == n - 1){
                pow[i] = a[i] - a[i - 1];
            } else {
                pow[i] = a[i + 1] - a[i - 1];
            }
            pow[i]--;
        }
        for (int i = 0; i < n;i++){
            cout << pow[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}