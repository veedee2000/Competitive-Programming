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
    /*
        Given node -> none - 0
        Given node -> child - 1
        Given node -> grandchild - 2
        Given node -> both - 3
    */
public:
    int ans;
    int sumEvenGrandparent(TreeNode* root) {
        ans = 0;
        f(root,0);
        return ans;
    }
    
    void f(TreeNode* root,int c){
        if(!root) return;
        if(c < 2){
            ans += c ? root -> val : 0;
            if(root -> val % 2 == 0) f(root -> right,2),f(root -> left,2);
            else f(root -> right,0),f(root -> left,0);
        }
        else{
            ans += c == 3 ? root -> val : 0;
            if(root -> val % 2 == 0) f(root -> right,3),f(root -> left,3);
            else f(root -> right,1),f(root -> left,1);
        }
    }
};
