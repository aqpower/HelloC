#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int main(){
    int n, a[maxn];
    cin >> n;
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    int sum = 0, max = -1, ind = -1;
    for (int i = 1; i < n;i++){
        if(a[i] > a[i-1]){
            sum++;
        } else {
            if(sum > max){
                max = sum;
                ind = i;
            }
            sum = 0;
        }
    }
            if(sum > max){
                max = sum;
                ind = n;
            }
    for (int i = ind - max - 1; i < ind;i++){
        cout << a[i];
        if(i!=ind - 1){
            cout << ' ';
        }
    }
    return 0;
}