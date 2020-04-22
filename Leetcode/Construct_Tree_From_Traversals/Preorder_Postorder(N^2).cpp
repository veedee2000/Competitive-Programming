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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        return f(0,pre.size() - 1,pre,0,post.size() - 1,post);
    }
    
    TreeNode* f(int preStart,int preEnd,vector<int>& pre,int postStart,int postEnd,vector<int>& post){
        if(preStart > preEnd) return NULL;
        TreeNode* root = new TreeNode(pre[preStart]);
        preStart++,postEnd--;
        int leftIndex = postStart - 1,sz = 0;
        for(int i = postStart;i <= postEnd;i++){
            if(post[i] == pre[preStart]) {leftIndex = i; sz = leftIndex - postStart + 1; break;}
        }
        root -> left = f(preStart,preStart + sz - 1,pre,postStart,leftIndex,post);
        root -> right = f(preStart + sz,preEnd,pre,leftIndex + 1,postEnd,post);
        return root;
    }
};
