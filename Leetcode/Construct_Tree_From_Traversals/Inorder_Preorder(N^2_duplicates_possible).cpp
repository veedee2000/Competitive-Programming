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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        return f(0,n - 1,preorder,0,n - 1,inorder);
    }
    
    TreeNode* f(int preStart,int preEnd,vector<int>&preorder,int inStart,int inEnd,vector<int>&inorder){
        if(preStart > preEnd) return NULL;
        TreeNode* root = new TreeNode(preorder[preStart]);
        if(preStart == preEnd) return root;
        int indexIn;
        for(int i = inStart;i <= inEnd;i++){
            if(inorder[i] == preorder[preStart]){
                indexIn = i; break;
            }
        }
        int sizeLeft = indexIn - inStart;
        root -> left = f(preStart + 1,preStart + sizeLeft,preorder,inStart,indexIn - 1,inorder);
        root -> right = f(preStart + sizeLeft + 1,preEnd,preorder,indexIn + 1,inEnd,inorder);
        return root;
    }
};
