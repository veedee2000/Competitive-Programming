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
    int ans = 0;
    int maxAncestorDiff(TreeNode* root) {
        dfs(root, INT_MAX, INT_MIN);
        return ans;
    }
    
    void dfs(TreeNode* root, int minval, int maxval){
        minval = min(minval, root -> val);
        maxval = max(maxval, root -> val);
        ans = max(ans, maxval - minval);
        if(root -> left != NULL) dfs(root -> left, minval, maxval);
        if(root -> right != NULL) dfs(root -> right, minval, maxval);
    }
};
