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
    int ans = INT_MAX,pre = -1;
    int getMinimumDifference(TreeNode* root) {
        if(!root) return ans;
        if(root -> left) getMinimumDifference(root -> left);
        if(pre != -1) ans = min(ans,root -> val - pre),pre = root -> val;
        else pre = root -> val;
        if(root -> right) getMinimumDifference(root -> right);
        return ans;
    }
};
