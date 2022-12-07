#include <bits/stdc++.h>
using namespace std;

int main(){
    string a;
    cin >> a;
    double sum = 0;
    bool fu = false, ou = false;
    for (int i = 0; i < a.size();i++){
        if(!i && a[i] == '-'){
            fu = true;
            continue;
        }
        int t = a[i] - '0';
        if(t == 2){
            sum++;
        }
        if(i == a.size() - 1 && t%2 == 0){
            ou = true;
        }
    }
    int w = a.size();
    if(fu){
        w--;
    }
    double ans = sum / w;
    if(fu){
        ans *= 1.5;
    }
    if(ou){
        ans *= 2;
    }
    ans *= 100;
    printf("%.2lf%%", ans);
}