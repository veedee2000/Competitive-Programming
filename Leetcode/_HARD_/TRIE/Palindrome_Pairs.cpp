class Solution{

private: 
    struct trie{
        int index;
        trie* child[26];

        trie(){
            index = -1;
            for(int i = 0;i < 26;i++) child[i] = NULL;
        }
    };

public: 
    
    vector<vector<int>> palindromePairs(vector<string>& wordList){

        vector<vector<int>>pairs;
        vector<int>sizes;
        for(auto word:wordList) sizes.push_back(word.size());

        trie* root = new trie(); 
        vector<vector<bool>>palindrome(wordList.size()), palindromeFront(wordList.size());

        for(int i = 0;i < wordList.size();i++){
            palindrome[i].resize(wordList[i].size() + 1,0);
            palindromeFront[i].resize(wordList[i].size() + 1,0);
            frontPalin(wordList[i],i,palindromeFront);
            string rev = wordList[i];
            reverse(rev.begin(),rev.end());
            insert(rev,i,root,palindrome);
        }

        trie* node;

        for(int i = 0;i < wordList.size();i++){

            node = root;

            for(int j = 0;j < wordList[i].size();j++){
                if(!node) break;
                if(node -> index != -1 and node -> index != i){
                    if(palindrome[i][j]){
                        pairs.push_back({i,node -> index});
                    }
                }
                node = node -> child[wordList[i][j] - 'a'];
            }
            dfs(node,i,-1,pairs,palindromeFront);
        }

        return pairs;

    }
    
    void frontPalin(string& s,int index,vector<vector<bool>>& palindromeFront){
        for(int i = 0;i < s.size();i++){
            int l = 0,r = i;
            bool yes = 1;
            while(l < r) if(s[l++] != s[r--]) { yes = 0; break; }
            palindromeFront[index][i] = yes;
        }
    }

    void dfs(trie* root,int index,int sz,vector<vector<int>>& pairs,vector<vector<bool>>& palindromeFront){
        if(!root) return;
        if(root -> index != -1 and root -> index != index){
            if(sz == -1 or palindromeFront[root -> index][sz]) pairs.push_back({index,root -> index});
        }
        for(int i = 0;i < 26;i++){
            dfs(root -> child[i],index,sz + 1,pairs,palindromeFront);
        }
    }

    bool isPalindrome(string& s){
        int l = 0,r = s.size() - 1;
        while(l < r){
            if(s[l++] != s[r--]) return 0;
        }
        return 1;
    }

    void insert(string s,int index,trie* root,vector<vector<bool>>& palindrome){
        string now = "";
        for(int i = 0;i < s.size();i++){
            now.push_back(s[i]);
            palindrome[index][s.size() - 1 - i] = isPalindrome(now);
            if(!root -> child[s[i] - 'a']) root -> child[s[i] - 'a'] = new trie();
            root = root -> child[s[i] - 'a'];
        }
        root -> index = index;
    }

};
