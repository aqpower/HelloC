#include <bits/stdc++.h>
using namespace std;
const int maxn = 55;
int n, pre[maxn], mid[maxn];
priority_queue<int,vector<int>, greater<int>> plawer;

void Treebirth(int prel, int prer, int midl, int midr, int lawer){
    plawer.push(lawer);
    if(prel == prer){
        return;
    }
    int root = pre[prel];
    int j;
    for (j = midl; j <= midr;j++){
        if(mid[j] == root){
            break;
        }
    }
    int numl = j - midl;
    Treebirth(prel + 1, prel + numl, midl, j - 1, lawer + 1);
    Treebirth(prel + numl + 1, prer, j + 1, midr, lawer + 1);
}

int main()
{
    cin >> n;
    for (int i = 0;i<n;i++){
        cin >> pre[i];
    }
    for (int i = 0;i<n;i++){
        cin >> mid[i];
    }
    Treebirth(0, n - 1, 0, n - 1, 1);
    cout << plawer.top();

    return 0;
}