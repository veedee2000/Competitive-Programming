/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        deque<TreeNode*>d;
        if(root) d.push_back(root);
        bool even = 0;
        while(!d.empty()){
            int sz = d.size();
            vector<int>level;
            while(sz--){
                if(even){
                    TreeNode* curr = d.back();
                    d.pop_back();
                    level.push_back(curr -> val);
                    if(curr -> right) d.push_front(curr -> right);
                    if(curr -> left) d.push_front(curr -> left);
                }
                else{
                    TreeNode* curr = d.front();
                    d.pop_front();
                    level.push_back(curr -> val);
                    if(curr -> left) d.push_back(curr -> left);
                    if(curr -> right) d.push_back(curr -> right);
                }
            }
            ans.push_back(level);
            even = !even;
        }
        return ans;
    }
};
