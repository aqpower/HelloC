#include <bits/stdc++.h>
using namespace std;
int k = 1;
int num(int a){
    vector<int> aa;
    do{
        aa.push_back(a % 10);
        a /= 10;
    } while (a);
    int sum = 0;
    for (int i = 0; i < aa.size();i++){
        sum += aa[i];
    }
    sum *= 3;
    sum ++;
    return sum;
}
int pre = -1;
void print(int a){
    cout << k++ << ':' << a << '\n';
}
void solve(int a){
    int t = num(a);
    if(a == t){
        print(a);
        return;
    }
    print(t);
    pre = t;
    solve(t);
}
int main(){
    int n;
    cin >> n;
    solve(n);
    return 0;
}