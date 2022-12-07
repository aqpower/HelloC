#include <bits/stdc++.h>
using namespace std;
int a[105];
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int tag = 0;
        for (int i = 1; i <= n;i++){
            cin >> a[i];
        }
        for (int i = 1; i <= n;i++){
            if(a[i] - tag > i){
                tag += a[i] - tag - i;
            }
        }
        cout << tag << '\n';
    }
    return 0;
}