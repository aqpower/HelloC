#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,se,bs,bw,w,s;
    cin >> n;
    while(n--){
        cin >> se;
        if(se){
            bs = 130;
            bw = 27;
        } else{
            bs = 129;
            bw = 25;
        }
        cin >> s >> w;
        if(s > bs){
            cout << "ni li hai!";
        } else if(s == bs){
            cout << "wan mei!";
        } else {
            cout << "duo chi yu!";
        }
        cout << ' ';
        if(w > bw){
            cout << "shao chi rou!";
        } else if(w == bw){
            cout << "wan mei!";
        } else {
            cout << "duo chi rou!";
        }
        cout << '\n';
    }
    return 0;
}