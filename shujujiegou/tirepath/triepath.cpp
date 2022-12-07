#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
struct Node{
    int weight;
    vector<int> child;
}Node[maxn];
bool cmp(int a, int b){
    return Node[a].weight > Node[b].weight;
}
int n, m, s;
vector<int> ans;
void DFS(int index,int sum){
    if(sum > s){
        return;
    }
    if(sum == s){
        if(Node[index].child.size() == 0){
            for (int i = 0; i < ans.size(); i++){
                cout << ans[i];
                if(i < ans.size() - 1){
                    cout << ' ';
                }
                else{
                    cout << '\n';
                }
            }
        }
        else{
            return;
        }
    }
    for (int i = 0; i < Node[index].child.size(); i++){
        int next = Node[index].child[i];
        ans.push_back(Node[next].weight);
        DFS(next, sum + Node[next].weight);
        ans.pop_back();
    }
}
int main(){
    cin >> n >> m >> s;
    for (int i = 0; i < n; i++){
        cin >> Node[i].weight;
        Node[i].child.clear();
    }
    int now, k, t;
    for (int i = 0; i < m; i++){
        cin >> now >> k;
        for (int j = 0; j < k; j++){
            cin >> t;
            Node[now].child.push_back(t);
        }
        sort(Node[now].child.begin(), Node[now].child.end(), cmp);
    }
    ans.push_back(Node[0].weight);
    DFS(0, Node[0].weight);

    return 0;
}