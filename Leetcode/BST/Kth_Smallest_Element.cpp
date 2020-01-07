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
    vector<int>values;
    int kthSmallest(TreeNode* root, int k) {
        traverse(root);
        return values[k - 1];
    }
    
    void traverse(TreeNode* node){
        if(!node) return;
        traverse(node -> left);
        values.push_back(node -> val);
        traverse(node -> right);
    }
};
