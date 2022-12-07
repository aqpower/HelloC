#include <bits/stdc++.h>
using namespace std;

int main(){
    char c;
    int n;
    cin >> c >> n;
    for (int i = 0; i < n/2+1;i++){
        char now = c++;
        for (int j = 0; j < n / 2-i;j++)
        {
            cout << ' ';
        }
        cout << now;
        for (int j = 0; j < 2 * i - 1;j++){
            cout << ' ';
        }
        if(i){
            cout << now;
        }
        cout << '\n';
    }
    c -= 2;
    for (int i = n/2 - 1; i >= 0;i--){
        char now = c--;
        for (int j = 0; j < n / 2-i;j++)
        {
            cout << ' ';
        }
        cout << now;
        for (int j = 0; j < 2 * i - 1;j++){
            cout << ' ';
        }
        if(i){
            cout << now;
        }
        cout << '\n';
    }

        return 0;
}