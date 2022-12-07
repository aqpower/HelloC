#include <bits/stdc++.h>
using namespace std;

int main(){
    char c, t, te;
    int h;
    cin >> c >> h;
    t = c, te = c;
    int dl = h / 2;
    int l = h / 2 + 1;
    for (int i = 0; i < l;i++){
        t = c++;
        for (int j = 0; j < dl - i;j++){
            cout << ' ';
        }
        cout << t;
        if(i != 0){
            for (int j = 0; j < 2 * i - 1;j++){
                cout << ' ';
            }
            cout << t;
        }
        cout << '\n';
    }
    t = te;
    c -= 2;
    for (int i = dl - 1; i >= 0;i--){
        t = c--;
        for (int j = 0; j < dl - i;j++){
            cout << ' ';
        }
        cout << t;
        if(i != 0){
            for (int j = 0; j < 2 * i - 1;j++){
                cout << ' ';
            }
            cout << t;
        }
        cout << '\n';
    }

    return 0;
}