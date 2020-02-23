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
    TreeNode* prev,*firstEnd,*secondEnd;
    void recoverTree(TreeNode* root) {
        prev = firstEnd = secondEnd = NULL;
        correct(root);
        int temp = firstEnd -> val;
        firstEnd -> val = secondEnd -> val;
        secondEnd -> val = temp;
    }
    
    void correct(TreeNode* root){
        if(!root) return;
        if(!root -> left and !prev) prev = root;
        correct(root -> left);
        if(prev and prev -> val > root -> val){
            if(firstEnd == NULL){
                firstEnd = prev;
            }
            secondEnd = root;
        }
        prev = root;
        correct(root -> right);
    }
};
