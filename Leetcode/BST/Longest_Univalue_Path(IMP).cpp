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
    int ans = 1;
    int longestUnivaluePath(TreeNode* root) {
        if(!root) return 0;
        f(root,root -> val);
        return ans - 1;
    }
    
    int f(TreeNode* root,int val){
        if(!root) return 0;
        int leftVal = f(root -> left,root -> val),rightVal = f(root -> right,root -> val);
        ans = max(ans,1 + leftVal + rightVal);
        if(root -> val != val) return 0;
        return 1 + max(leftVal,rightVal);
    }
};
