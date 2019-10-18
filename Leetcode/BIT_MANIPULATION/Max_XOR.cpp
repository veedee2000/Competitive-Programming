struct Trie{
    struct Trie *child[2];
    bool end_of_word;
};

struct Trie* getnode(void){
    struct Trie* node = new Trie;
    node -> end_of_word = false;
    for(int i=0;i<2;i++){
        node -> child[i] = NULL;
    }
    return node;
} 

int insert(struct Trie* root, int word){
    int maxval = 0,curr,curr_toggle;
    struct Trie * beta = root;
    for(int i = 31;i>=0;i--){
        if(word & (1<<i)) curr = 1;
        else curr = 0;
        root -> end_of_word = false;
        curr_toggle = curr ^ 1;
        if(!root -> child[curr]){
            root -> child[curr] = getnode();
        }
        if(!beta -> child[curr_toggle]){
            maxval = maxval << 1;
            beta = beta -> child[curr];
        }
        else{
            maxval = (maxval << 1) | 1;
            beta = beta -> child[curr_toggle];
        }
        root = root -> child[curr];
    }
    // cout<<maxval<<endl;
    root -> end_of_word = true;
    return maxval;
}


class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        struct Trie* root = getnode();
        int ans=0;
        for(auto x:nums){
            ans = max(ans, insert(root,x));
            cout<<endl;
        }
        return ans;
    }
    
};
