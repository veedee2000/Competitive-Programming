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
    unordered_map<TreeNode*,unordered_map<bool,int>>dp;
    int rob(TreeNode* root) {
        int ans = f(root,1);
        return ans;
    }
    
    int f(TreeNode* root,bool c){
        if(!root) return 0;
        if(dp[root].count(c)) return dp[root][c];
        int ans;
        if(c == 1){
            ans = max(root -> val + f(root -> left,0) + f(root -> right,0),f(root -> left,1) + f(root -> right,1));
        }
        else{
            ans = f(root -> left,1) + f(root -> right,1);
        }
        return dp[root][c] = ans;
    }
};
