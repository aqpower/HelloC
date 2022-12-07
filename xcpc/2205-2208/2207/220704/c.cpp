#include <bits/stdc++.h>
using namespace std;
char a[10][10];
int main(){
    int t;
    cin >> t;
    while(t--){
        int r, l;
        for (int i = 0; i < 8;i++){
            for (int j = 0; j < 8;j++){
                cin >> a[i][j];
            }
        }
        for (int i = 1; i < 8;i++){
            for (int j = 1; j < 8;j++){
                if(a[i-1][j-1] == '#' && a[i+1][j-1] == '#' && a[i + 1][j + 1] == '#' && a[i-1][j+1] == '#'){
                    r = i + 1;
                    l = j + 1;
                    break;
                }
            }
        }
        cout << r << ' ' << l << '\n';
    }
    return 0;
}