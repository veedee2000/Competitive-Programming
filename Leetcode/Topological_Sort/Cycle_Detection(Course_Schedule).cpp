class Solution {
public:
    bool b[20110],c = 0;
    vector<vector<int>>graph;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph.resize(numCourses,vector<int>(0));
        for(int i = 0;i < prerequisites.size();i++){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        for(int i = 0;i < numCourses;i++){
            dfs(i);
            if(c) return 0;
        }
        return 1;
    }
    
    void dfs(int i){
        b[i] = 1;
        for(int j = 0;j < graph[i].size();j++){
            if(!b[graph[i][j]]) dfs(graph[i][j]);
            else{
                c = 1;
                return;
            }
        }
        b[i] = 0;
    }
};
