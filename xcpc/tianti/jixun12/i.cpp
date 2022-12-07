#include <bits/stdc++.h>
using namespace std;
int n, ans[100005];
string a[100005];

int main(){
    scanf("%d", &n);
    getchar();
    for (int i = 1; i <= n;i++){
        getline(cin, a[i]);
    }
    for (int i = 1; i <= n;i++){
        int cnt = 0;
        int s = a[i].size();
        for (int j = 1; j <= n;j++){
            if(j == i){
                cnt++;
                continue;
            }
            int ns = a[j].size();
            int al = a[j].rfind(a[i]);
            if(al != string::npos &&  al == ns - s){
                cnt++;
            }
        }
        ans[i] = cnt;
    }
    for (int i = 1; i <= n;i++){
        // cout << ans[i] << '\n';
        printf("%d\n", ans[i]);
    }
    return 0;
}