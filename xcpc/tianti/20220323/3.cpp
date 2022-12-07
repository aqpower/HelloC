#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int dat[1000005];
int main(){
    int n, k;
    queue<int> q;
    vector<int> min, max;
    cin >> n >> k;
    for (int i = 0; i < n;i++){
        cin >> dat[i];
    }
    for (int i = 0; i + k - 1 < n;i++){
        vector<int> t;
        for (int j = i; j <= i + k - 1;j++){
            t.push_back(dat[j]);
        }
        sort(t.begin(), t.end());
        max.push_back(*(t.end() - 1));
        min.push_back(*(t.begin()));
    }

        for (int i = 0; i < min.size(); i++)
        {
            cout << min[i];
            if (i != min.size() - 1)
            {
                cout << ' ';
            }
        }
    cout << '\n';
    for (int i = 0; i < max.size();i++){
        cout << max[i];
        if(i != max.size() - 1){
            cout << ' ';
        }
    }

    return 0;
}