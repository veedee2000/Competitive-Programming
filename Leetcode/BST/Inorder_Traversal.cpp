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
    vector<int> inorderTraversal(TreeNode* root) {
        traverse(root);
        return ans;
    }
    
    void traverse(TreeNode* root){
        if(!root) return;
        traverse(root -> left);
        ans.push_back(root -> val);
        traverse(root -> right);
    }
};
