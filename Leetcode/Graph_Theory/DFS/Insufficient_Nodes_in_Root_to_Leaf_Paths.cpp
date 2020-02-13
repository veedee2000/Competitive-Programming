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
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        if(!root) return NULL;
        if(!root -> left and !root -> right){
            return (limit - root -> val > 0 ? NULL : root);
        }
        root -> left = sufficientSubset(root -> left,limit - root -> val);
        root -> right = sufficientSubset(root -> right,limit - root -> val);
        return ((!root -> left and !root -> right) ? NULL : root);  
    }
};
