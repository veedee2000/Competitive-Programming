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
    int ans = 10000;
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        dfs(root,1);
        return ans;
    }
    
    void dfs(TreeNode* root, int depth){
        if(!root) return;
        if(!root -> left and !root -> right){
            ans = min(ans, depth);
        }
        dfs(root -> left, depth + 1);
        dfs(root -> right, depth + 1);
    }
    
};
