#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    multiset<int> ans;
    while(cin >> n,n != -1){
        ans.insert(n);
    }
    while(cin >> n,n != -1){
        ans.insert(n);
    }
    if(ans.empty()){
        cout << "NULL";
    } else {
        for (auto i = ans.begin(); i != ans.end();i++){
            cout << (*i);
            if(i != --ans.end()){
                cout << ' ';
            }
        }
    }   
    return 0;
}