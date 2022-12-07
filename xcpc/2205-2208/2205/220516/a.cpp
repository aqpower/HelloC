#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    if(s[0] == '-'){
        cout << "fu ";
        s.erase(s.begin());
    }
    for (int i = 0; i < s.size();i++){
        switch (s[i])
        {
        case '0'/* constant-expression */:
            /* code */
            cout << "ling";
            break;
        case '1'/* constant-expression */:
            /* code */
            cout << "yi";
            break;
        case '2'/* constant-expression */:
            /* code */
            cout << "er";
            break;
        case '3'/* constant-expression */:
            /* code */
            cout << "san";
            break;
        case '4'/* constant-expression */:
            /* code */
            cout << "si";
            break;
        case '5'/* constant-expression */:
            /* code */
            cout << "wu";
            break;
        case '6'/* constant-expression */:
            /* code */
            cout << "liu";
            break;
        case '7'/* constant-expression */:
            /* code */
            cout << "qi";
            break;
        case '8'/* constant-expression */:
            /* code */
            cout << "ba";
            break;
        case '9'/* constant-expression */:
            /* code */
            cout << "jiu";
            break;
        }
        if(i != s.size() - 1){
            cout << ' ';
        }
    }
    return 0;
}