#include <bits/stdc++.h>
using namespace std;
int n,mycount = 0;

int main(){
    cin >> n;
    for (int i = 1; i <= 30;i++){
        for (int j = 1;j <= 75;j++){
            for (int k = 1;k <= 150;k++){
                if(i * 5 + j * 2 + k == 150 && i + j + k == 100){
                    cout << i << ' ' << j << ' ' << k << '\n';
                    mycount++;
                    if(mycount == n){
                        return 0;
                    }
                }
            }
        }
    }

        return 0;
}