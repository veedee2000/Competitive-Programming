#include <bits/stdc++.h>
using namespace std;

vector<int>inorder;

struct TreeNode{
	int val;
	TreeNode* left,*right;
	TreeNode(int v=0){
		val = v;
		left = NULL;
		right = NULL;
	}
};

TreeNode* f(int inStart,int inEnd,vector<int>levelorder){
	if(inStart > inEnd) return NULL;
	TreeNode* root = new TreeNode(levelorder[0]);
	if(inStart == inEnd) return root;
	int indexIn;
	for(int i = inStart;i <= inEnd;i++){
		if(levelorder[0] == inorder[i]) {indexIn = i; break;}
	}
	int indexLeft = -1;
	for(int i = inStart;i < indexIn;i++){
		if(levelorder[1] == inorder[i]){ indexLeft = i; break; }
	}
	if(indexLeft != -1){
		vector<int>left;
		unordered_set<int>s;
		for(int i = inStart;i < indexIn;i++) s.insert(inorder[i]);
		for(int i = 0;i < levelorder.size();i++) if(s.count(levelorder[i])) left.push_back(levelorder[i]);
		root -> left = f(inStart,indexIn - 1,left);
		s.clear();
		int indexRight = -1;
		for(int i = indexIn + 1;i <= inEnd;i++){
			if(levelorder[2] == inorder[i]){ indexRight = i; break; }
		}
		if(indexRight != -1){
			vector<int>right;
			for(int i = indexIn + 1;i <= inEnd;i++) s.insert(inorder[i]);
			for(int i = 0;i < levelorder.size();i++) if(s.count(levelorder[i])) right.push_back(levelorder[i]);
			root -> right = f(indexIn + 1,inEnd,right);
		}
	}
	else{
		vector<int>right;
		unordered_set<int>s;
		for(int i = inStart;i < indexIn;i++) s.insert(inorder[i]);
		for(int i = 0;i < levelorder.size();i++) if(s.count(levelorder[i])) right.push_back(levelorder[i]);
		root -> left = f(inStart,indexIn - 1,right);
	}
	return root;
}

void p(TreeNode* root){
	if(!root) return;
	p(root -> left);
	cout<<root -> val<<" ";
	p(root -> right);
}

int main() {
	
	int n;
	cin>>n;
	inorder.resize(n);
	vector<int>levelorder(n);
	for(int i = 0 ;i < n;i++) cin>>inorder[i];
	for(int i = 0 ;i < n;i++) cin>>levelorder[i];
	
	TreeNode* root = f(0,n - 1,levelorder);
	p(root);
	
	return 0;
}
