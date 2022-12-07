#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    double sum, t;
    cin >> n;
    for (int i = 0; i < n;i++){
        cin >> t;
        sum += 1 / t;
    }
    printf("%.2f",1/(sum/n));

        return 0;
}