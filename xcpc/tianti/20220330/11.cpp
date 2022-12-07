#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const int maxn = 205;
int adj[maxn][maxn];
bool vis[maxn];
int d[maxn];
int main(){
	fill(adj[0],adj[0]+maxn*maxn,inf);
	int n,m, c1, c2, cost;
	cin >> n >> m;
	for(int i =0;i<m;i++){
		cin >> c1 >> c2 >> cost;
		adj[c1][c2] = cost;
		adj[c2][c1] = cost;
	}
    int k, ans = 0, mint = inf, minn = maxn;
	cin >> k;
	for(int ik =1;ik<=k;ik++) {
		int np, tp;
		int troad[maxn];
		cin >> np;
		for(int i = 0;i < np;i++){
            cin >> troad[i];
        }
		if(np != n){
			continue;
		}
        int sum = 0;
		bool f = true;
		fill(vis,vis+maxn,false);
		int pre = 0;
		for(int i = 0;i < np;i++){
            int nowt = adj[pre][troad[i]];
            if(nowt != inf){
				sum += nowt;	
				vis[troad[i]] = true;
				pre = troad[i];
			} else {
				f = false;
				break;
			}
		}
		if(adj[troad[np-1]][0] == inf){
			f = false;
		} else {
			sum += adj[troad[np - 1]][0];
            for(int i = 1;i <= n;i++){
                if(!vis[i]){
                    f = false;
                    break;
                }
		    }
		}
		if(f){
			ans++;
            if(sum < mint){
				mint = sum;
                minn = ik;
            } 
		}
	}

	cout << ans << '\n' << minn << ' ' << mint << '\n';
	
    return 0;
}