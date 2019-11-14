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
    vector<int>nums;
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        this -> nums = nums;
        return create(0,nums.size() - 1);
    }
    
    TreeNode* create(int left,int right){
        int mid = left + (right - left) / 2;
        if(left > right) return 0;
        TreeNode* node = new TreeNode(nums[mid]);
        node -> left = create(left,mid - 1);
        node -> right = create(mid + 1,right);
        return node;
    }
};
