#include <bits/stdc++.h>
using namespace std;
int a[105];
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        set<int> ans;
        for (int i = 0; i < n;i++){
            scanf("%d", &a[i]);
            if(ans.count(a[i])){
                if(!ans.count(-a[i])){
                    ans.insert(-a[i]);
                }
            } else {
                ans.insert(a[i]);
            }
        }
        cout << ans.size() << '\n';
    }
    return 0;
}