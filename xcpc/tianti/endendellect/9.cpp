#include <bits/stdc++.h>
using namespace std;

int main(){
    int m, n, k;
    cin >> m >> n >> k;
    while(k--){
        int a[n];
        bool vis[n + 3] = {false};
        stack<int> s;
        for (int i = 0; i < n;i++){
            cin >> a[i];
        }
        int max = -1;
        bool f = false;
        for (int k = 0; k < n;k++){
            if(a[k] > max){
                max = a[k];
                for (int i = 1; i <= a[k];i++){
                    if(!vis[i]){
                        s.push(i);
                        vis[i] = true;
                    }
                }
                if(s.size() > m){
                    f = true;
                }
                s.pop();
            } else {
                if(a[k] != s.top()){
                    f = true;
                } else {
                    if(!s.empty()){
                        s.pop();
                    }
                }
            }
        }
        if(f){
            cout << "NO";
        } else {
            cout << "YES";
        }
        cout << '\n';
    }

    return 0;
}