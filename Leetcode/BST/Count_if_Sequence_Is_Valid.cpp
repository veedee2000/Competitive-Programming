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
    bool isValidSequence(TreeNode* root, vector<int>& arr,int i = 0) {
        if(!root) return 0;
        if(i == arr.size()) return 0;
        if(!root -> right and !root -> left and root -> val == arr[i] and i == arr.size() - 1) return 1;
        if(root -> val != arr[i]) return 0;
        return isValidSequence(root -> left,arr,i + 1) or isValidSequence(root -> right,arr,i + 1);
    }
};
