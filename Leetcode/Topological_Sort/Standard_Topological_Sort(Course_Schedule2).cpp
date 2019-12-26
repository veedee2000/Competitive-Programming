class Solution {
public:
    vector<vector<int>>graph;
    vector<int>ans,aux;
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        graph.resize(numCourses,vector<int>(0));
        bool b[numCourses],check[numCourses];
        memset(check,0,sizeof(check));
        
        for(int i = 0;i < prerequisites.size();i++){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        while(ans.size() < numCourses){
            memset(b,0,sizeof(b));
            for(int i = 0;i < numCourses;i++){
                if(!check[i]){
                    for(int j = 0;j < graph[i].size();j++){
                        b[graph[i][j]] = 1;
                    }
                }
            }
            bool c = 1;
            for(int i = 0;i < numCourses;i++){
                if(!b[i] and !check[i]){
                    ans.push_back(i);
                    check[i] = 1;
                    c = 0;
                }
            }
            if(c) return aux;
        }
        return ans;
    }
};
