#include <bits/stdc++.h>
using namespace std;

int main(){
    int a1, a2, b1, b2;
    scanf("%d/%d%d/%d", &a1, &b1, &a2, &b2);
    int aa = a1 * b2;
    int aa2 = a2 * b1;
    if(aa > aa2){
        cout << a1 << '/' << b1 << " > " << a2 << '/' << b2;
    } else if(aa == aa2){
        cout << a1 << '/' << b1 << " = "<< a2 << '/' << b2;
    } else {
        cout << a1 << '/' << b1 << " < "<< a2 << '/' << b2;
    }
    return 0;
}