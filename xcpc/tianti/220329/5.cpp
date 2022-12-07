#include <bits/stdc++.h>
using namespace std;

int main(){
    int dic[30];
    for (int i = 0;i<24;i++){
        cin >> dic[i];
    }
    int h;
    while(cin >> h, h>=0 && h < 24){
        cout << dic[h] << ' ';
        if(dic[h] > 50){
            cout << "Yes";
        } else {
            cout << "No";
        }
        cout << '\n';
    }
    return 0;
}