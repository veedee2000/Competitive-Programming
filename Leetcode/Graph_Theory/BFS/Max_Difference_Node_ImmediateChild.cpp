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
    queue<TreeNode*>q;
    int ans = 0;
    int maxAncestorDiff(TreeNode* root) {
        bfs(root);
        return ans;
    }
    
    void bfs(TreeNode* root){
        if(!root) return; 
        q.push(root);
        while(!q.empty()){
            TreeNode* current = q.front();
            q.pop();
            if(current -> left != NULL){
                q.push(current -> left);
                ans = max(ans, abs(current -> val - current -> left -> val));
            }
            if(current -> right != NULL){
                q.push(current -> right);
                ans = max(ans, abs(current -> val - current -> right -> val));
            }
        }
    }
};
