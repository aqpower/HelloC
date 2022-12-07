#include <bits/stdc++.h>
using namespace std;
char a[405][405];
int main(){
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int x = -1, y = -1, m ,nn;
        for (int i = 0; i < n;i++){
            for (int j = 0; j < n;j++){
                cin >> a[i][j];
                if(a[i][j] == '*'){
                    if(x == -1){
                        x = i;
                        y = j;
                    } else {
                        m = i;
                        nn = j;
                    }
                }
            }
        }
        if(m != x && y != nn){
            a[x][nn] = '*';
            a[m][y] = '*';
        } else if(y == nn){
            int toy = y + 1 < n ? y + 1 : 0;
            a[x][toy] = '*';
            a[m][toy] = '*';
        } else {
            int tox = x + 1 < n ? x + 1 : 0;
            a[tox][y] = '*';
            a[tox][nn] = '*';
        }
        for (int i = 0; i < n;i++){
            for (int j = 0; j < n;j++){
                cout << a[i][j];
            }
            cout << '\n';
        }
    }
    return 0;
}