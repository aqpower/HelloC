#include <bits/stdc++.h>
using namespace std;
int a[105];
int b[105];
int main(){
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        memset(b, 0, sizeof(b));
        int n;
        cin >> n;
        for (int i = 0; i < n;i++){
            cin >> a[i];
            b[a[i]]++;
        }
        for (int i = 0; i < n; i++)
        {
            if (b[a[i]] == 1){
                cout << i + 1 << '\n';
                break;
            }
        }
    }
    return 0;
}