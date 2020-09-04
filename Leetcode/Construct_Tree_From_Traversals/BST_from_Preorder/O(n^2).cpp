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
    
    TreeNode* f(vector<int>& preorder, int start, int end){
        if(start > end) return NULL;
        TreeNode* node = new TreeNode(preorder[start]);
        int right = start + 1;
        while(right <= end and preorder[right] < preorder[start]) right++;
        node -> left = f(preorder, start + 1, right - 1);
        node -> right = f(preorder, right, end);
        return node;
    }
    
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return f(preorder, 0, preorder.size() - 1);
    }
};
