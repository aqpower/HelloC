#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5;
int father[maxn];
bool isfather[maxn] = {false};
int findfather(int a){
    if(father[a] == a){
        return a;
    }
    return findfather(father[a]);
}
void myunion(int a,int b){
    int fa = findfather(a);
    int fb = findfather(b);
    if(fa!=fb){
        father[fa] = fb;
    }
}
int main(){
    set<int> wor;
    for (int i = 0; i < maxn;i++){
        father[i] = i;
    }
    int n;
    cin >> n;
    for (int k = 0; k < n;k++){
        int num = 0, t;
        vector<int> dat;
        cin >> num;
        while(num--){
            cin >> t;
            wor.insert(t);
            dat.push_back(t);
        }
        for (int i = 1; i < dat.size();i++){
            myunion(dat[i], dat[i - 1]);
        }
    }
    for (auto i = wor.begin(); i != wor.end();i++){
        isfather[findfather(*i)] = true;
    }
    int sumf = 0;
    for (int i = 0;i<maxn;i++){
        if(isfather[i]){
            sumf++;
        }
    }
    cout << wor.size() << ' ' << sumf << '\n';
    int q, c1, c2;
    cin >> q;
    while(q--){
        cin >> c1 >> c2;
        if(findfather(c1)==findfather(c2)){
            cout << 'Y';
        } else {
            cout << 'N';
        }
        cout << '\n';
    }

        return 0;
}