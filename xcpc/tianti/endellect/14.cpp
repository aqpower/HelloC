#include <bits/stdc++.h>
using namespace std;
struct node{
    int val;
    int lawer;
    node *l, *r;
};
node* newnode(int val){
    node *a = new node;
    a->val = val;
    a->l = a->r = NULL;                                                                                                   
    return a;
}
void insert(int val,node* &root){
    if(root == NULL){
        root = newnode(val);
        return;
    }
    if(val >= root->val){                      
        insert(val, root->l);
    } else {
        insert(val, root->r);
    }
}
vector<int> law(node* root){
    vector<int> a;
    queue<node *> q;
    q.push(root);
    while(!q.empty()){
        node* top = q.front();
        q.pop();
        a.push_back(top->val);
        if(top->l){
            q.push(top->l);
        }
        if(top->r){
            q.push(top->r);
        }
    }
    return a;
}
int main(){
    int n, t;
    node* root = NULL;
    cin >> n;
    for (int i = 0; i < n;i++){
        cin >> t;
        insert(t, root);
    }
    vector<int> ans = law(root);
    for (int i = 0; i < ans.size();i++){
        cout << ans[i];
        if(i!=ans.size() - 1){
            cout << ' ';
        }
    }
    cout << '\n';
    cout << "YES";
    return 0;
}