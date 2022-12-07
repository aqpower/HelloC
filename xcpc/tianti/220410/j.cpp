#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e4 + 5;
int father[maxn];
void init(int n){
    for (int i = 1; i <= n;i++){
        father[i] = i;
    }
}
int findfather(int n){
    if(father[n] == n){
        return n;
    }
    return father[n] = findfather(father[n]);
}
void unionfather(int a, int b){
    int fa = findfather(a);
    int fb = findfather(b);
    if(fa!=fb){
        father[fa] = fb;
    }
}
int main(){
    int n, m;
    int mycase = 1;
    while(cin >> n >> m,n!=0 && m!=0){
        init(n);
        int c1, c2;
        while(m--){
            cin >> c1 >> c2;
            unionfather(c1, c2);
        }
        set<int> ans;
        for (int i = 1; i <= n;i++){
            ans.insert(findfather(i));
        }
        printf("Case %d: %d\n", mycase++, ans.size());
    }
    return 0;
}