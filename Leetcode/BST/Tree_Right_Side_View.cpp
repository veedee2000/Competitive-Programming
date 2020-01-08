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
    vector<int>ansReturn;
    vector<vector<int>>ans;
    vector<int> rightSideView(TreeNode* root) {
       int height = findHeight(root);
        ans.resize(height + 1);
        traverse(root,0);
        for(auto x:ans){
            ansReturn.push_back(x[x.size() - 1]);
        }
        return ansReturn;
    }
    
    int findHeight(TreeNode* root){
        if(!root) return -1;
        return 1 + max(findHeight(root -> left),findHeight(root -> right));
    }
    
    void traverse(TreeNode* root,int h){
        if(!root) return;
        ans[h].push_back(root -> val);
        traverse(root -> left,h + 1);
        traverse(root -> right,h + 1);
    }
};
