#include <bits/stdc++.h>
using namespace std;

int main(){
    int l, n;
    cin >> l >> n;
    n--;
    int a[10];
    fill(a, a + 10, 0);
    int now = 0;
    while (n / 26){
        a[now++] = n % 26;
        n /= 26;
    } 
    a[now++] = n % 26;
    for (int i = 0; i < l;i++){
        a[i] = 26 - a[i];
        // cout << a[i] << ' ';
    }
    reverse(a, a + l);
    for (int i = 0; i < l;i++){
        printf("%c", 'a' + a[i] - 1);
    }

        return 0;
}