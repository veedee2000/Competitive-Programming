class Solution {
public:
    vector<vector<int>>graph;
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        queue<pair<vector<int>,double>>q;
        q.push({{1,0},1.0});
        graph.resize(n + 1);
        for(auto x:edges){
            graph[x[1]].push_back(x[0]);
            graph[x[0]].push_back(x[1]);
        }
        vector<int>b(n + 1,0);
        b[1] = 1;
        while(!q.empty()){
            pair<vector<int>,double>curr = q.front();
            q.pop();
            if(curr.first[0] == target){
                if(curr.first[1] == t) return curr.second;
                if(curr.first[1] < t){
                    for(auto x:graph[target]){
                        if(!b[x]) return 0;
                    }
                    return curr.second;
                }
                else return 0;
            }
            int num = 0;
            for(auto x:graph[curr.first[0]]){
                if(!b[x]) num++;
            }
            for(auto x:graph[curr.first[0]]){
                if(!b[x]){
                    b[x] = 1;
                    q.push({{x,curr.first[1] + 1},(double) curr.second / num});
                }
            }
        }
        return 0;
    }
};
