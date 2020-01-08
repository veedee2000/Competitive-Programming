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
    vector<int>ans;
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        int height = findHeight(root);
        ans.resize(height + 1);
        bfs(root);
        return ans;
    }
    
    int findHeight(TreeNode* root){
        if(!root) return -1;
        return 1 + max(findHeight(root -> left),findHeight(root -> right));
    }
    
    void bfs(TreeNode* root){
        unordered_map<TreeNode*,int>height;
        queue<TreeNode*>q;
        q.push(root);
        height[root] = 0;
        ans[0] = root -> val;
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            
            if(curr -> left){
                height[curr -> left] = height[curr] + 1;
                ans[height[curr -> left]] = curr -> left -> val;
                q.push(curr -> left);
            }
            
            if(curr -> right){
                height[curr -> right] = height[curr] + 1;
                ans[height[curr -> right]] = curr -> right -> val;
                q.push(curr -> right);
            }
        }
    }
};
