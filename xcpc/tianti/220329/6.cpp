#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int a[15];
    cin >> n;
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    int sum = 0;
    for (int i = 0; i < n;i++){
        for (int j = 0;j<n;j++){
            if(i == j){
                continue;
            } else {
                sum += a[i] * 10 + a[j];
            }
        }
    }
    cout << sum;
    return 0;
}