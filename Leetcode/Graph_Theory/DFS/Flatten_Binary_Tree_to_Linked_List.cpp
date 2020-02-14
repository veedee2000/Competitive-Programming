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
    void flatten(TreeNode* root) {
        f(root);
    }
    
    TreeNode* f(TreeNode* root){
        if(!root) return NULL;
        if(!root -> left){
            root -> right = f(root -> right);
            return root;
        }
        TreeNode* node = f(root -> left);
        root -> left = NULL;
        TreeNode* nodeRight = root -> right;
        root -> right = node;
        if(node) while(node -> right) node = node -> right;
        node -> right = f(nodeRight);
        return root;
        
    }
    
};
