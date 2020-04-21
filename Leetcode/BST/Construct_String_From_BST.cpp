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
    string ans = "";
    bool c = 0;
    string tree2str(TreeNode* root,bool c = 0) {
        if(!root) return "";
        if(ans.size()) ans += "(",c = 1;
        ans += to_string(root -> val);
        if(!root -> left and root -> right) ans += "()"; 
        if(root -> left) tree2str(root -> left);
        if(root -> right) tree2str(root -> right);
        if(c) ans += ")";
        return ans;
    }
};
