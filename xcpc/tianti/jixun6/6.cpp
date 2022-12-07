#include <bits/stdc++.h>
using namespace std;
int n;
int w[1005];
int main(){
    fill(w, w + 1005, 100);
    cin >> n;
    int t,maxn = -1;
    for (int i = 0; i < n;i++){
        cin >> t;
        for (int j = 1;;j++){
            if(w[j] - t >= 0){
                if(j > maxn){
                    maxn = j;
                }
                w[j] = w[j] - t;
                cout << t << ' ' << j << '\n';
                
                break;
            }
        }
    }
    cout << maxn;

    return 0;
}