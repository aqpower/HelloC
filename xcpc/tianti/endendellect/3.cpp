#include <bits/stdc++.h>
using namespace std;
int m, n;
int wor[25][25] = {0};
int num = 0;
struct pai{
    int val, m, n;
    pai(int _val, int _m,int _n):val(_val),m(_m),n(_n) {}
};
bool judge(int a,int b){
    int t = wor[a][b];
    if(t>wor[a-1][b]){
        if(t>wor[a+1][b]){
            if(t>wor[a][b+1]){
                if(t>wor[a][b-1]){
                    return true;
                }
            }
        }
    }
    return false;
}
int main(){
    cin >> m >> n;
    for (int i = 1; i <= m;i++){
        for (int j = 1; j <= n;j++){
            cin >> wor[i][j];
        }
    }
    vector<pai> ans;
    for (int i = 2; i < m;i++){
        for (int j = 2; j < n;j++){
            if(judge(i,j)){
                ans.push_back(pai(wor[i][j], i, j));
                num++;
            }
        }
    }
    if(num){
        for (int i = 0; i < ans.size();i++){
            cout << ans[i].val << ' ' << ans[i].m << ' ' << ans[i].n << '\n';
        }
    } else {
        cout << "None " << m << ' ' << n;
    }
        return 0;
}