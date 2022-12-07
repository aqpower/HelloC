#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn];
int p[maxn];
int main(){
    int n;
    scanf("%d", &n);
    int l = 1,nl = 1;
    for (int i = 0; i < n;i++){
        scanf("%d", &a[i]);
        if(i){
            if(a[i] > a[i-1] * 2 && a[i] > a[i-1]){
                l = max(l, nl);
                nl = 1;
            } else {
                nl++;
            } 
        }
    }
    l = max(l, nl);
    cout << l << '\n';
    return 0;
}