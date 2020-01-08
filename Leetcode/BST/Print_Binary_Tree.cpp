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
    vector<vector<string>>ans;
    vector<vector<string>> printTree(TreeNode* root) {
        int m = 1 + height(root);
        int n = (1 << m) - 1;
        ans.resize(m,vector<string>(n, ""));
        int start = 0,end = n - 1;
        traverse(root,start,end,0);
        return ans;
    }
    
    int height(TreeNode* root){
        if(!root) return -1;
        return 1 + max(height(root -> left),height(root -> right));
    }
    
    void traverse(TreeNode* root,int start,int end,int h){
        if(start > end) return;
        if(!root){
            return;
        }
        int req = (start + end + 1) / 2;
        ans[h][req] = to_string(root -> val);
        traverse(root -> left,start,req - 1,h + 1);
        traverse(root -> right,req + 1,end,h + 1);
    }
};
