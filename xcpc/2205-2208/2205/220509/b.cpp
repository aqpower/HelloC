#include <bits/stdc++.h>
using namespace std;
int a[50][50];
int n;
void solution(int now, int i, int j){
    if(now == n * n + 1){
        return;
    }
    int l, r;
    if(i == 1 && j == n){
        a[i][j] = now;
        solution(now + 1, i + 1, j);
    } else if(j == n){
        a[i][j] = now;
        solution(now + 1, i - 1, 1);
    } else if(i == 1){
        a[i][j] = now;
        solution(now + 1, n, j + 1);
    } else if(a[i - 1][j + 1]){
        a[i][j] = now;
        solution(now + 1, i + 1, j);
    } else {
        a[i][j] = now;
        solution(now + 1, i - 1, j + 1);
    }
}
int main(){
    cin >> n;
    n = 2 * n - 1;
    solution(1, 1, n / 2 + 1);
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= n;j++){
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}