#include <bits/stdc++.h>
using namespace std;
struct P{
    double d;
    int num;
} a[1005];
bool cmp(P a, P b){
    return a.d < b.d;
}

int main(){
    int n, s,x,y;
    cin >> n >> s;
    for (int i = 0; i < n;i++){
        cin >> x >> y >> a[i].num;
        a[i].d = sqrt(x * x + y * y);
    }
    sort(a, a + n, cmp);
    double mind = -1;
    for (int i = 0; i < n;i++){
        s += a[i].num;
        if(s >= 1e6){
            mind = a[i].d;
            break;
        }
    }
    if(mind != -1){
        printf("%.7lf\n", mind);
    } else {
        cout << -1 << '\n';
    }
    return 0;
}