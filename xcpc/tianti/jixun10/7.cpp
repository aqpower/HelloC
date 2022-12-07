#include <bits/stdc++.h>
using namespace std;
bool unifun(char a, char b){
    return (a == b) && (b == ' ');
}
int main(){
    int n;
    cin >> n;
    getchar();
    string s;
    while(n--){
        getline(cin, s);
        cout << s << '\n';
        cout << "AI: ";
        // unique(s.begin(), s.end(), unifun);
        // s.erase(unique(s.begin(), s.end(), unifun), s.end());
        for (int i = 0; i < s.size();i++){
            if (s[i] == ' '){
                if(i != s.size() - 1){
                    int now = i + 1;
                    while(now < s.size() && s[now] == ' '){
                        s.erase(now, 1);
                    }
                } 
            }
        }
            while (*s.begin() == ' ')
            {
                s.erase(s.begin());
            }
        while(*(s.end() - 1) == ' '){
            s.erase(s.end() - 1);
        }
        for(int i = 0; i < s.size();i++){
            if(s[i]>='A' && s[i] <= 'Z'){
                if(s[i]!='I'){
                    s[i] += 32;
                }
            }
        }
        int inf;
        while(inf = s.find(" can you"), inf != string::npos){
            s.insert(inf, " I can");
            s.erase(inf + 6, 8);
        }
        while(inf = s.find(" could you"), inf != string::npos){
            s.insert(inf, " I could");
            s.erase(inf + 8, 10);
        }
        while(inf = s.find(" I"), inf != string::npos){
            s.insert(inf, " you");
            s.erase(inf + 4, 2);
        }
        while(inf = s.find(" me"), inf != string::npos){
            s.insert(inf, " you");
            s.erase(inf + 4, 3);
        }
        while(inf = s.find("?"), inf != string::npos){
            s.insert(inf, "!");
            s.erase(inf + 1, 1);
        }
        cout << s;
        cout << '\n';
    }

    return 0;
}