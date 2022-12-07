#include <bits/stdc++.h>
using namespace std;
int na = 3, nb = 4, nc = 5;
int ans = 0;
string s;
void dfs(){
    if(s.size() == 12){
        // cout << s << '\n';
        ans++;
        return;
    }
    if(na){
        s.push_back('a');
        na--;
        dfs();
        na++;
        s.pop_back();
    }
    if(nb){
        s.push_back('b');
        nb--;
        dfs();
        nb++;
        s.pop_back();
    }
    if(nc){
        s.push_back('c');
        nc--;
        dfs();
        nc++;
        s.pop_back();
    }
}
int main(){
    dfs();
    cout << ans/12 << '\n';
    return 0;
}