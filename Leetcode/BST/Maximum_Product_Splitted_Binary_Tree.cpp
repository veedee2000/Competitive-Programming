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
    long long ans,sum;
    int maxProduct(TreeNode* root) {
        if(!root or (!root -> left and !root -> right)) return 0;
        ans = INT_MIN,sum = 0;
        const int mod = 1e9 + 7;
        changeTree(root);
        sum += root -> val;
        calculate(root);
        return ans % mod;
    }
    
    int changeTree(TreeNode* root){
        if(!root) return 0;
        return root -> val += changeTree(root -> left) + changeTree(root -> right);
    }
    
    void calculate(TreeNode* root){
        if(!root) return;
        if(root -> left) ans = max(ans,(long long) (sum - root -> left -> val) * root -> left -> val),calculate(root -> left);
        if(root -> right) ans = max(ans,(long long) (sum - root -> right -> val) * root -> right -> val),calculate(root -> right);
    }

};
