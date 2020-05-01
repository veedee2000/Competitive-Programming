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
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};
        stack<TreeNode*>s;
        s.push(root);
        vector<int>ans;
        TreeNode* curr;
        while(!s.empty()){
            ans.push_back(s.top() -> val);
            curr = s.top();
            s.pop();
            if(curr -> left) s.push(curr -> left);
            if(curr -> right) s.push(curr -> right);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
