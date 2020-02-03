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
    
    struct Node{
        int take;
        int leave;
    };
    
public:
    int rob(TreeNode* root) {
        Node ans = dfs(root);
        return max(ans.take,ans.leave);
    }
    
    Node dfs(TreeNode* root){
        if(!root) return {0,0};
        Node left = dfs(root -> left);
        Node right = dfs(root -> right);
        Node current;
        current.take = max(root -> val + left.leave + right.leave,left.take + right.take);
        current.leave = left.take + right.take;
        return current;
    }
    
};
