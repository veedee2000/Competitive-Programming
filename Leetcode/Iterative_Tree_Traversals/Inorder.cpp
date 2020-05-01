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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*>s;
        TreeNode* curr = root;
        vector<int>ans;
        while(1){
            if(s.empty() and curr == NULL) break;
            while(curr != NULL) s.push(curr),curr = curr -> left;
            ans.push_back(s.top() -> val);
            curr = s.top() -> right;
            s.pop();
        }
        return ans;
    }
};
