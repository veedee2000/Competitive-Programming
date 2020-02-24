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
    int ans;
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 0;
        h(root);
        return ans;
    }
    
    int h(TreeNode* root){
        if(!root) return -1;
        int hLeft = h(root -> left),hRight = h(root -> right);
        ans = max(ans,hLeft + hRight + 2);
        return 1 + max(hLeft,hRight);
    }
};
