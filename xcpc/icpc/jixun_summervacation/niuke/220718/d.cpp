#include <bits/stdc++.h>
using namespace std;
double cal(int d, int r){
    double xita = asin(1.0 * d / r);
    double l = xita * r;
    return 2 * l;
}
int main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int r;
        cin >> r;
        int x, y, d;
        cin >> x >> y >> d;
        double ans;
        if(x){
            double l1,l2;
            if(x < 0){
                l1 = cal(fabs(x + d), r);
                l2 = cal(fabs(x - d), r);
                ans = l2 / 2 + l1 / 2;
            } else {
                l1 = cal(fabs(x - d), r);
                l2 = cal(fabs(x + d), r);
                ans = l2 / 2 + l1 / 2;
            }
        } else {
            ans = cal(d, r);
        }
        printf("%.6lf", ans);
    }
    return 0;
}
