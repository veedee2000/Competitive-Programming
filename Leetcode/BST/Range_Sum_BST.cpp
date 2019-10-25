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
    int rangeSumBST(TreeNode* root, int L, int R) {
        dfs(root, L, R);
        return ans;
    }
    
    void dfs(TreeNode* root, int L, int R){
        if(!root) return;
        if(root -> val >= L and root -> val <=  R) ans += root -> val;
        dfs(root -> left, L, R);
        dfs(root -> right, L, R);
    }
};
