#include <bits/stdc++.h>
using namespace std;

int main(){
    map<string, int> da;
    int n, m, cnt;
    string tn;
    cin >> n >> m;
    getchar();
    for (int i = 0; i < n;i++){
        getline(cin, tn);
        cnt= count(tn.begin(), tn.end(), ' ');
        string t = tn.erase(0, cnt);
        da[t] = cnt;
    }
    string quiz;
    while(m--){
        getline(cin, quiz);
        string pre = quiz.substr(0,quiz.find("is") - 1);
        string ne = quiz.substr(quiz.find("of") + 3, quiz.size() - 1);
        if(quiz.find("child")!=string::npos){
            if(da[pre] - da[ne] == 2){
                cout << "True";
            } else {
                cout << "False";
            }
        } else if(quiz.find("parent")!=string::npos){
            if(da[pre] - da[ne] == -2){
                cout << "True";
            } else {
                cout << "False";
            }
        } else if(quiz.find("sibling")!=string::npos){
            if(da[pre] - da[ne] == 0){
                cout << "True";
            } else {
                cout << "False";
            }
        } else if(quiz.find("descendant")!=string::npos){
            if(da[pre] - da[ne] > 0){
                cout << "True";
            } else {
                cout << "False";
            }
        } else if(quiz.find("ancestor")!=string::npos){
            if(da[pre] - da[ne] < 0){
                cout << "True";
            } else {
                cout << "False";
            }
        }
        cout << '\n';
    }

    return 0;
}