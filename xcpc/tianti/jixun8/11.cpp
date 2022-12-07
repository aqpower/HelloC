#include <bits/stdc++.h>
using namespace std;
typedef pair<int, string> P;
bool dic[10005] = {false};
vector<string> de, mynew;
map<string, P> d;
void solve(string add){
    if(add == "-1"){
        return;
    }
    int v = d[add].first;
    v = abs(v);
    if(!dic[v]){
        dic[v] = true;
        mynew.push_back(add);
    } else {
        de.push_back(add);
    }
    solve(d[add].second);
}
int main(){
    string fir;
    int n;
    cin >> fir >> n;
    string add, next;
    int val;
    for (int i = 0; i < n;i++){
        cin >> add >> val >> next;
        d[add] = P(val, next);
    }
    solve(fir);
    string pre;
    for (int i = 0; i < mynew.size();i++){
        string now = mynew[i];
        if(i < mynew.size()-1){
            next = mynew[i + 1];
        } else {
            next = "-1";
        }
        cout << now << ' ' << d[now].first << ' ' << next << '\n';
    }
    for (int i = 0; i < de.size();i++){
        string now = de[i];
        if(i < de.size()-1){
            next = de[i + 1];
        } else {
            next = "-1";
        }
        cout << now << ' ' << d[now].first << ' ' << next << '\n';
    }
    

    return 0;
}