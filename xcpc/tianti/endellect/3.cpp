#include <bits/stdc++.h>
using namespace std;

int ans(int a){
    int sum = 1;
    for (int i = 2; i <= a;i++){
        sum *= i;
    }
    return sum;
}

int main(){
    int n,sum = 0;
    cin >> n;
    for (int i = 1; i <= n;i++){
        sum += ans(i);
    }
    cout << sum;

    return 0;
}