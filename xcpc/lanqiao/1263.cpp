#include <bits/stdc++.h>
using namespace std;

int main(){
    int m, n;
    while(cin >> m >> n){
        char wor[1005][1005];
        fill(wor[0], wor[0] + 1005 * 1005, '.');
        int l = n / 2;
        int aj = l * 2 + m;
        int nl = 1, nj = 1;
        while(nl <= l){
            for (int j = nj; j < nj + m;j++){
                wor[nl][j] = '*';
            }
            nj++;
            nl++;
        }
        nl = 1, nj = aj;
        while(nl <= l){
            for (int j = nj; j > nj - m;j--){
                wor[nl][j] = '*';
            }
            nj--;
            nl++;
        }
        for (int i = l + 1; i < l + 1 + m;i++){
            wor[nl][i] = '*';
        }
        for (int i = 1; i <= l + 1;i++){
            for (int j = 1; j <= aj;j++){
                cout << wor[i][j];
            }
            cout << '\n';
        }
        for (int i = l; i >= 1;i--){
            for (int j = 1; j <= aj;j++){
                cout << wor[i][j];
            }
            cout << '\n';
        }
    }
    return 0;
}