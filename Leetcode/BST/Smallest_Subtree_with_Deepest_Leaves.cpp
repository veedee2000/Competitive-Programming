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
    unordered_map<TreeNode*,int>mp;
    vector<TreeNode*>deepest;
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        traverse(root,0);
        int maxVal = -1;
        for(auto x:mp) maxVal = max(maxVal,x.second);
        for(auto x:mp){
            if(x.second == maxVal) deepest.push_back(x.first);
        }
        TreeNode* ans = deepest[0];
        for(int i = 1;i < deepest.size();i++){
            ans = lca(root,ans,deepest[i]);
        }
        return ans;
    }
    
    void traverse(TreeNode* root,int h){
        if(!root) return;
        mp[root] = h;
        traverse(root -> left,h + 1);
        traverse(root -> right,h + 1);
    }
    
    TreeNode* lca(TreeNode* root,TreeNode* p,TreeNode* q){
        if(!root) return NULL;
        if(root == p or root == q) return root;
        TreeNode* l = lca(root -> left,p,q);
        TreeNode* r = lca(root -> right,p,q);
        if(l and r) return root;
        if(l) return l;
        if(r) return r;
        return NULL;
    }
};
