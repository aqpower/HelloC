#include <bits/stdc++.h>
using namespace std;

int main(){
    int nt;
    cin >> nt;
    getchar();
    string s, c;
    while(nt--){
        getline(cin, s);
        getline(cin, c);
        bool flag = false;
        if(s.find(c) != string::npos){
            int now = 0, l, r;
            int a[5];
            while(s.find(c, now)!= string::npos){
                now = s.find(c, now);
                l = now;
                r = s.size() - now - 1;
                now++;
                if(l % 2 == 0 && r % 2 == 0){
                    flag = true;
                    break;
                }
            }
        }
        if(flag){
            cout << "YES";
        } else {
            cout << "NO";
        }
        cout << '\n';
    }

    return 0;
}


// #include "iostream"
// #include "algorithm"
// #include "string"

// std::string s;
// char ch;
// int n;

// int main()
// {
// 	std::cin >> n;
// 	while (n--) {
// 		std::cin >> s >> ch;
// 		bool flag = false;
// 		for (int i = 0; i < s.size(); i++) {
// 			if (ch == s[i]) {
// 				if (i % 2 == 0) flag = true;
// 			}
// 		}
// 		if (flag) std::cout << "Yes" << std::endl;
// 		else std::cout << "No" << std::endl;
// 	}


// 	return 0;
// }
