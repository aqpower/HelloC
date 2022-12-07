#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
const int maxn = 1e5 + 5;
int a[maxn];
bool used[maxn];
int k,n;
bool myfind(int x){
    int l = 1, r = n - 1;
    while(l <= r){
    // cout << 'A' << '\n';
        int mid = ((r + l) >> 1);
        if(a[mid] == x){
            used[mid] = true;
            return true;
        } else if(a[mid] < x){
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return false;
}
int main(){
    scanf("%d%d", &k, &n);
    for (int i = 0;i<n;i++){
        scanf("%d", &a[i]);
    }
    P ans[10000];
    int cnt = 0;
    sort(a, a + n);
    for (int i = 0; i < n;i++){
        if(used[i] || a[i] == k/2){
            continue;
        }
        if(myfind(k - a[i])){
            used[i] = true;
            ans[cnt++] = make_pair(a[i],k - a[i]);
        }
    }
    if(cnt == 0){
        printf("No Solution\n");
    } else {
        for (int i = 0; i < cnt;i++){
            cout << ans[i].first << ' ' << ans[i].second << '\n';
        }
    }
    
        return 0;
}