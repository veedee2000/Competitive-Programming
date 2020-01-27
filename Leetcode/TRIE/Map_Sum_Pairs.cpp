struct trie{
    struct trie* child[26];
    int sum;
};

struct trie* getNode(){
    struct trie* root = new trie;
    for(int i = 0;i < 26;i++) root -> child[i] = NULL;
    root -> sum = 0;
    return root;
}

void construct(struct trie* root,string& word,int val,int pre){
    for(auto x:word){
        int index = x - 'a';
        if(!root -> child[index]) root -> child[index] = getNode();
        root = root -> child[index];
        root -> sum = root -> sum + val - pre;
    }
}

int sumAt(struct trie* root,string& word){
    for(auto x:word){
        int index = x - 'a';
        if(!root -> child[index]) return 0;
        root = root -> child[index];
    }
    return root -> sum;
}

class MapSum {
public:
    /** Initialize your data structure here. */
    struct trie* root;
    unordered_map<string,int>mp;
    MapSum() {
        root = getNode();
    }
    
    void insert(string key, int val) {
        if(mp.count(key)) construct(root,key,val,mp[key]);
        else construct(root,key,val,0);
        mp[key] = val;
    } 
    
    int sum(string prefix) {
        return sumAt(root,prefix);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
