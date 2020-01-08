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
    vector<vector<int>>adj;
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        if(K == 0) return {target -> val};
        adj.resize(1100);
        create(root);
        bfs(target -> val,K);
        return ans;
    }
    
    void create(TreeNode* root){
        if(!root) return;
        if(root -> left){
            adj[root -> val].push_back(root -> left -> val);
            adj[root -> left -> val].push_back(root -> val);
        }
        if(root -> right){
            adj[root -> val].push_back(root -> right -> val);
            adj[root -> right -> val].push_back(root -> val);
        }
        create(root -> left);
        create(root -> right);
    }
    
    void bfs(int s,int k){
        queue<int>q;
        vector<bool>b(1100,0);
        int distance[1100];
        q.push(s);
        distance[s] = k;
        b[s] = 1;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(auto x:adj[curr]){
                if(!b[x]){
                    b[x] = 1;
                    distance[x] = distance[curr] - 1;
                    if(distance[x] == 0) ans.push_back(x);
                    else q.push(x);
                }
            }
        }
    }
    
    
    
    
};
