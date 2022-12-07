#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e5;
int l[maxn], r[maxn];
int main(){
    int n, q;
    int left = 1;
    cin >> n >> q;
    for (int i = 0; i <= n; i++){
        l[i] = i - 1;
        r[i] = i + 1;
    }
    while (q--)
    {
        int t;
        scanf("%d", &t);
        if (t == left){
            left = r[t];
        }
        int nr = r[t];
        if (nr == n + 1)
        {
            nr = t;
            t = l[t];
        }
            r[l[t]] = nr;
            l[r[nr]] = t;
            l[nr] = l[t];
            l[t] = nr;
            r[t] = r[nr];
            r[nr] = t;
    }
    while(left != n + 1){
        printf("%d ", left);
        left = r[left];
    }
    
        return 0;
}