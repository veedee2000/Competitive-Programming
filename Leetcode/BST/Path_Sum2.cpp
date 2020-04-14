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
    vector<vector<int>>ans;
    int sum;
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        this -> sum = sum;
        vector<int>p;
        dfs(root,0,p);
        return ans;
    }
    
    void dfs(TreeNode* root,int s,vector<int>&path){
        if(!root) return;
        path.push_back(root -> val);
        if(!root -> left and !root -> right){
            if(s + root -> val == sum) ans.push_back(path);
            path.pop_back();
            return;
        }
        dfs(root -> left,s + root -> val,path);
        dfs(root -> right,s + root -> val,path);
        path.pop_back();
    }
};
