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
    vector<string>ans;
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        trie* root = getNode();
        for(auto word:wordDict) insert(root,word);
        trie* rootSub = root -> child[s[0] - 'a'];
        if(!rootSub) return ans;
        string path;
        path.push_back(s[0]);
        f(root,rootSub,s,path);
        return ans;
    }
    
    void f(trie* original,trie* root,string s,string path){
        if(!root){
            return;
        }
        if(s.size() == 1 and root -> endOfWord){
            ans.push_back(path);
            return;
        }
        if(s.size() == 1){
            return;
        }
        s.erase(0,1);
        if(root -> endOfWord){
            string path1 = path;
            path1.push_back(' ');
            path1.push_back(s[0]);
            string path2 = path;
            path2.push_back(s[0]);
            f(original,original -> child[s[0] - 'a'],s,path1);
            f(original,root -> child[s[0] - 'a'],s,path2);
            return;
        }
        path.push_back(s[0]);
        f(original,root -> child[s[0] - 'a'],s,path);
    }
};
