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
    int ans=0;
    int maxDepth(TreeNode* root) {
        dfs(root, 1);
        return ans;
    }
    
    void dfs(TreeNode* root,int current){
        if(!root) return;
        ans = max(ans, current);
        if(root -> left != NULL) dfs(root -> left, current + 1);
        if(root -> right != NULL) dfs(root -> right, current + 1);
    }
    
};
