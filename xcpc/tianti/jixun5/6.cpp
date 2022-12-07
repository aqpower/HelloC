#include <bits/stdc++.h>
using namespace std;
int num;
struct iden{
    string pass;
    int ntry;
    int desk;
}date[1005];
int main(){
    cin >> num;
    for (int i = 0; i < num;i++){
        cin >> date[i].pass >> date[i].ntry >> date[i].desk;
    }
    int nm,m[1005];
    cin >> nm;
    for (int i = 0; i < nm;i++){
        cin >> m[i];
    }
    for (int i = 0; i < nm;i++){
        int tar;
        for (tar = 0; tar < num;tar++){
            if(date[tar].ntry == m[i])
                break;
        }
        cout << date[tar].pass << ' ' << date[tar].desk << '\n';
    }
    return 0;
}