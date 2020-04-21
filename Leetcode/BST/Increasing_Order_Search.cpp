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
    TreeNode* newRoot = NULL, *t;
    TreeNode* increasingBST(TreeNode* root) {
        f(root);
        return newRoot;
    }
    
    void f(TreeNode* root){
        if(!root) return;
        f(root -> left);
        if(!newRoot) newRoot = new TreeNode(root -> val),t = newRoot;
        else t -> right = new TreeNode(root -> val), t = t -> right;
        f(root -> right);
    }
};
