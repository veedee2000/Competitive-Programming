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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(!t1) return t2;
        if(!t2) return t1;
        if(!t1 and !t2) return NULL;
        TreeNode* t = new TreeNode(0);
        t -> val = t1 -> val + t2 -> val;
        t -> left = mergeTrees(t1 -> left, t2 -> left);
        t -> right = mergeTrees(t1 -> right, t2 -> right);
        return t;
    }
};
