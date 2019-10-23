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
    vector<int>ans;
    queue<TreeNode*>q;
    long long a[1100];
    map<TreeNode*,int>level;
    vector<int> largestValues(TreeNode* root) {
        for(int i = 0;i < 1000;i++) a[i] = LLONG_MIN;
        bfs(root);
        for(int i = 0;i < 1000;i++){
            if(a[i] > LLONG_MIN) ans.push_back(a[i]);
        }
        return ans;
    }
    
    void bfs(TreeNode* root){
        if(!root) return;
        q.push(root);
        level[root] = 0;
        a[level[root]] = root -> val; 
        while(!q.empty()){
            root = q.front();
            q.pop();
            if(root -> left != NULL) {
                q.push(root -> left);
                level[root -> left] = level[root] + 1;
                a[level[root -> left]] = max(a[level[root -> left]], (long long) q.back() -> val);
            }
            if(root -> right != NULL) {
                q.push(root -> right);
                level[root -> right] = level[root] + 1;
                a[level[root -> right]] = max(a[level[root -> right]], (long long) q.back() -> val);
            }
        }   
    }
};
