#include <iostream>
using namespace std;

int main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    string n;
    cin >> n;
    if(n.size() == 1){
        cout << n << '\n';
    } else {
        bool fg = true;
        for (int i = 0; i < n.size() - 1;i++){
            if(n[i] != '9'){
                fg = false;
                break;
            }
        }
        if(fg){
            cout << n << '\n';
        } else {
            for (int i = 0; i < n.size() - 1;i++){
                putchar('9');
            }
        }
    }
    return 0;
}