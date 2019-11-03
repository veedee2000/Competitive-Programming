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
    unordered_map<TreeNode*, int>level;
    int maxLevelSum(TreeNode* root) {
        return bfs(root);
    }
    
    int bfs(TreeNode* root){
        q.push(root);
        level[root] = 1;
        int current_level = 1,val = 0,ans = INT_MIN,ans_level = 1;
        while(!q.empty()){
            TreeNode* current = q.front();
            q.pop();
            
            if(current_level != level[current]){
                if(val > ans){
                    ans = val;
                    ans_level = current_level;
                }
                val = 0, current_level = level[current];
            }
            val += current -> val;
            
            if(current -> left){
                q.push(current -> left);
                level[current -> left] = level[current] + 1;
            }
            
            if(current -> right){
                q.push(current -> right);
                level[current -> right] = level[current] + 1;
            }
            
        }
        return ans_level;
    }
};
