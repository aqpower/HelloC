#include <bits/stdc++.h>
using namespace std;
int n, m, en,em;
bool wor[1001][1001];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
typedef pair<int, int> P;
bool vis[1001][1001];
map<P, P> fly;
struct node{
	int x,y, take;
	node(int dx, int dy, int ta = 1): x(dx), y(dy), take(ta){}
	node(){}
};
bool isend(int x, int y){
	return x==en && y==em;
}
bool isvaild(int x,int y){
	if(x < 1 || y < 1 || x > n || y > m){
		return false;
	}
	if(!wor[x][y]){
		return false;
	}
	return true && (!vis[x][y]);
}
int main(){
	bool flag = true;
	char t;
	scanf("%d %d", &n, &m);
	getchar();
	for(int i =1;i<=n;i++){
		for(int j =1;j<=m;j++){
			scanf("%c",&t);
			if(t == '.'){
				wor[i][j] = true;
			}
		}
		getchar();
	}
	int q, qa, qb, qc, qd;
	scanf("%d", &q);
	for(int i =0;i<q;i++){
		scanf("%d%d%d%d",&qa, &qb, &qc, &qd);
		fly[P(qa,qb)] = P(qc,qd);
	}
	scanf("%d%d", &en, &em);
	node s = node(1,1);
	s.take = 0;
	queue<node> qu;
	qu.push(s);
	int take = 0;
	while(!qu.empty()){
		node top = qu.front();
		qu.pop();
		int nowx = top.x, nowy = top.y, nt = top.take;
		vis[nowx][nowy] = true;
		if(isend(nowx,nowy)){
			flag = false;
			cout << nt;
			break;
		}
		if(fly.count(P(nowx, nowy)) != 0){
			P ed = fly[P(nowx, nowy)];
			nowx = ed.first;
			nowy = ed.second;
			if(!wor[nowx][nowy]){
				flag = false;
				break;
			}
		}
		if(isend(nowx,nowy)){
			flag = false;
			cout << nt;
			break;
		}
		node to;
		for(int i =0;i<4;i++){
			for(int j =0;j<4;j++){
				int tox = nowx+dx[i],toy = nowy+dy[i];
				if(isvaild(tox, toy)){
					to.x = tox,to.y= toy,to.take = nt+1;
					qu.push(to);
				}
			}
		}
	}
	if(flag){
		cout << "No solution" << '\n';
	}
	
	
	return 0;
}