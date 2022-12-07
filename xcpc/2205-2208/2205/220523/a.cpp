#include <bits/stdc++.h>
using namespace std;
bool judge(int a){
    for (int i = 2; i <= sqrt(a);i++){
        if(a % i == 0){
            return false;
        }
    }
    return true;
}
int main(){
    int t = 5;
    while(t--){
        int n;
        cin >> n;
        string sa = to_string(n),sb;
        sb = sa;
        reverse(sa.begin(), sa.end());
        bool fg = false;
        if(n / 100000 == 0 && sa == sb && judge(n)){
            fg = true;
        } 
       if(fg){
           cout << "Yes";
       } else {
           cout << "No";
       }
       cout << '\n';
    }
    return 0;
}