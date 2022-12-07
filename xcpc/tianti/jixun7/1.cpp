#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int s, h, w, dh, dw;
    for (int i = 0; i < n;i++){
        bool flag = true;
        cin >> s >> h >> w;
        if(s){
            dh = 130, dw = 27;
        } else {
            dh = 129, dw = 25;
        }
            if(h > dh){
                cout << "ni li hai!";
            } else if (h == dh) {
                cout << "wan mei!";
            } else {
                cout << "duo chi yu!";
            }
            cout << ' ';
            if(w > dw){
                cout << "shao chi rou!";
            } else if(w == dw){
                cout << "wan mei!";
            } else {
                cout << "duo chi rou!";
            }
            cout << '\n';
    }

    return 0;
}