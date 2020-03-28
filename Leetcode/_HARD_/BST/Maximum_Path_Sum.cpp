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
    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        f(root);
        return ans;
    }
    
    int f(TreeNode* root){
        if(!root) return 0;
        int leftVal = f(root -> left);
        int rightVal = f(root -> right);
        int valIfPath = root ->val + max({leftVal,rightVal,0});
        ans = max({ans,valIfPath,root -> val + leftVal + rightVal});
        root -> val = valIfPath;
        return root -> val;
    }
};
