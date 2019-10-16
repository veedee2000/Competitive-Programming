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
    vector<int>vp,vq;
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // memset(b,0,sizeof(b));
        dfsp(p);
        // memset(b,0,sizeof(b));
        dfsq(q);
        if(vp == vq) return true;
        else return false;
    }
    
    void dfsp(TreeNode* node){
        if(node !=  NULL){
            vp.push_back(node -> val);
            dfsp(node -> left);
            dfsp(node -> right);
        }
        if(node == NULL) vp.push_back(0);
    }
    
    void dfsq(TreeNode* node){
        if(node !=  NULL){
            vq.push_back(node -> val);
            dfsq(node -> left);
            dfsq(node -> right);
        }
        if(node == NULL) vq.push_back(0);
    }
};
