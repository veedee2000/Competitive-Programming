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
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        ans = 0;
        f(root,0);
        return ans;
    }
    
    void f(TreeNode* root,bool c){
        if(!root) return;
        if(!root -> left and !root -> right) {ans += c ? root -> val : 0; return;}
        f(root -> left,1);
        f(root -> right,0);
    }
};
