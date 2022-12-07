#include <bits/stdc++.h>
using namespace std;

int main(){
    double n;
    cin >> n;
    double max = -1, t;
    for (int i = 0; i < 12;i++){
        cin >> t;
        if(t > max){
            max = t;
        }
    }
    printf("%.2lf", max * n);
    return 0;
}