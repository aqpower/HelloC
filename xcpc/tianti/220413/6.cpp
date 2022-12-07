#include <bits/stdc++.h>
using namespace std;
int wor[5][5];
bool sec[5][5];
bool used[12];
int main(){
    int  ti,tj;
    for (int i = 1; i <= 3;i++){
        for (int j = 1; j <= 3;j++){
            cin >> wor[i][j];
            used[wor[i][j]] = true;
            if(!wor[i][j]){
                ti = i;
                tj = j;
            }
        }
    }
    for (int i = 1; i <= 9;i++){
        if(!used[i]){
            wor[ti][tj] = i;
            sec[ti][tj] = true;
            break;
        }
    }
    int k = 3, x, y;
    while(k--){
        cin >> x >> y;
        sec[x][y] = true;
        cout << wor[x][y] << '\n';
    }
    int fun, sum = 0;
    cin >> fun;
    if(fun <= 3){
        for (int i = 1; i <= 3;i++){
            // if(sec[fun][i]){
                sum += wor[fun][i];
            // }
        }
    } else if(fun <= 6){
        fun -= 3;
        for (int i = 1; i <= 3;i++){
            // if(sec[i][fun]){
                sum += wor[i][fun];
            // }
        }
    } else if(fun == 7){
        for (int i = 1; i <= 3;i++){
            // if(sec[i][i]){
                sum += wor[i][i];
            // }
        }
    } else {
        for (int i = 1; i <= 3;i++){
            // if(sec[i][4 - i]){
                sum += wor[i][4 - i];
            // }
        }
    }
    int dic[24] = {10000, 36, 720, 360, 80, 252, 108, 72, 54, 180, 72, 180, 119, 36, 306, 1080, 144, 1800, 3600};
    cout << dic[sum - 6] << '\n';
    return 0;
}