class Solution {
    
    struct trie{
        trie* child[26];
        bool endOfWord;
    };
    
    trie* getNode(){
        trie* root = new trie;
        for(int i = 0;i < 26;i++) root -> child[i] = NULL;
        root -> endOfWord = 0;
        return root;
    }
    
    void insert(trie* root,string s){
        for(auto x:s){
            if(!root -> child[x - 'a']) root -> child[x - 'a'] = getNode();
            root = root -> child[x - 'a'];
        }
        root -> endOfWord = 1;
    }
    
public:
    
    bool wordBreak(string s, vector<string>& wordDict) {
        trie* root = getNode();
        for(auto word:wordDict) insert(root,word);
        trie* rootSub = root -> child[s[0] - 'a'];
        if(!rootSub) return 0;
        return f(root,rootSub,s);
    }
    
    bool f(trie* original,trie* root,string s){
        if(!root) return 0;
        if(s.size() == 1 and root -> endOfWord) return 1;
        if(s.size() == 1) return 0;
        s.erase(0,1);
        if(root -> endOfWord){
            return f(original,original -> child[s[0] - 'a'],s) or f(original,root -> child[s[0] - 'a'],s);
        }
        return f(original,root -> child[s[0] - 'a'],s);
    }
};
