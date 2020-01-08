/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    vector<int>v;
    int sz;
    BSTIterator(TreeNode* root) {
        traverse(root);
        sz = 0;
    }
    
    void traverse(TreeNode* root){
        if(!root) return;
        traverse(root -> left);
        v.push_back(root -> val);
        traverse(root -> right);
    }
    
    /** @return the next smallest number */
    int next() {
        return v[sz++];
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return (sz < v.size());
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
