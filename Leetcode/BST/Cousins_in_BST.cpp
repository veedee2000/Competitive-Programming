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
    int levelx,levely;
    TreeNode *parentx, *parenty;
    bool isCousins(TreeNode* root, int x, int y) {
        if(root -> val == x or root -> val == y) return 0;
        f(root,x,0,0);
        f(root,y,0,1);
        cout<<levelx<<" "<<levely;
        return ((levelx == levely) and !(parentx == parenty));
    }
    
    void f(TreeNode* root,int val,int h,bool c){
        if(!root) return;
        if((root -> left ? root -> left -> val == val : 0) or (root -> right ? root -> right -> val == val : 0)){
            if(!c) levelx = h + 1,parentx = root;
            else levely = h + 1,parenty = root;
            return;
        }
        f(root -> left,val,h + 1,c);
        f(root -> right,val,h + 1,c);
    }
};
