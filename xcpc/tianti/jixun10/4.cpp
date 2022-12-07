#include <bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin >> n;
    string s;
    int b, m;
    getchar();
    vector<string> ans;
    while(n--){
        cin >> s >> b >> m;
        getchar();
        if(b>20||b<15||m>70||m<50){
            ans.push_back(s);
        }
    }
    for (int i = 0; i < ans.size();i++){
        cout << ans[i] << '\n';
    }

        return 0;
}