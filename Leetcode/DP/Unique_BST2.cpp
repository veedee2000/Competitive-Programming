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
    unordered_map<int,unordered_map<int,vector<TreeNode*>>>dp;
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return {};
        return f(1,n);
    }
    
    vector<TreeNode*>f(int start,int end){
        if(start > end) return {NULL};
        if(dp[start].count(end)) return dp[start][end];
        for(int i = start;i <= end;i++){
            for(auto left:f(start,i - 1)){
                for(auto right:f(i + 1,end)){
                    TreeNode* root = new TreeNode(i);
                    root -> left = left,root -> right = right;
                    dp[start][end].push_back(root);
                }
            }
        }
        return dp[start][end];
    }
};
