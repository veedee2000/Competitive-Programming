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
    
    // -1 -> compulsarily fit the camera 
    // 0 -> does not contain coverage, if u don't fit camera then child must compulsarily have camera
    // 1 -> contains coverage
    
    const int INF = 1e7;
    
    unordered_map<TreeNode*,unordered_map<int,int>>dp;
    int minCameraCover(TreeNode* root) {
        if(!root) return 0;
        if(!root -> left and !root -> right) return 1;
        return f(root,0);
    }
    
    int f(TreeNode* root,int state){
        if(!root) return state == -1 ? INF : 0;
        if(dp[root].count(state)) return dp[root][state];
        int ans;
        if(state == -1) ans = 1 + f(root -> left,1) + f(root -> right,1);
        else if(state == 0) ans = min({1 + f(root -> left,1) + f(root -> right,1),f(root -> left,-1) + f(root -> right,-1),f(root -> left,-1) + f(root -> right,0),f(root -> left,0) + f(root -> right,-1),f(root -> left,-1) + f(root -> right,-1)});
        else ans = min(1 + f(root -> left,1) + f(root -> right,1),f(root -> left,0) + f(root -> right,0));
        return dp[root][state] = ans;
    }
};
