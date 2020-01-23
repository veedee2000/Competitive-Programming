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
    int ans;
    int distributeCoins(TreeNode* root) {
        ans = 0;
        dfs(root);
        return ans;
    }
    
    int dfs(TreeNode* root){
        if(!root) return 0;
        int left = dfs(root -> left);
        int right = dfs(root -> right);
        ans += abs(left) + abs(right);
        return root -> val + left + right - 1;
    }
};
