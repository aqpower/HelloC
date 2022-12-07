#include <bits/stdc++.h>
using namespace std;

int main(){
    string a, b;
    getline(cin, a);
    getline(cin, b);
    while(a.find(b) != string::npos){
        a.erase(a.find(b), b.size());
    }
    cout << a;
    return 0;
}