#include <bits/stdc++.h>
using namespace std;
// #define F(x) (ac *pow(x, 3) + ab *pow(x, 2) + aa * (x) + a0)
double ac, ab, aa, a0;
double F(double x){
    return (ac * pow(x, 3) + ab * pow(x, 2) + aa * (x) + a0);
}
int main(){
    cin >> ac >> ab >> aa >> a0;
    double a, b;
    cin >> a >> b;
    while(b - a > 0.01){
        if(F(a) * F(b) < 0){
            double mid = F((a + b) / 2);
            if(mid == 0){
                printf("%.2lf\n", (a + b) / 2);
                return 0;
            } else if(mid * F(a) > 0){
                a = (a + b) / 2;
            } else {
                b = (a + b) / 2;
            }
        } else {
            break;
        }
    }
    printf("%.2lf\n", (a + b) / 2);
    return 0;
}