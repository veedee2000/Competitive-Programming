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
    vector<string>ans;
    vector<string> binaryTreePaths(TreeNode* root) {
        string path = "";
        dfs(root,path);
        return ans;
    }
    void dfs(TreeNode* root, string path){
        if(!root) return;
        if(!root -> left and !root -> right){
            path += to_string(root -> val);
            ans.push_back(path);
        }
        if(root -> left != NULL){
            dfs(root -> left, path + to_string(root -> val) + "->");
        }
        if(root -> right != NULL){
            dfs(root -> right, path + to_string(root -> val) + "->");
        }
    }
};
