#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    getchar();
    getline(cin, s);
    int len = s.size();
    int m = len / n;
    if(len%n!=0){
        m++;
    }
    char a[105][105];
    int now = 0;
    fill(a[0], a[0] + 105 * 105, ' ');
    for (int i = m;;i--){
        for (int j = 1; j <= n;j++){
            a[j][i] = s[now++];
            if(now == len){
                for (int ii = 1; ii <= n;ii++){
                    for (int jj = 1; jj <= m;jj++){
                        cout << a[ii][jj];
                    }
                    cout << '\n';
                }
                    return 0;
            }
        }
    }
        return 0;
}