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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p or !q) return (p == q);
        else if(p -> val != q -> val) return 0;
        else return (isSameTree(p -> left, q -> left) and isSameTree(p -> right, q -> right));
    }
};
