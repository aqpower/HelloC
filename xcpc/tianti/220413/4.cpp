#include <bits/stdc++.h>
using namespace std;
char dic[13][8] = {{'0',' '},"1,.?!","2ABC","3DEF","4GHI","5JKL","6MNO","7PQRS","8TUV","9WXYZ"};
int num[13] = {2,5, 4, 4, 4, 4, 4, 5, 4, 5};
int main(){
    string s;
    while(cin >> s){
        int now = s[0] - '0';
        cout << dic[now][(s.size() - 1) % num[now]];
    }
    return 0;
}