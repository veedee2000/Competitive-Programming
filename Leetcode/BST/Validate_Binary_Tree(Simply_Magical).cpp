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
    bool isValidBST(TreeNode* root) {
        return isValidUtil(root, NULL, NULL);
    }
    bool isValidUtil(TreeNode* root, TreeNode* l,TreeNode* r){
        if(root == NULL) return true;
        
        if(l != NULL && root->val <= l->val)
            return false;
        if(r != NULL && root->val >= r->val)
            return false;
        return isValidUtil(root->left,l,root) 
            && isValidUtil(root->right,root,r);
    }
};
