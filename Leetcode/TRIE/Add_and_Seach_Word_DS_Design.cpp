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

bool searchWord(struct trie* root,string word,int i){
    if(!root) return 0;
    if(i == word.size()) return (root -> endOfWord);
    if(word[i] == '.'){
        bool ans = 0;
        for(int x = 0;x < 26;x++) ans |= searchWord(root -> child[x],word,i + 1);
        return ans;
    }
    else return searchWord(root -> child[word[i] - 'a'],word,i + 1);
}

class WordDictionary {
public:
    /** Initialize your data structure here. */
    struct trie* root;
    WordDictionary() {
        root = getNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        construct(root,word);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return searchWord(root,word,0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
