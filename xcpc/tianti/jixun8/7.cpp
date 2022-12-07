#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    int da[105];
    for (int i = 0; i < 105;i++){
        da[i] = i;
    }
    cin >> n >> m;
    while(n--){
        string a;
        cin >> a;
        stack<int> s;
        bool flag = true;
        for (int i = 0; i < a.size();i++){
            if(s.size() > m){
                flag = false;
                break;
            }
            if(a[i] == 'S'){
                s.push(da[i]);
            } else {
                if(!s.empty()){
                    s.pop();
                } else {
                    flag = false;
                    break;
                }
            }
        }
        if(flag && s.empty()){
            cout << "YES";
        } else {
            cout << "NO";
        }
        cout << '\n';
    }

    return 0;
}