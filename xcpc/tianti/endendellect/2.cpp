#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    cout << a << " + " << b << " = " << a + b << '\n';
    cout << a << " - " << b << " = " << a - b << '\n';
    cout << a << " * " << b << " = " << a * b << '\n';
    if(a % b == 0 || b % a == 0){
        cout << a << " / " << b << " = " << a / b << '\n';
    } else {
        double aa = a;
        printf("%.0lf / %d = %.2lf", aa, b, aa / b);
    }
    return 0;
}