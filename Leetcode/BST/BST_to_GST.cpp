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
    vector<int>v,prefix;
    TreeNode* bstToGst(TreeNode* root) {
        store(root);
        pre();
        return new_val(root);
    }
    
    void store(TreeNode* root){
        if(!root) return;
        store(root -> left);
        v.push_back(root -> val);
        store(root -> right);
    }
    
    void pre(){
        int sum = 0;
        reverse(v.begin(),v.end());
        for(auto x:v){
            sum += x;
            prefix.push_back(sum);
        }
    }
    
    TreeNode* new_val(TreeNode* root){
        if(!root) return NULL;
        for(int i = 0;i < v.size();i++){
            if(v[i] == root -> val){
                root -> val = prefix[i];
                break;
            }
        }
        new_val(root -> left);
        new_val(root -> right);
        return root;
    }
    
};
