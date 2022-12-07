#include <bits/stdc++.h>
using namespace std;

int main(){
    string t, r;
    cin >> t >> r;
    int ind = 0;
    bool fg = true;
    int pr = 0, ne = 0;
    for (int i = 0; i < r.size();){
        if(t[ind] == r[i]){
            ind++;
            i++;
        } else {
            if(pr){
                fg = false;
                break;
            }
            pr = i + 1;
            i = r.size() - 1 - (t.size() - pr);
        }
    }
    if(fg){
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}