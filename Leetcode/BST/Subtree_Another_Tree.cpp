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
    bool ans = 1,ans_final = 0;
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!s or !t) return (!s & !t);
        if(s -> val == t -> val){
            ans = 1;
            check(s,t);
            ans_final |= ans;
        }
        isSubtree(s -> right, t);
        isSubtree(s -> left, t);
        return ans_final;
    }
    
    void check(TreeNode* s,TreeNode* t){
        if(!s or !t) ans &= (!s & !t);
        else{
            ans &= (s -> val == t -> val);
            if(ans){
                check(s ->left, t -> left);
                check(s -> right, t -> right);
            }
        }
    }
};
