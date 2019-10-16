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
    vector<string>v;
    int sumRootToLeaf(TreeNode* root) {
        dfs(root, "");
        int ans = 0;
        for(auto x:v){
            ans += stoi(x, 0, 2);
            cout<<x<<" ";
        }
        return ans;
    }
    
    void dfs(TreeNode* node, string s){
        if(!node -> left and !node->right){
            s = s + to_string(node -> val);
            v.push_back(s);
        }
        else{
            if(node -> left != NULL) dfs(node->left, s + to_string(node -> val));
            if(node -> right != NULL) dfs(node->right, s + to_string(node -> val));
        }
    }
};
