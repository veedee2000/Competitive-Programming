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
    unordered_map<int,vector<TreeNode*>>dp;
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n % 2 == 0) return {};
        if(dp.count(n)) return dp[n];
        if(n == 1) return dp[1] = {new TreeNode(0)};
        for(int i = 1;i <= n - 2;i+=2){
            for(auto left:allPossibleFBT(i)){
                for(auto right:allPossibleFBT(n - 1 - i)){
                    TreeNode* root = new TreeNode(0);
                    root -> left = left,root -> right = right;
                    dp[n].push_back(root);
                }
            }
        }
        return dp[n];
    }
};
