#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;

int main(){
    int t,te;
    vector<P> ans;
    while(scanf("%d %d", &t, &te) != EOF){
        ans.push_back(P(t, te));
    }
    int num = 0;
    for (int i = 0; i < ans.size();i++){
        int a = ans[i].first * ans[i].second;
        if(a){
            num++;
        }
    }
    num--;
    for (int i = 0; i < ans.size();i++){
        int a = ans[i].first * ans[i].second;
        if(a){
            cout << a << ' ' << ans[i].second - 1;
            if(num){
                cout << ' ';
                num--;
            }
        }
    }

    return 0;
}