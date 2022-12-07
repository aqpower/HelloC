#include <bits/stdc++.h>
using namespace std;
const int maxn = 15;
int n, l, t, a[maxn];
struct node{
    int date;
    node *lchild, *rchild;
} Node[maxn];
node* newCode(int x){
    node *now = new node;
    now->date = x;
    now->lchild = NULL,
    now->rchild = NULL;
    return now;
}
void insert(node* &root, int x){
    if(root == NULL){
        root = newCode(x);
        return;
    }
    if(x == root->date){
        return;
    } else if(x > root->date){
        insert(root->rchild, x);
    } else {
        insert(root->lchild, x);
    }
}
vector<int> lawer(node *root){
    vector<int> v;
    queue<node *> q;
    q.push(root);
    while(!q.empty()){
        node *top = q.front();
        q.pop();
        v.push_back(top->date);
        if(top->lchild){
            q.push(top->lchild);
        }
        if(top->rchild){
            q.push(top->rchild);
        }
    }
    return v;
}
node*Create(){
    node *root = NULL;
    
    for (int i = 0; i < n;i++){
        cin >> t;
        insert(root, t);
    }
    return root;
}
int main(){
    while(cin >> n && n){
        cin >> l;
        node* re = Create();
        vector<int> ans = lawer(re);
        while(l--){
            node *ret = Create();
            vector<int> ant = lawer(ret);
            cout <<( ant == ans ? "Yes" : "No") << '\n';
        }
    }
    return 0;
}