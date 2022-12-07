#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    string a[105];
    getchar();
    for (int i = 0; i < n;i++){
        getline(cin, a[i]);
    }
    for (int i = 0; i < k;i++){
        for (int j = 0; j < n - 1;j++){
            if(a[j] > a[j+1]){
                swap(a[j], a[j + 1]);
            }
        }
    }
    for (int i = 0; i < n;i++){
        cout << a[i] << '\n';
    }
        return 0;
}