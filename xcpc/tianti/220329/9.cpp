#include <bits/stdc++.h>
using namespace std;

int main(){
    stack<int> s1;
    stack<char> s2;
    int n;
    int  t;
    char c;
    cin >> n;
    while(n--){
        cin >> t;
        s1.push(t);
    }
    getchar();
    string s;
    getline(cin, s);
    for (int i = 0; i < s.size();i++){
        if(s[i]!=' '){
            s2.push(s[i]);
        }
    }
    int n1, n2;
    int now = 0;
    while(!s2.empty()){
        n1 = s1.top();
        s1.pop();
        n2 = s1.top();
        s1.pop();
        c = s2.top();
        s2.pop();
        if(c == '+'){
            t = n2 + n1;
        } else if(c == '-'){
            t = n2 - n1;
        } else if(c == '*'){
            t = n2 * n1;
        } else {
            if(n1 == 0){
                cout << "ERROR: " << n2 << "/0";
                return 0;
            }
            t = n2 / n1;
        }
        now = t;
        s1.push(t);
    }
    cout << now;

    return 0;
}