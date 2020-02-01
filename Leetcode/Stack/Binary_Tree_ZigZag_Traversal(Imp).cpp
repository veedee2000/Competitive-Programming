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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>>ans;
        deque<TreeNode*>d;
        d.push_back(root);
        bool flag = 1;
        while(!d.empty()){
            vector<int>v;
            int len = d.size();
            while(len--){
                if(flag){
                    TreeNode* curr = d.front();
                    d.pop_front();
                    v.push_back(curr -> val);
                    if(curr -> left) d.push_back(curr -> left);
                    if(curr -> right) d.push_back(curr -> right);
                }
                else{
                    TreeNode* curr = d.back();
                    d.pop_back();
                    v.push_back(curr -> val);
                    if(curr -> right) d.push_front(curr -> right);
                    if(curr -> left) d.push_front(curr -> left);
                }
            }
            flag = !flag;
            ans.push_back(v);
        }
        return ans;
    }
};
