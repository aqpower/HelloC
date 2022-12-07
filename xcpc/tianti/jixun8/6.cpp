#include <bits/stdc++.h>
using namespace std;
bool findnum(string a){
    for (int i = 0; i < a.size();i++){
        if(isdigit(a[i])){
            return true;
        }
    }
    return false;
}
int main(){
    bool fa = false;
    bool fb = false;
    string a, b;
    cin >> a >> b;
    int da = -1, db = -1;
    if(findnum(a)){
         da = stoi(a);
    }
    if(findnum(b)){
         db = stoi(b);
    }
    string dda = to_string(da);
    string ddb = to_string(db);
    if(da > 0 && dda.size() == a.size()){
        fa = true;
    }
    if(db > 0 && ddb.size() == b.size()){
        fb = true;
    }
    if(fa){
        cout << da;
    } else {
        cout << '?';
    }
    cout << " + ";
    if(fb){
        cout << db;
    } else {
        cout << '?';
    }
    cout << " = ";
    if(fa&&fb){
        cout << da + db;
    } else {
        cout << '?';
    }
    return 0;
}