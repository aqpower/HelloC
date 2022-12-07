#include <bits/stdc++.h>
using namespace std;
int unsam(int n){
    string s = to_string(n);
    while(s.size() < 4){
        s.insert(0, "0");
    }
    set<char> se;
    for (int i = 0; i < s.size();i++){
        se.insert(s[i]);
    }
    return se.size();
}
int main(){
    int y,n;
    cin >> y >> n;
    int dy = y;
    while (true){
        if(unsam(dy) == n){
            printf("%d %04d\n", dy - y, dy);
            break;
        }
        dy++;
    }
    return 0;
}