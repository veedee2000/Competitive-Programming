class Solution {
    
    struct TrieNode{
        TrieNode* child[2];
        
        TrieNode(){
            child[0] = child[1] = NULL;
        }
    };
    
    int insert(TrieNode* root, int num){
        TrieNode *p = root, *q = root;
        int ans = 0, bit;
        for(int i = 31;i >= 0;i--){
            bit = ((num >> i) & 1);
            if(!p -> child[bit]) p -> child[bit] = new TrieNode();
            p = p -> child[bit];
        }
        
        for(int i = 31;i >= 0;i--){
            bit = ((num >> i) & 1);
            if(q -> child[!bit]) q = q -> child[!bit], ans |= (1 << i);
            else q = q -> child[bit];
        }
        return ans;
    }
    
public:
    int findMaximumXOR(vector<int>& nums) {
        TrieNode* root = new TrieNode();
        int n = nums.size(), ans = 0;
        for(auto x:nums){
            ans = max(ans, insert(root, x));
        }
        return ans;
    }
};
