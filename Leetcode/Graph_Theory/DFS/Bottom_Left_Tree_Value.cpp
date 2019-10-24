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
    int level_max = 0, ans = 0;
    int findBottomLeftValue(TreeNode* root) {
        dfs(root,1);
        return ans;
    }
    void dfs(TreeNode* root, int level){
        if(!root -> right and !root -> left and level > level_max){
            ans = root -> val;
            level_max = level;
        }
        if(root -> left != NULL) dfs(root -> left, level + 1);
        if(root -> right != NULL) dfs(root -> right, level + 1);
    }
};
