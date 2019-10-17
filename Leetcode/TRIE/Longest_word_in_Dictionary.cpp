class Solution {
public:
    
    struct Trie{
        struct Trie *child[26];
        bool end_of_word;
    };
    
    struct Trie* getnode(void){
        struct Trie* node = new Trie;
        node -> end_of_word = false;
        for(int i=0;i<26;i++){
            node -> child[i] = NULL;
        }
        return node;
    } 
    
    bool insert(struct Trie* root, string word){
        int count = 0;
        for(int i = 0;i < word.size();i++){
            
            int index = word[i] - 'a';
            if(!root -> end_of_word) ++count;
            
            if(!root -> child[index]){
                root -> child[index] = getnode();
            }
            root = root -> child[index];
        }
        root -> end_of_word = true;
        
        if(count == 1) return true;
        else return false;
    }
    
    string longestWord(vector<string>& words) {
        int n = words.size();
        sort(words.begin(),words.end());
        if(n == 1) return words[0];
        if(n == 0) return 0;
        struct Trie* root =  getnode();
        string ans = "";
        
        for(auto x:words){
            bool valid = insert(root, x);
            if(valid){
                if(x.size() > ans.size()){
                    ans = x;
                }
            }
        }
        return ans;
    }
};
