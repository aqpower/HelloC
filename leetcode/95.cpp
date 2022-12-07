#include <bits/stdc++.h>
using namespace std;
 //Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
class Solution {
public:
    TreeNode* newCode(int x){
        TreeNode *now = new TreeNode;
        now->val = x;
        now->left = now->right = NULL;
        return now;
    }
    void insert(TreeNode* &root,int x){
        if(!root){
            root = newCode(x);
            return;
        }
        if(x > root->val){
            insert(root->right, x);
        }
        else {
            insert(root->left, x);
        }
    }
    void lawer(TreeNode*root,vector<TreeNode*> &v){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *top = q.front();
            q.pop();
            v.push_back(top);
            if(!top){
                continue;
            }
            q.push(top->left);
            q.push(top->right);
        }
    }
    vector<TreeNode*> generateTrees(int n) {
        int a[n + 10];
        for (int i = 0; i < n;i++){
            a[i] = i + 1;
        }
        int j = 0;
        do{
            vector<TreeNode*> v;
            TreeNode *root = NULL;
            for (int i = 0; i < n;i++){
                insert(root, a[i]);
            }
            lawer(root, v);
            for (int i = 0; i < v.size();i++){
                if(v[i])
                cout << v[i]->val << ' ';
            }
            cout << '\n';
            
        } while (next_permutation(a, a + n));
            vector<TreeNode*> v;
        return v;
    }
};

int main(){
    Solution s;
    s.generateTrees(3);
    
    return 0;
}