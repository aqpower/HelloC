#include <bits/stdc++.h>
using namespace std;

int main(){
    int m;
    scanf("%d", &m);
    while(m--){
        int t;
        int ans = 0;
        scanf("%d", &t);
        while(t != 1){
            cout << t << '\n';
            ans++;
            if(t % 2){
                t--;
            } else {
                t /= 2;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}