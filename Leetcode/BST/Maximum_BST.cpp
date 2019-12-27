/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int>nums;
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        this -> nums = nums;
        return construct(0,nums.size() - 1);
    }
    
    TreeNode* construct(int beg,int end){
        if(beg > end) return NULL;
        int max_val = nums[beg],in = beg;
        for(int i = beg;i <= end;i++){
            if(max_val < nums[i]) max_val = nums[i],in = i;
        }
        TreeNode* node = new TreeNode(max_val);
        node -> left = construct(beg,in - 1);
        node -> right = construct(in + 1,end);
        return node;
    }
};
