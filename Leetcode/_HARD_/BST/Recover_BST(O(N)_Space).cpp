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
    vector<int>v,sub,s;
    void recoverTree(TreeNode* root) {
        f(root);
        sub = v;
        sort(v.begin(),v.end());
        for(int i = 0;i < v.size();i++){
            if(v[i] != sub[i]){
                s = {v[i],sub[i]};
                break;
            }
        }
        correct(root);
    }
    
    void f(TreeNode* root){
        if(!root) return;
        f(root -> left);
        v.push_back(root -> val);
        f(root -> right);
    }
    
    void correct(TreeNode* root){
        if(!root) return;
        if(root -> val == s[0]) root -> val = s[1];
        else if(root -> val == s[1]) root -> val = s[0];
        correct(root -> left);
        correct(root -> right);
    }
};
