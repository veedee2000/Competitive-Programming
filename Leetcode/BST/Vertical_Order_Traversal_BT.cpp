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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root) return {};
        map<int,vector<int>>mp;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            int sz = q.size();
            unordered_map<int,set<int>>s;
            while(sz--){
                pair<TreeNode*,int>curr = q.front();
                q.pop();
                TreeNode* node = curr.first;
                int dir = curr.second;
                s[dir].insert(node -> val);
                if(node -> left) q.push({node -> left,dir - 1});
                if(node -> right) q.push({node -> right,dir + 1});
            }
            for(auto sets:s){
                for(auto ele:sets.second){
                    mp[sets.first].push_back(ele);
                }
            }
        }
        for(auto x:mp) ans.push_back(x.second);
        return ans;
    }
};
