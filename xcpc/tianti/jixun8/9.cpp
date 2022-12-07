#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[105], b[105];
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    for (int i = 0; i < n;i++){
        cin >> b[i];
    }
    bool flag = false;
    cout << "Insertion Sort" << '\n';
    for (int i = 1; i < n;i++){
        if(b[i] > b[i + 1]){
            int t = b[i];
            int j;
            for ( j = 0; j < n;j++){
                if(b[j] > t){
                    break;
                }
            }
            int p = b[j];

        }
        
    }
    for (int i = 0; i < n;i++){
        cout << b[i];
        if(i != n - 1){
            cout << ' ';
        }
    }

        return 0;
}