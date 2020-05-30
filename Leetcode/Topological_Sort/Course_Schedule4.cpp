class Solution {
    
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>>graph(n);
        vector<int>inDegree(n,0);
        for(auto pairs:prerequisites){
            graph[pairs[0]].push_back(pairs[1]);
            inDegree[pairs[1]]++;
        }
        unordered_map<int,unordered_set<int>>mp;
        queue<int>q;
        for(int i = 0;i < n;i++) if(!inDegree[i]) q.push(i);
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(auto neighbour:graph[curr]){
                if(--inDegree[neighbour] == 0) q.push(neighbour);
                mp[neighbour].insert(curr);
                for(auto pre:mp[curr]) mp[neighbour].insert(pre);
            }
        }
        vector<bool>ans;
        for(auto pairs:queries){
            int child = pairs[1], parent = pairs[0];
            ans.push_back(mp[child].count(parent));
        }
        return ans;
    }
};
