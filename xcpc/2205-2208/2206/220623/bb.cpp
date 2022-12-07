#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        int a = 0;
        cin >> s;
        while (s[s.size() - 1] !='5' && s[s.size()-1]!='0'){
            s.erase(s.end() - 1);
            a++;
        }
        cout << s << '\n';
        while(!s.empty()){
            if(s.back() == '0'){
                if (s[s.size() - 2] !='5' && s[s.size()-2]!='0'){
                s.erase(s.end() - 2);
                a++;
                cout << s << '\n';
                }
            } else {
                if (s.size() > 2 && s[s.size() - 2] !='2' && s[s.size()-2]!='7'){
                s.erase(s.end() - 2);
                a++;
                cout << s << '\n';
                }
            }
        }
        cout << a << '\n';
    }
    return 0;
}