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
    vector<int>v1,v2;
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        dfs1(root1);
        dfs2(root2);
        return (v1 == v2);
    }
    
    void dfs1(TreeNode* root1){
        if(root1 == NULL) return ;
        if(!root1 -> left and !root1 -> right) v1.push_back(root1 -> val);
        if(root1 -> left != NULL) dfs1(root1 -> left);
        if(root1 -> right != NULL) dfs1(root1 -> right);
    }
    
    void dfs2(TreeNode* root2){
        if(root2 == NULL) return ;
        if(!root2 -> left and !root2 -> right) v2.push_back(root2 -> val);
        if(root2 -> left != NULL) dfs2(root2 -> left);
        if(root2 -> right != NULL) dfs2(root2 -> right);
    }
    
};
