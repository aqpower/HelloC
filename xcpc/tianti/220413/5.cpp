#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n,m;
    cin >> n >> m;
    getchar();
    while(m--){
        string s;
        ll now = 1;
        getline(cin, s);
        for (int i = 0; i < s.size();i++){
                now *= 2;
            if(s[i] != 'y'){
                now++;
            } 
        }
        cout << now - pow(2, n) + 1 << '\n';
    }
    return 0;
}