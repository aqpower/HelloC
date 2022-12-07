#include <bits/stdc++.h>
using namespace std;
const int maxe = 510, inf = 1e9;
int n, m;
typedef long long LL;
struct edge{
    int from, to;
    LL cost;
    edge(){};
    edge(int _from, int _to, LL _cost):from(_from), to(_to), cost(_cost) {}
};
vector<edge> edg;
// ? int d[maxe]; 
// ? bool vis[maxe] = {false};
int father[maxe];
int findfather(int a){
    if(a == father[a]){
        return a;
    }
        return findfather(father[a]);
}
bool isSamefa(int a,int b){
    int fa = findfather(a);
    int fb = findfather(b);
    if(fa == fb){
        return true;
    }
    return false;
}
bool cmp(edge a,edge b){
    return a.cost < b.cost;
}
bool isTree(int &sum, int &numedge){
    sort(edg.begin(), edg.end(), cmp);
    for (int i = 0; i < m;i++){
        int c1 = edg[i].from, c2 = edg[i].to, w = edg[i].cost;
        if(!isSamefa(c1,c2)){
            father[c1] = c2;
            numedge++;
            sum += w;
        }
        if(numedge == n - 1){
            break;
        }
    }
    if(numedge == n - 1){
        return true;
    }
    return false;
}

int main(){
    int c1, c2;
    LL w;
    cin >> n >> m;
    for (int i = 1; i <= n;i++){
        father[i] = i;
    }
    for (int k = 0; k < m;k++){
        cin >> c1 >> c2 >> w;
        edg.push_back(edge(c1, c2, w));
    }
    int sum = 0, numedge = 0;
    if(isTree(sum,numedge)){
        cout << sum << '\n';
        cout << "Yes" << '\n';
    }
    else {
        cout << "No MST" << '\n';
        set<int> fa;
        for (int i = 1; i <= n;i++){
            fa.insert(findfather(i));
        }
        cout << fa.size() << '\n';
    }

    return 0;
}

