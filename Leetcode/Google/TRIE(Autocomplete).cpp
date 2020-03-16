#include <bits/stdc++.h>
using namespace std;

vector<string>ans;

struct trie{
	trie* child[26];
	bool endOfWord;
};

trie* getNode(){
	struct trie* root = new trie;
	for(int i = 0;i < 26;i++) root -> child[i] = NULL;
	root -> endOfWord = 0;
	return root;
}

void insert(string word,trie* root){
	for(auto x:word){
		if(!root -> child[x - 'a']) root -> child[x - 'a'] = getNode();
		root = root -> child[x - 'a'];
	}
	root -> endOfWord = 1;
}

void findWords(trie* root,string now){
	if(!root) return;
	for(int i = 0;i < 26;i++){
		now.push_back('a' + i);
		findWords(root -> child[i],now);
		now.pop_back();
	}
	if(root -> endOfWord){
		ans.push_back(now);
	}
}

void traverse(string autoComplete,trie* root){
	for(auto x:autoComplete){
		if(!root -> child[x - 'a']) return;
		root = root -> child[x - 'a'];
	}
	findWords(root,"");
	if(ans.size()) for(auto &x:ans) x = autoComplete + x;
}



int main() {
	
	int n;
	cin>>n;
	vector<string>words(n);
	trie* root = getNode();
	for(int i = 0;i < n;i++) cin>>words[i],insert(words[i],root);
	string autoComplete;
	cin>>autoComplete;
	traverse(autoComplete,root);
	for(auto x:ans) cout<<x<<" ";
	
	return 0;
}
