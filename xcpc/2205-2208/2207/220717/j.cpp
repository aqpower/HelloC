#include <bits/stdc++.h>
using namespace std;
int a[1005];
int main(){
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    unordered_map<int, int> ad, su;
    for (int i = 0; i < n;i++){
        for (int j = 0; j < n;j++){
            ad[a[i] + a[j]] = 1;
            su[a[i] - a[j]] = 1;
        }
    }
    for (auto i = ad.begin(); i != ad.end();i++){
        if(su[(*i).first]){
            cout << "Yes" << '\n';
            return 0;
        }
    }
    cout << "No" << '\n';
    return 0;
}