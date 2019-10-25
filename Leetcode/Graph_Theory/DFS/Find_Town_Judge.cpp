class Solution {
public:
    int count = 0,index;
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>v[1101];
        for(int i = 0;i < trust.size();i++){
            v[trust[i][0]].push_back(trust[i][1]);
        }
        for(int i = 1;i <= n;i++){
            cout<<v[i].size();
            if(v[i].size() == 0) {++count; index = i;}
        }
        if(count == 1){
            for(int i = 1;i <= n;i++){
                if(i != index){
                    if(!dfs(i,index,v)){
                        return -1;
                    }
                }
            }
            return index;
        }
        else return -1;
    }
    
    bool dfs(int i, int index, vector<int>v[1101]){
        for(int j = 0;j < v[i].size();j++) if(v[i][j] == index) return true;
        return false;
    }
};
