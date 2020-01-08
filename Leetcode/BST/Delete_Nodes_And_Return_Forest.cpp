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
    vector<TreeNode*>ans;
    unordered_map<int,int>mp;
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(auto x:to_delete) mp[x]++;
        if(!mp.count(root -> val)) ans.push_back(root);
        traverse(root);
        return ans;
    }
    
    TreeNode* traverse(TreeNode* root){
        if(!root) return NULL;
        root -> left = traverse(root -> left);
        root -> right = traverse(root -> right);
        if(mp.count(root -> val)){
            if(root -> left) ans.push_back(root -> left);
            if(root -> right) ans.push_back(root -> right);
            root -> left = NULL;
            root -> right = NULL;
            return NULL;
        }
        return root;
    }
};
