#include <bits./stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> dat[55];
    for (int k = 1; k <= n;k++){
        int sumn, t;
        cin >> sumn;
        while(sumn--){
            cin >> t;
            dat[k].push_back(t);
        }
    }
    int k, c1,c2;
    cin >> k;
    while(k--){
        cin >> c1 >> c2;
        vector<int> a = dat[c1], b = dat[c2];
        vector<int> sam;
        int sum = 0;
        sort(a.begin(), a.end());
        int na = unique(a.begin(), a.end())- a.begin();
        sort(b.begin(), b.end());
        int nb = unique(b.begin(), b.end()) - b.begin();
        set<int> ab;
        for (int i = 0; i < a.size();i++){
            ab.insert(a[i]);
        }
        for (int i = 0; i < b.size();i++){
            ab.insert(b[i]);
        }
        sum = na + nb;
        double nna = a.size() + b.size() - ab.size();
        double ans = nna / sum * 100;
        printf("%.2lf%%\n", ans);
    }

    return 0;
}