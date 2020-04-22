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
    int level = 0,index = 0;
    string s;
    TreeNode* recoverFromPreorder(string& s,int currLevel = 0) {
        int num = 0;
        while(index < s.size() and s[index] != '-') num = num * 10 + int (s[index++] - '0');
        TreeNode* root = new TreeNode(num);
        level = 0;
        while(index < s.size() and s[index] == '-') level++,index++;
        if(level <= currLevel) return root;
        root -> left = recoverFromPreorder(s,currLevel + 1);
        if(level <= currLevel) return root;
        root -> right = recoverFromPreorder(s,currLevel + 1);
        return root;
    }
};
