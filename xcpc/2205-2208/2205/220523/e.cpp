#include <bits/stdc++.h>
using namespace std;
int n;
int dat[1005];
typedef pair<int, int> P;
int find(int x){
    int l = 0, r = n - 1;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(dat[mid] == x){
            return mid;
        } else if(dat[mid] > x){
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return -1;
}
int main(){
    cin >> n;
    for (int i = 0; i < n;i++){
        cin >> dat[i];
    }
    sort(dat, dat + n);
    set<string> mark;
    set< pair<int, pair<int, int>> > se;
    for (int i = 0; i < n;i++){
        for (int j = i + 1; j < n;j++){
            int x = 0 - dat[i] - dat[j];
            int fa = find(x);
            if(fa != -1 && fa != i && fa != j){
                // string sum = to_string(i) + to_string(j) + to_string(find(x));
                // if(mark.count(sum)){
                //     continue;
                // }
                // mark.insert(sum);
                int a[4] = {x, dat[i], dat[j]};
                sort(a, a + 3);
                se.insert(make_pair(a[0], make_pair(a[1], a[2])));
            }
        }
    }
    if(se.empty()){
        cout << "No Solution" << '\n';
    } else {
        for (auto i = se.begin(); i != se.end();i++){
            P tt = (*i).second;
            cout << (*i).first << ' ' << tt.first << ' ' << tt.second << '\n';
        }
    }
    return 0;
}