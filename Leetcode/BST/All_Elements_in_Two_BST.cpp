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
    vector<int>ans;
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        dfs(root1);
        dfs(root2);
        sort(ans.begin(),ans.end());
        return ans;
    }
    
    void dfs(TreeNode* root){
        if(!root) return;
        ans.push_back(root -> val);
        dfs(root -> left);
        dfs(root -> right);
    }
};
