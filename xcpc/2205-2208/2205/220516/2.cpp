#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n, m, q;
int father[maxn];
int findf(int a){
    if(a == father[a]){
        return a;
    }
    return findf(father[a]);
}
void unionfather(int a, int b){
    int fa = findf(a);
    int fb = findf(b);
    if(fa != fb){
        father[fa] = fb;
    }
}
int main(){
    cin >> n >> m >> q;
    for (int i = 0; i < n;i++){
        father[i] = i;
    }
    int a, b;
    while(m--){
        cin >> a >> b;
        unionfather(a, b);
    }
    while(q--){
        cin >> a >> b;
        if(findf(a) == findf(b)){
            cout << "Y";
        } else {
            cout << "N";
        }
        cout << '\n';
    }
    return 0;
}