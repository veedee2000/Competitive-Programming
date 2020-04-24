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
    unordered_map<int,bool>mp;
    int h,k;
    vector<int>ans;
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        k = K;
        setPath(root,target,0);
        trav(root,h);
        return ans;
    }
    
    bool setPath(TreeNode* root,TreeNode* target,int height){
        if(!root) return 0;
        if(root -> val == target -> val) {h = height; return mp[root -> val] = 1;}
        return mp[root -> val] = setPath(root -> left,target,height + 1) | setPath(root -> right,target,height + 1);
    }
    
    void trav(TreeNode* root,int dist){
        if(dist == k) ans.push_back(root -> val);
        if(root -> left){
            if(mp[root -> left -> val]) trav(root -> left,dist - 1);
            else trav(root -> left,dist + 1);
        }
        if(root -> right){
            if(mp[root -> right -> val]) trav(root -> right,dist - 1);
            else trav(root -> right,dist + 1);
        } 
    }
};
