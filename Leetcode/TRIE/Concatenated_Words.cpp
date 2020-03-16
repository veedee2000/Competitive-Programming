class Solution {
    vector<string>ans;
    
    struct trie{
        struct trie* child[26];
        bool endOfWord;
    };
    
    struct trie* getNode(){
        struct trie* root = new trie();
        for(int i = 0;i < 26;i++) root -> child[i] = NULL;
        root -> endOfWord = 0;
        return root;
    }
    
    void insert(struct trie* root,string word){
        for(auto x:word){
            int index = x - 'a';
            if(!root -> child[index]) root -> child[index] = getNode();
            root = root -> child[index];
        }
        root -> endOfWord = 1;
    }
    
    bool check(struct trie* root,string word){
        for(auto x:word){
            int index = x - 'a';
            if(!root -> child[index]) return 0;
            root = root -> child[index];
        }
        return root -> endOfWord;
    }
    
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        struct trie* root = getNode();
        for(auto word : words) insert(root,word);
        for(auto word : words) if(valid(root,word)) ans.push_back(word);
        return ans;
    }
    
    bool valid(struct trie* root,string word){
        if(word.size() <= 1 and !check(root,word)) return 0;
        int sz = word.size() - 1;
        string l = "", r = "";
            l += word[i];
            r = word.substr(i+1);
            if(check(root, l) && (check(root, r) || valid(root, r))) {
                return 1;
            }
        }
        return 0;
    }
    
};
