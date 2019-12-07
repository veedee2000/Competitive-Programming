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
    bool isSymmetric(TreeNode* root) {
        return dfs(root,root);
    }
    
    bool dfs(TreeNode* node1,TreeNode* node2){
        if(!node1 or !node2) return (!node1 and !node2);
        if(node1 -> val != node2 -> val) return 0;
        return (dfs(node1 -> left,node2 -> right) and dfs(node1 -> right,node2 -> left));
    }
};
