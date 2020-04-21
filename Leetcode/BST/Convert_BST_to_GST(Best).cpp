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
    TreeNode* bstToGst(TreeNode* root) {
        f(root,0);
        return root;
    }
    
    int f(TreeNode* root,int count){
        if(!root) return 0;
        int rightSubtree = f(root -> right,count);
        root -> val += rightSubtree + count;
        int leftSubtree = f(root -> left,root -> val);
        return root -> val + leftSubtree - count;
    }
};
