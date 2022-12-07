#include <bits/stdc++.h>
using namespace std;
void print_subset(int n){
	for(int i =0;i < (1 << n);i++){
		for(int j = 0;j < n;j++){
			if(i & (1 << j)){
				cout << j << ' ';
			}
		}
		cout << '\n';
	}
}
void print_set(int n, int k){
	for(int i =0;i < (1 << n);i++){
		int num = 0, kk = i;
		while(kk){
			//kk = (kk)&(kk - 1);
			kk -= (kk)&(-kk);
			num++;
		}
		if(num == k){
			for(int j =0;j<n;j++){
				if(i & (1 << j)){
					cout << j << ' ';
				}
			}
			cout << '\n';
		}
	}
}
int main(){
	int n;
	clock_t start, end;
	start = clock();
	
	print_set(13,9);
	end = clock();
	cout << (double)(end - start) / CLOCKS_PER_SEC << '\n';
	return 0;

}