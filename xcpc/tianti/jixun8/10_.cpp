#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n;
bool issort(int a[]){
    for (int i = 0; i < n;i++){
        if(a[i] != i){
            return false;
        }
    }
    return true;
}
int main(){
    cin >> n;
    int a[maxn];
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    int num = 0;
    while(!issort(a)){
        bool f = false;
        for (int i = 0; i < n;i++){
            if(!a[i]){
                for (int j = 0; j < n;j++){
                    if(j == i){
                        swap(a[i], a[j]);
                        num++;
                        f = true;
                        break;
                    }
                }
            } else {
                if(i == n-1){
                    cout << num;
                    return 0;
                }
            }
            if(f){
                break;
            }
        }
    }
    cout << num;
    return 0;
}