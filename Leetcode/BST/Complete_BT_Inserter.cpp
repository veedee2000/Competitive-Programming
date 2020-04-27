/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class CBTInserter {
public:
    TreeNode *root;
    vector<TreeNode*>v;
    int height;
    CBTInserter(TreeNode* rootNode) {
        root = rootNode;
        height = h(root);
        f(root,0);
    }
    
    int insert(int val) {
        if(!v.size()) height++, f(root,0);
        TreeNode *ret = v[0];
        if(v.size() > 1 and v[0] == v[1]) v[0] -> left = new TreeNode(val);
        else v[0] -> right = new TreeNode(val);
        v.erase(v.begin());
        return ret -> val;
    }
    
    TreeNode* get_root() {
        return root;
    }
    
    int h(TreeNode* root){
        if(!root) return -1;
        return 1 + max(h(root -> left),h(root -> right));
    }
    
    void f(TreeNode* root,int ht){
        if(!root) return;
        if(ht == height - 1){
            if(!root -> left) v.push_back(root);
            if(!root -> right) v.push_back(root);
        }
        else{
            f(root -> left,ht + 1);
            f(root -> right,ht + 1);
        }
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */
