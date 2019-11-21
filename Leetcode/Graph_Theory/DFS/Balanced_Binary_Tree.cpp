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
    bool c = 1;
    bool isBalanced(TreeNode* root) {
        check(root);
        return c;
    }
    
    int check(TreeNode* root){
        if(!root) return -1;
        int lh = check(root -> left);
        int rh = check(root -> right);
        if(abs(lh - rh) > 1) c = 0;
        return 1 + max(lh,rh);
    }
};
