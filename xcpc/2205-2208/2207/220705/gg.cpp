#include <bits/stdc++.h>
using namespace std;

int main(){
    int n1, n2, x, y;
    cin >> n1 >> n2 >> x >> y;
    int v = -1;
    int g = 0, ma = 0, mb = 0;
    for (int i = 1;;i++){
        if(i % x == 0){
            mb++;
        } else if(i % y == 0){
            ma++;
        } else {
            g++;
        }
        if(g - n1 + ma + mb >= n2 && g + ma >= n1 && g + mb >= n2){
            v = i;
            break;
        }
    }
    cout << v << '\n';
    return 0;
}