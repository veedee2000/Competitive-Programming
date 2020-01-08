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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(!root1 or !root2) return !(root1 or root2);
        if(root1 -> val == root2 -> val){
            
            bool notFlipped = flipEquiv(root1 -> left,root2 -> left) and flipEquiv(root1 -> right,root2 -> right);
                               
            bool Flipped =  flipEquiv(root1 -> left,root2 -> right) and flipEquiv(root1 -> right,root2 -> left);
                               
            return (notFlipped or Flipped);        
        }
        return 0;
    }
};
