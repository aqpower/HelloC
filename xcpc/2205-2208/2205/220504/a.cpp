#include <bits/stdc++.h>
using namespace std;
int dat[105][105];
int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++){
            cin >> dat[i][j];
        }
    }
    int t;
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++){
            cin >> t;
            dat[i][j] += t;
        }
    }
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++){
            cout << dat[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}