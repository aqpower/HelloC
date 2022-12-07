#include <bits/stdc++.h>
using namespace std;

int main(){
    int l, n;
    cin >> l >> n;
    int c[10];
    fill(c, c + 10, 26);
    int now = l;
    n--;
    while(n--){
        if(c[now] == 1){
            c[now] = 26;
            while(c[now - 1] == 1){
                c[now - 1] = 26;
                now--;
            }
            c[now - 1]--;
        } else {
            c[now]--;
        }
    }

    return 0;
}