#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        set<int> se;
        for (int i = 1; i * i <= n;i++){
            se.insert(i * i);
            if(pow(i,3) <= n){
                se.insert(pow(i,3));
            }
        }
        cout << se.size() << '\n';
    }
    return 0;
}


