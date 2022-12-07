#include <bits/stdc++.h>
using namespace std;
int main(){
    double a, b, c;
    cin >> a >> b >> c;
    double m = a + b + c * pow(2, 63) - c *  pow(2,62);
    printf("%.0lf\n", m);
    return 0;
}