class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>inDegree(numCourses,0);
        vector<vector<int>>graph(numCourses);
        vector<int>ans,empty = {};
        for(auto edge:prerequisites){
            graph[edge[0]].push_back(edge[1]);
            inDegree[edge[1]]++;
        }
        queue<int>q;
        for(int i = 0;i < numCourses;i++){
            if(!inDegree[i]) q.push(i);
        }
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            ans.push_back(curr);
            numCourses--;
            for(auto x:graph[curr]){
                if(inDegree[x]){
                    if(--inDegree[x] == 0) q.push(x);
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return numCourses == 0 ? ans : empty;
    }
};
