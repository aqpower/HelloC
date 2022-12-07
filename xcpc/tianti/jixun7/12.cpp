#include <bits/stdc++.h>
using namespace std;
const int maxn = 30005;
int father[maxn];
int findfather(int a){
    if(father[a] == a){
        return a;
    }
    return findfather(father[a]);
}
void myunion(int a, int b){
    int fa = findfather(a);
    int fb = findfather(b);
    if(fa != fb){
        father[fa] = fb;
    }
}
bool isfa[maxn] = {false};
int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < maxn;i++){
        father[i] = i;
    }
    while(m--){
        int num, t;
        vector<int> p;
        cin >> num;
        while(num--){
            cin >> t;
            p.push_back(t);
        }
        for (int i = 1; i < p.size();i++){
            myunion(p[i - 1], p[i]);
        }
    }
    for (int i = 1; i <= n;i++){
        isfa[findfather(i)] = true;
    }
    int max = -1;
    for (int i = 1; i <= n;i++){
        if(isfa[i]){
            int now = 0;
            for (int j = 1; j <= n;j++){
                if(findfather(j) == i){
                    now++;
                }
            }
            if(now > max){
                max = now;
            }
        }
    }
    cout << max;

    return 0;
}