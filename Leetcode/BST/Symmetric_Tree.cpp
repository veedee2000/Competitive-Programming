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
    vector<int>left,right;
    bool isSymmetric(TreeNode* root) {
        dfs_left(root);
        dfs_right(root);
        return (left == right);
    }
    
    void dfs_left(TreeNode* root){
        if(!root) {left.push_back(-1); return;}
        left.push_back(root -> val);
        dfs_left(root -> left);
        dfs_left(root -> right);
    }
    
    void dfs_right(TreeNode* root){
        if(!root) {right.push_back(-1); return;}
        right.push_back(root -> val);
        dfs_right(root -> right);
        dfs_right(root -> left);
    }
};
