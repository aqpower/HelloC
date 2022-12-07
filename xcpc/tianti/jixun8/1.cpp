#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[10005];
    double sum = 0, ave, ans = 0;
    for (int i = 0; i < n;i++){
        cin >> a[i];
        sum += a[i];
    }
    ave = sum / n;
    for (int i = 0; i < n;i++){
        ans += pow(a[i] - ave, 2);
    }
    ans /= n;
    ans = sqrt(ans);
    printf("%.5lf", ans);


    return 0;
}