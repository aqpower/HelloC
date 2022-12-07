#include <bits/stdc++.h>
using namespace std;
const int maxn = 505;
bool adj[maxn][maxn];
int road[maxn];
bool isgu[maxn];
int main(){
    int n, m, c1, c2;
    cin >> n >> m;
    while(m--){
        cin >> c1 >> c2;
        road[c1]++;
        road[c2]++;
        adj[c1][c2] = true;
        adj[c2][c1] = true;
    }
    for (int i = 0; i < n;i++){
        if(!road[i]){
            isgu[i] = true;
        }
    }
    int k, at;
    cin >> k;
    while(k--){
        cin >> at;
        bool flag = false;
        for (int i = 0; i < n;i++){
            if(adj[at][i]){
                adj[i][at] = false;
                road[i]--;
                if(road[i] == 0){
                    flag = true;
                }
            }
        }
        n--;
        if (flag){
            printf("Red Alert: City %d is lost!\n", at);
        }
        else{
            printf("City %d is lost.\n", at);
        }
    }
    if(!n){
          cout << "Game Over.";
     }
    return 0;
}