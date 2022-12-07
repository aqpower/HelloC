#include <bits/stdc++.h>
using namespace std;

int main(){
    string a;
    getline(cin, a);
    string ans;
    for (int i = 0; i < a.size();i++){
        if(a[i] >= 'A' && a[i] <= 'Z'){
            ans += a[i];
        }
    }
    if(ans.empty()){
        cout << "Not Found";
    } else {
        int tong[100];
        memset(tong, 0, sizeof(tong));
        for (int i = 0; i < ans.size();i++){
            int num = ans[i];
            if(!tong[num]){
                cout << ans[i];
                tong[num]++;
            }
        }
    }
    return 0;
}