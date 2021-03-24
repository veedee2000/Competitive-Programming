class Solution {
    
    struct trie{
        vector<trie*>child;
        bool endOfWord;
        int count;
        trie(){
            child = vector<trie*>(2, NULL);
            count = 0;
        }
    };
    
    int countSmaller(trie* root, int n, int k){
        int ans = 0;
        for(int i = 16;i >= 0 and root;i--){
            int bit1 = (n >> i) & 1, bit2 = (k >> i) & 1;
            if(!bit2){
                root = root -> child[bit1];
                continue;
            }
            if(root->child[bit1]) {
                ans += root -> child[bit1] -> count; 
            }
            root = root -> child[1 - bit1];
        }
        return ans;
    }
    
    void insert(trie* root, int x){
        for(int i = 16;i >= 0;i--){
            int bit = (x >> i) & 1;
            if(!root -> child[bit]) root -> child[bit] = new trie();
            root = root -> child[bit];
            root -> count++;
        }
    }
    
public:
    int countPairs(vector<int>& nums, int low, int high) {
        trie* root = new trie();    
        int ans = 0;
        for(int i = 0;i < nums.size();i++){
            ans += countSmaller(root, nums[i], high + 1) - countSmaller(root, nums[i], low);
            insert(root, nums[i]);
        }
        return ans;
    }
};
