#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b;
    scanf("%d/%d", &a, &b);
    int d = __gcd(a, b);
    cout << (a / d) << '/' << (b / d);
    return 0;
}