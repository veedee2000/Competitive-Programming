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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        dfs(root,val);
        return root;
    }
    
    TreeNode* dfs(TreeNode* root, int val){
        if(!root) return new TreeNode(val);
        if(root -> val > val){
            root -> left = dfs(root -> left,val);
        }
        else root -> right = dfs(root -> right,val);
        return root;
    }
};
