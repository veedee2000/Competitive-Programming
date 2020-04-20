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
    string ans;
public:
    string smallestFromLeaf(TreeNode* root) {
        ans = "";
        f(root,ans);
        return ans;
    }
    
    void f(TreeNode* root,string& s){
        if(!root) return;
        s.insert(0,1,(char) 'a' + root -> val);
        if(!root -> left and !root -> right){
            if(ans == "") ans = s;
            else ans = min(ans,s);
            return;
        }
        f(root -> left,s);
        f(root -> right,s);
        s.erase(s.begin());
    }
};
