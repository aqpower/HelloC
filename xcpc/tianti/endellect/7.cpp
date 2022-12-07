#include <bits/stdc++.h>
using namespace std;

int main(){
    string a;
    set<int> se;
    vector<int> arr;
    vector<int> ind;
    cin >> a;
    for (int i = 0; i < a.size();i++){
        int t = a[i] - '0';
        se.insert(t);
    }
    for (auto i =se.begin(); i != se.end();i++){
        arr.push_back(*i);
    }
    reverse(arr.begin(), arr.end());
    for (int i = 0; i < a.size(); i++)
    {
        int t = a[i] - '0';
        int ans = find(arr.begin(), arr.end(), t) - arr.begin();
        ind.push_back(ans);
    }
    cout << "int[] arr = new int[]{";
    for (int i = 0; i < arr.size();i++){
        cout << arr[i];
        if(i!=arr.size() - 1){
            cout << ',';
        }
    }
    cout << "};" << '\n';
    cout << "int[] index = new int[]{";
    for (int i = 0; i < ind.size();i++){
        cout << ind[i];
        if(i!=ind.size() - 1){
            cout << ',';
        }
    }
    cout << "};" << '\n';

    return 0;
}