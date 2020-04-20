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
        return f(0,preorder.size() - 1,preorder);
    }
    
    TreeNode* f(int start,int end,vector<int>& preorder){
        TreeNode* root = new TreeNode(preorder[start]);
        if(start == end) return root;
        int rightStart = end + 1;
        for(int i = start + 1;i <= end;i++){
            if(preorder[i] > preorder[start]) {rightStart = i; break;}
        } 
        
        root -> left = (rightStart == start + 1) ? NULL :  f(start + 1,rightStart - 1,preorder);
        root -> right = (rightStart == end + 1) ? NULL : f(rightStart,end,preorder);
        
        return root;
    }
};
