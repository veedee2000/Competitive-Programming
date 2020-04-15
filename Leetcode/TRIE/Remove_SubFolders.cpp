class Solution {
    
    struct trie{
        bool endOfFile;
        unordered_map<string,trie*>child;
        trie(){
            endOfFile = 0;
        }
    };
    
    void insert(trie* root,string s){
        int i = 0;
        while(i < s.size()){
            i++;
            string file = "";
            while(i < s.size() and s[i] != '/') file.push_back(s[i++]);
            if(!root -> child.count(file)) root -> child[file] = new trie();
            root = root -> child[file];
        }
        root -> endOfFile = 1;
    }
    
    bool search(trie* root,string s){
        int i = 0;
        while(i < s.size()){
            i++;
            string file = "";
            while(i < s.size() and s[i] != '/') file.push_back(s[i++]);
            root = root -> child[file];
            if(root -> endOfFile and i < s.size()) return 0;
        }
        return 1;
    }
    
    vector<string>ans;
    
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        trie* root = new trie();
        for(auto x:folder) insert(root,x);
        for(auto x:folder){
            if(search(root,x)) ans.push_back(x);
        }
        return ans;
    }
};
