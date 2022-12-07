#include <bits/stdc++.h>
using namespace std;
string s[55];
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n;i++){
            cin >> s[i];
        }
        int min = 1e9;
        for (int i = 0; i < n;i++){
            for (int j = i + 1; j < n;j++){
                int su = 0;
                for (int k = 0; k < m;k++){
                    su += abs(s[i][k] - s[j][k]);
                }
                if(su < min){
                    min = su;
                }
            }
        }
        cout << min << '\n';
    }

    return 0;
}