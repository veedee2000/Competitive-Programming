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
    unordered_map<int,int>mp;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        for(int i = 0;i < n;i++) mp[inorder[i]] = i;
        return f(0,n - 1,inorder,0,n - 1,postorder);
    }
    
    TreeNode* f(int inStart,int inEnd,vector<int>& inorder,int postStart,int postEnd,vector<int>& postorder){
        if(inStart > inEnd) return NULL;
        TreeNode* root = new TreeNode(postorder[postEnd]);
        int indexIn = mp[postorder[postEnd]];
        int leftSize = indexIn - inStart;
        root -> left = f(inStart,indexIn - 1,inorder,postStart,postStart + leftSize - 1,postorder);
        root -> right = f(indexIn + 1,inEnd,inorder,postStart + leftSize,postEnd - 1,postorder);
        return root;
    }
};
