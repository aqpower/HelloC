#include <bits/stdc++.h>
using namespace std;
int dat[10][10];
int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n;i++){
        for (int j = 0; j < n;j++){
            cin >> dat[i][j];
        }
    }
    bool fg = false;
    for (int i = 0; i < n;i++){
        int ind_max = -1, max = -1;
        for (int j = 0; j < n;j++){
            if(dat[i][j] > max){
                max = dat[i][j];
                ind_max = j;
            }
        }
        bool fi = false;
        for (int k = 0; k < n;k++){
            if(k == i){
                continue;
            }
            if(dat[k][ind_max] < dat[i][ind_max]){
                fi = true;
                break;
            }
        }
        if(!fi){
            cout << i << ' ' << ind_max << '\n';
            return 0;
        }
    }
    cout << "NO" << '\n';
    return 0;
}