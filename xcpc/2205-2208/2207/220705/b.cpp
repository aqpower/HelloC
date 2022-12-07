#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn];
bool po[maxn];
int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n;i++){
        scanf("%d", &a[i]);
    }
    int ans = 1;
    for (int i = 2; i <= n;i++){
        bool fg = false;
        for (int j = 0; j + i < n;j++){
            if(po[j]){
                continue;
            }
            for (int k = j + 1;k < j + i;k++){
                if(po[k]){
                    break;
                }
                if(a[k] / a[k - 1] >= 2){
                    po[k - 1] = true;
                    break;
                }
                if(k == j+i-1){
                    fg = true;
                }
            }
            if(fg){
                ans = i;
                break;
            }
        }
        if(!fg){
            break;
        }
    }
    printf("%d\n", ans);
    return 0;
}