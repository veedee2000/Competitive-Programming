struct trie{
    struct trie* child[26];
    bool endOfWord;
};

struct trie* getNode(){
    struct trie* root = new trie;
    for(int i = 0;i < 26;i++) root -> child[i] = NULL;
    root -> endOfWord = 0;
    return root;
}

void construct(struct trie* root,string word){
    for(auto x:word){
        int index = x - 'a';
        if(!root -> child[index]) root -> child[index] = getNode();
        root = root -> child[index];
    }
    root -> endOfWord = 1;
}

bool find_match(struct trie* root,string word,int i,int val){
    if(!root) return 0;
    if(val > 1) return 0;
    if(i == word.size()) return ((val == 1) and (root -> endOfWord));
    bool ans = 0;
    for(int index = 0;index < 26;index++){
        if(word[i] - 'a' == index) ans |= find_match(root -> child[index],word,i + 1,val);
        else ans |= find_match(root -> child[index],word,i + 1,val + 1);
    }
    return ans;
}

class MagicDictionary {
public:
    struct trie* root;
    /** Initialize your data structure here. */
    MagicDictionary() {
        root = getNode();
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for(auto word:dict) construct(root,word);
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        return find_match(root,word,0,0);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dict);
 * bool param_2 = obj->search(word);
 */
