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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        preorder.erase(preorder.begin());
        for(auto x:preorder) insert(root,x);
        return root;
    }
    
    TreeNode* insert(TreeNode* node,int val){
        if(!node) return new TreeNode(val);
        if(node -> val > val) node -> left = insert(node -> left,val);
        else node -> right = node -> right = insert(node -> right,val);
        return node;
    }
};
