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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        if(root -> val > key) root -> left = deleteNode(root -> left,key);
        else if(root -> val < key) root -> right = deleteNode(root -> right,key);
        else{
            if(!root -> left and !root -> right){
                delete root;
                root = NULL;
                return NULL;
            }
            
            else if(root -> left and !root -> right){
                TreeNode* node = root -> left;
                delete root;
                root = NULL;
                return node;
            }
            
            else if(!root -> left and root -> right){
                TreeNode* node = root -> right;
                delete root;
                root = NULL;
                return node;
            }
            
            else{
                TreeNode* node = root -> left;
                while(node -> right) node = node -> right;
                root -> val = node -> val;
                root -> left = deleteNode(root -> left,node -> val); 
            }
        }
        return root;
    }
};
