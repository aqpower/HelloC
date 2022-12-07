#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, t;
    vector<queue<int>> ve;
    queue<int> qut,qu;
    ve.push_back(qut);
    cin >> n;
    int top = n;
    for (int i = 0; i < n;i++){
        cin >> t;
        qu.push(t);
    }
    while(!qu.empty()){
        int now = qu.front();
        qu.pop();
        bool flag = false;
        if(now == top){
            for (int i = 0; i < ve.size();i++){
                if(ve[i].empty()){
                    flag = true;
                    break;
                }
            }
            if(!flag){
                ve.push_back(qut);
            }
            top--;
            for (int i = 0; i < ve.size();i++){
                if(!ve[i].empty() && ve[i].front() ==  top){
                    top--;
                    ve[i].pop();
                }
            }
        } else {
            for (int i = 0; i < ve.size();i++){
                if(ve[i].empty()){
                    ve[i].push(now);
                    flag = true;
                    break;
                }
                if(now < ve[i].back()){
                    ve[i].push(now);
                    flag = true;
                    break;
                }
            }
            if(!flag){
                queue<int> tt;
                tt.push(now);
                ve.push_back(tt);
            }
        }
    }
    cout << ve.size();
    return 0;
}