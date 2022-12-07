#include <iostream>
#include <queue>
using namespace std;
typedef int TreeType;
const int maxn = 1e5 + 5;
int n, pre[maxn], in[maxn], post[maxn];
struct tree{
    TreeType date;
    int layer;
    tree *lchild, *rchild;
};
void inorder(tree* root){
	if(!root){
		return;
	}
	inorder(root->lchild);
	cout << root->date;
	inorder(root->rchild);
}
void layerOrder(tree *T){
    queue<tree*> q;
    T->layer = 1;
    q.push(T);
    while(!q.empty()){
        tree* top = q.front();
        q.pop();
        cout << top->date; 
        if(top->lchild){
            top->lchild->layer = top->layer + 1;
            q.push(top->lchild);
        }
        if(top->rchild){
            top->rchild->layer = top->layer + 1;
            q.push(top->rchild);
        }
    }
}
tree* Create(int preL, int preR, int inL, int inR){
    if(preL > preR){
        return NULL;
    }
    tree *root = new tree;
    root->date = pre[preL];
    int k;
    for (k = inL; k <= inR; k++){
        if(in[k] == pre[preL]){
            break;
        }
    }
    int numleft = k - inL;
    root->lchild = Create(preL + 1, preL + numleft, inL, k - 1);
    root->rchild = Create(preL + numleft + 1, preR, k + 1, inR);
    return root;
}

tree* inCreate(int postL, int postR, int inL, int inR){
	if(postL > postR){
		return NULL;
	}
	int k;
	for(k = inL; k <= inR; k++){
		if(in[k] == post[postR]){
			break;
		}
	}
	int numleft = k - inL;
	tree* root = new tree;
	root->date = in[k];
	root->lchild = inCreate(postL, postL + numleft - 1, inL, k - 1);
	root->rchild = inCreate(postL + numleft, postR - 1, k + 1, inR);
	return root;
}
void layer(tree* root){
	queue<tree*> q;
	q.push(root);
	while(!q.empty()){
		tree* top = q.front();
		q.pop();
		cout << top->date << ' ';
		if(top->lchild){
			q.push(top->lchild);
		}
		if(top->rchild){
			q.push(top->rchild);
		} 
	}
}
int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> post[i];
	}
	for(int i = 0; i < n; i++){
		cin >> in[i];
	}
	layer(inCreate(0, n - 1, 0, n - 1));
	
	return 0;
}