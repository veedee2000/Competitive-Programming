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
    bool ans = 0;
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return 0;
        dfs_sum(root, 0, sum);
        return ans; 
    }
    
    void dfs_sum(TreeNode* root, int now, int sum){
        if(!root) return;
        now += root -> val;
        if(!root -> left and !root -> right and now == sum){
            ans = 1;
        } 
        dfs_sum(root -> left, now, sum);
        dfs_sum(root -> right, now, sum);
    }
};
