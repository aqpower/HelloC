#include <bits/stdc++.h>
using namespace std;
int swa(int a, int b){
    return 1225 - (a + a - 1) + (a * (a - 1)) - (b + b - 1) + (b * (b - 1));
}
int main(){
    for (int i = 2; i <= 49;i++){
        for (int j = 2; j <= 49;j++){
            if(abs(j - i) <= 1){
                continue;
            }
            if(swa(i,j) == 2015){
                cout << i - 1 << '\n';
            }
        }
    }
    cout << -1 << '\n';
    return 0;
}