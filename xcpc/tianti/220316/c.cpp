#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int wor[10] = {0};
    cin >> n;
    getchar();
    string a;
    cin >> a;
    for (int i = 0; i < a.size();i++){
        if(a[i] == 'L'){
            for (int j = 0; j < 10;j++){
                if(!wor[j]){
                    wor[j] = 1;
                    break;
                }
            }
        } else if(a[i] == 'R'){
            for (int j = 9; j >= 0;j--){
                if(!wor[j]){
                    wor[j] = 1;
                    break;
                }
            }
        } else {
            int now = a[i] - '0';
            wor[now] = 0;
        }
    }

    for (int i = 0; i < 10;i++){
        cout << wor[i];
    }

        return 0;
}