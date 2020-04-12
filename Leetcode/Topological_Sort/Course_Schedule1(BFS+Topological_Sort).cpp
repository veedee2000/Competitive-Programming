class Solution {
    
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>inDegree(numCourses,0);
        vector<vector<int>>graph(numCourses);
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
            numCourses--;
            for(auto x:graph[curr]){
                if(inDegree[x]){
                    if(--inDegree[x] == 0) q.push(x);
                }
            }
        }
        return numCourses == 0;
    }
};
