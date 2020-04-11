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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        int ans = 1;
        while(!q.empty()){
            int sz = q.size(),minL,maxL,c = 0;
            while(sz--){
                pair<TreeNode*,int>curr = q.front();
                q.pop();
                if(!c) c = !c,minL = maxL = curr.second;
                else{
                    minL = min(minL,curr.second);
                    maxL = max(maxL,curr.second);
                    ans = max(ans,maxL - minL + 1);
                }
                TreeNode* node = curr.first;
                if(node -> left) q.push({node -> left,2 * curr.second + 1});
                if(node -> right) q.push({node -> right,2 * curr.second});
            }
        }
        return ans;
    }
};
