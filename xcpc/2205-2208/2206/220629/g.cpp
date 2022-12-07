#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn], b[maxn];
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        int ind = -1;
        for (int i = 0; i < n;i++){
            scanf("%d", &a[i]);
            if(a[i] == 1){
                ind = i;
            }
        }
        if(ind == 0 && n == 1){
            cout << 1 << ' ' << '\n';
            continue;
        }
        int ne = ind + 1, pre = ind - 1;
        b[ind] = a[0];
        for (int i = 1; i < ind;i++){
            if(a[i] < b[pre + 1]){
                b[pre] = a[i];
                pre--;
            } else {
                b[ne] = a[i];
                ne++;
            }
        }
        if(ind){
            printf("1 ");
        }
        for (int i = pre + 1; i < ne;i++){
            printf("%d ", b[i]);
        }
        for (int i = ind + 1; i < n;i++){
            printf("%d ", a[i]);
        }
        putchar('\n');
    }
    return 0;
}