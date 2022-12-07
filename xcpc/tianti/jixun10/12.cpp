#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    while(k--){
        bool f = true;
        int  t, top = 1;
        stack<int> wor;
        for (int i = 0; i < n;i++){
            cin >> t;
            if (t == top){
                top++;
                while(!wor.empty() && wor.top() == top){
                    wor.pop();
                    top++;
                }
            } else {
                wor.push(t);
                if(wor.size() > m){
                    f = false;
                }
            }
        }
        if(!wor.empty()){
            f = false;
        }
        if(f){
            cout << "YES";
        } else {
            cout << "NO";
        }
        cout << '\n';
    }

    return 0;
}
