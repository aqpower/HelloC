#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    int num = 0;
    for (int i = 2; i < s.size();i++){
        if(s[i] == 'U' && s[i-1] == 'P' && s[i-2] == 'H'){
            num++;
        }
    }
    cout << num << '\n';
    return 0;
}