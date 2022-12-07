#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n + 3] = {0}, dic[n+3][n+3] = {0};
        for (int i = 1; i <= n;i++){
            for (int j = i + 1; j <= n;j++){
                if(a[i] - a[j] >= 3){
                    dic[i][j] = -1;
                    a[j] += 3;
                }
                else if(a[j] - a[i] >= 3){
                    dic[i][j] = 1;
                    a[i] += 3;
                } else {
                    dic[i][j] = 0;
                    a[i]++;
                    a[j]++;
                }
            }
        }
        for (int i = 1; i <= n;i++){
            cout << a[i] << ' ';
        }
        cout << endl;
        for (int i = 1; i <= n;i++){
            for (int j = i + 1; j <= n;j++){
                cout << dic[i][j] << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}