#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n;
int main(){
    cin >> n;
    int a[maxn];
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    int num = 0, d;
    while(!is_sorted(a,a+n)){
        int now = find(a, a + n, 0) - a;
        if(now){
            for (int i = 0; i < n;i++){
                if(a[i] != i){
                    d = i;
                    break;
                }
            }
        }
        else {
            d = find(a, a + n, now) - a;}
        swap(a[now], a[d]);
        num++;
    }
    cout << num;
    return 0;
}