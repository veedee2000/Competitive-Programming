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
    int ans = 0,height = -1;
    int deepestLeavesSum(TreeNode* root) {
        cal(root,0);
        return ans;
    }
    
    void cal(TreeNode* root,int val){
        if(!root) return;
        if(val > height) height = val,ans = root -> val;
        else if(val == height) ans += root -> val;
        cal(root -> left,val + 1);
        cal(root -> right,val + 1);
    }
};
