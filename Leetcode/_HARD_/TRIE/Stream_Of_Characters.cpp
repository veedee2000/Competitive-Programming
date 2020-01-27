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

void construct(struct trie* root,string& word){
    reverse(word.begin(),word.end());
    for(auto x:word){
        int index = x - 'a';
        if(!root -> child[index]) root -> child[index] = getNode();
        root = root -> child[index];
    }
    root -> endOfWord = 1;
}

bool search(struct trie* root,string& s){
    for(auto x:s){
        if(!root -> child[x - 'a']) return 0;
        root = root -> child[x - 'a'];
        if(root -> endOfWord) return 1;
    }
    return 0;
}

class StreamChecker {
public:
    struct trie* root;
    string s;
    StreamChecker(vector<string>& words) {
        s = "";
        root = getNode();
        for(auto word:words) construct(root,word);
    }
    
    bool query(char letter) {
        s.insert(0, 1, letter);
        return search(root,s);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
