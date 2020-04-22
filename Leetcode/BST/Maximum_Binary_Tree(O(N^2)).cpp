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
    vector<int>nums;
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        vector<int>A = deconstruct(root);
        A.push_back(val);
        nums = A;
        return f(0,A.size() - 1);
    }
    
    vector<int> deconstruct(TreeNode* root){
        if(!root) return {};
        vector<int>now = deconstruct(root -> left);
        now.push_back(root -> val);
        for(auto x:deconstruct(root -> right)) now.push_back(x);
        return now;
    }
    
    TreeNode* f(int start,int end){
        if(start > end) return NULL;
        int index = start;
        for(int i = start;i <= end;i++){
            if(nums[i] > nums[index]) index = i;
        } 
        TreeNode* root = new TreeNode(nums[index]);
        root -> left = f(start,index - 1);
        root -> right = f(index + 1,end);
        return root;
    }
};
