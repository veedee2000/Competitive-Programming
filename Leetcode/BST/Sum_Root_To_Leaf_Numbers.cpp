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
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        ans = 0;
        f(root,0); 
        return ans;
    }
    
    void f(TreeNode* root,int val){
        if(!root) return;
        val = val * 10 + root -> val;
        if(!root -> left and !root -> right) {ans += val; return;}
        f(root -> left,val);
        f(root -> right,val);
    }
};
