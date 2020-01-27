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
    for(auto letter:word){
        int index = letter - 'a';
        if(!root -> child[index]) root -> child[index] = getNode();
        root = root -> child[index];
    }
    root -> endOfWord = 1;
}

string search(struct trie* root,string word){
    string ret = "";
    for(auto x:word){
        int index = x - 'a';
        if(root -> endOfWord) return ret;
        if(!root -> child[index]) return word;
        ret += x;
        root = root -> child[index];
    }
    return word;
}

class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        struct trie* root = getNode();
        for(auto word:dict) construct(root,word);
        stringstream ss(sentence);
        string word,ans = "";
        while(ss >> word){
            if(ans == "") ans = search(root,word);
            else ans = ans + " "  + search(root,word);
        }
        return ans;
    }
};
