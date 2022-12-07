#include <bits/stdc++.h>
using namespace std;


int main(){
    int bui,lim[30];
    lim[1] = 1;
    for (int i = 2; i < 30;i++){
        lim[i] = lim[i-1] + 2 * (2 * i - 1);
    }
    int n;
    char c;
    scanf("%d %c", &n, &c);
    for (int i = 1; i < 50;i++){
        if(n <= lim[i]){
            if(n == lim[i]){
                bui = i;
            } else {
                bui = i - 1;
            }
            break;
        }
    }
    for (int i = 0; i < bui;i++){
        for (int j = 0; j < i;j++){
            cout << ' ';
        }
        for (int j = 0; j < 2 * (bui - i) - 1;j++){
            cout << c;
        }
        
        cout << '\n';
    }
    for (int i = bui - 2 ; i >= 0;i--){
        for (int j = 0; j < i;j++){
            cout << ' ';
        }
        for (int j = 0; j < 2 * (bui - i) - 1;j++){
            cout << c;
        }
        
        cout << '\n';
    }
    cout << n - lim[bui];

    return 0;
}