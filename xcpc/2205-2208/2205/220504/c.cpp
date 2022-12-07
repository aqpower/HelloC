#include <bits/stdc++.h>
using namespace std;
bool has[(int)1e8+5];
int main(){
    int n, m;
    cin >> n >> m;
    int t;
    for (int i = 0; i < n;i++){
        scanf("%d", &t);
        has[t] = true;
    }
    int x;
    while(m--){
        scanf("%d", &x);
        if(has[x]){
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}