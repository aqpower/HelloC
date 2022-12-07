#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    getchar();
    list<string> st;
    while(t--){
        string s;
        getline(cin, s);
        // reverse(s.begin(), s.end());
        st.push_back(s);
    }
    while(!st.empty()){
        string top = st.front();
        st.pop_front();
        cout << top << ' ';
    }
    
    return 0;
}