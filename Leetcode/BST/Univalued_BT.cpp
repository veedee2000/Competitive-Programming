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
    bool isUnivalTree(TreeNode* root) {
        return f(root,root -> val);
    }
    
    bool f(TreeNode* root,int val){
        if(!root) return 1;
        if(root -> val != val) return 0;
        return f(root -> left,val) and f(root -> right,val);
    }
};
