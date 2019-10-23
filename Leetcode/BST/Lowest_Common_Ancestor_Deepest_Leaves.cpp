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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(!root) return root;
        int l = dfs_max_depth(root -> left);
        int r = dfs_max_depth(root -> right);
        if(l == r) return root;
        else if(l < r) return lcaDeepestLeaves(root -> right);
        else return lcaDeepestLeaves(root -> left);
    }
    
    int dfs_max_depth(TreeNode* root){
        if(!root) return 0;
        return 1 + max(dfs_max_depth(root -> left), dfs_max_depth(root -> right));
    }
};
