#include <bits/stdc++.h>
using namespace std;
int a[1005];
void init(){
    for (int i = 0, j = 1; j <= 1000;i++){
        if(i % 3 != 0 && i % 10 != 3){
            a[j++] = i;
        }
    }
}
int main(){
    init();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << a[n] << '\n';
    }
    return 0;
}