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
    bool c;
    bool isCompleteTree(TreeNode* root) {
        if(!root) return 1;
        c = 1;
        bfs(root);
        return c;
    }
    
    void bfs(TreeNode* root){
        unordered_map<TreeNode*,int>height;
        unordered_map<int,bool>heightExist;
        queue<TreeNode*>q;
        q.push(root);
        height[root] = 0;
        heightExist[0] = 1;
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr -> left){
                height[curr -> left] = height[curr] + 1;
                
                if(!heightExist.count(height[curr -> left])) heightExist[height[curr -> left]] = 1;
                                                                                           if(!heightExist[height[curr -> left]]){                                      c = 0; return;
                }
                q.push(curr -> left);
            }
            else heightExist[height[curr] + 1] = 0,heightExist[height[curr] + 2] = 0;
            
            if(curr -> right){
                height[curr -> right] = height[curr] + 1;
                                                                                           if(!heightExist[height[curr -> right]]){                                      c = 0; return;
                }
                q.push(curr -> right);
            }
            else heightExist[height[curr] + 1] = 0,heightExist[height[curr] + 2] = 0;
        }
    }
};
