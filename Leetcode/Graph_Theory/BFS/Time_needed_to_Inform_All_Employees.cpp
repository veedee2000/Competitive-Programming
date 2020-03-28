class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<vector<int>>>graph(n);
        for(int employee = 0;employee < n;employee++){
            if(employee != headID) graph[manager[employee]].push_back({employee,informTime[manager[employee]]});
        }
        queue<vector<int>>q;
        q.push({headID,0});
        int ans = 0;
        while(!q.empty()){
            vector<int> curr = q.front();
            cout<<curr[1]<<" ";
            ans = max(ans,curr[1]);
            q.pop();
            for(auto x:graph[curr[0]]){
                q.push({x[0],x[1] + curr[1]});
            }
        }
        return ans;
    }
};
