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
    map<int,int>mp;
    vector<int>ans;
    int maxVal;
    vector<int> findFrequentTreeSum(TreeNode* root) {
        maxVal = -1;
        if(!root) return {};
        traverse(root);
        for(auto x:mp){
            if(x.second == maxVal) ans.push_back(x.first);
        }
        return ans;
    }
    
    int traverse(TreeNode* root){
        if(!root) return 0;
        int value = root -> val + traverse(root -> left) + traverse(root -> right);
        mp[value]++;
        maxVal = max(maxVal,mp[value]);
        return value;
    }
};
