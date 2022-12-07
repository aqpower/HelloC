#include <bits/stdc++.h>
using namespace std;
int n, mycount = 0;
vector<int> ans;
int sum = 0;
void dfs(int index){
    if(sum > n){
		return;
	}
	if(sum == n){
		cout << n << '=';
		for(int i =0;i < ans.size();i++){
			cout << ans[i];
			if(i != ans.size() - 1){
				cout << '+';
			}
		}
		mycount++;
		if(!(mycount % 4)){
			cout << '\n';
		} else {
			if(ans.size()!=1){
				cout << ';';	
			}
		}
		return;
	}
	for(int i = index;i <= n;i++){
			ans.push_back(i);
			sum += i;
			dfs(i);
			sum -= i;
			ans.pop_back();
			//!dfs(i); ! do not
	}
	
}
int main(){
	cin >> n;
	dfs(1);
	
	return 0;
}