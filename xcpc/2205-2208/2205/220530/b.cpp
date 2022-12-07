#include <bits/stdc++.h>
using namespace std;
int na[250], nb[250], ans[250];
int main(){
    string a, b;
    cin >> a >> b;
    bool isfir = true;
    int da = 0, db = 0;
    for (int i = 0; i < a.size();i++){
        if(a[i] == '0'){
            if(isfir){
                continue;
            }
        }
        isfir = false;
        na[da++] = a[i] - '0';
    }
    isfir = true;
    for (int i = 0; i < b.size();i++){
        if(b[i] == '0'){
            if(isfir){
                continue;
            }
        }
        isfir = false;
        nb[db++] = b[i] - '0';
    }
    reverse(na, na + da);
    reverse(nb, nb + db);
    int base = 0;
    int len = max(da, db);
    for (int i = 0; i < len;i++){
        ans[i] = na[i] + nb[i] + base;
        if(ans[i] > 9){
            ans[i] -= 10;
            base = 1;
        } else {
            base = 0;
        }
    }
    if(base){
        ans[len++] = 1;
    }
    if(!len){
        cout << 0;
    } else {
        reverse(ans, ans+len);
        for (int i = 0; i < len; i++)
        {
            cout << ans[i];
        }
    }
    return 0;
}