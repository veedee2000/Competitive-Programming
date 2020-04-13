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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*>q;
        int ans;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0;i < sz;i++){
                if(i == 0) ans = q.front() -> val;
                TreeNode* curr = q.front();
                q.pop();
                if(curr -> left) q.push(curr -> left);
                if(curr -> right) q.push(curr -> right);
            }
        }
        return ans;
    }
};
