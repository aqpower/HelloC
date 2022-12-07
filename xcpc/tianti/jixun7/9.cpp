#include <bits/stdc++.h>
using namespace std;
struct Treenode{
    int val,lawer;
    Treenode *left, *right;
};
Treenode* newnode(){
    Treenode *a = new Treenode;
    a->left = a->right = NULL;
    return a;
}
int maxl = -1;
void insert(int val,Treenode* &root, int law){
    if(!root){
        if(law > maxl){
            maxl = law;
        }
        root = newnode();
        root->val = val;
        root->lawer = law;
        return;
    }
    if(val > root->val){
        insert(val, root->right, law + 1);
    }
    else {
        insert(val, root->left, law + 1);
    }
}
int ans = 0;
void find(Treenode* root){
    if(!root){
        return;
    }
    if(root->lawer == maxl || root->lawer == maxl - 1){
        ans++;
    }
    find(root->left);
    find(root->right);
}
int main(){
    int n, t;
    Treenode *root = NULL;
    cin >> n;
    for (int i = 0; i < n;i++){
        cin >> t;
        insert(t, root, 1);
    }
    find(root);
    cout << ans;

    return 0;
}