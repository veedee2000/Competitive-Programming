/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class FindElements {
public:
    TreeNode* new_root;
    unordered_map<int,int>mp;
    FindElements(TreeNode* root) {
        root -> val = 0;
        mp[0]++;
        construct(root);
        new_root = root;
    }
    
    void construct(TreeNode* root){
        if(root -> left){
            root -> left -> val = 2*(root -> val) + 1;
            mp[root -> left -> val]++;
            construct(root -> left);
        }
        if(root -> right){
            root -> right -> val = 2*(root -> val) + 2;
            mp[root -> right -> val]++;
            construct(root -> right);
        }
    }
    
    bool find(int target) {
        return mp[target];
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
