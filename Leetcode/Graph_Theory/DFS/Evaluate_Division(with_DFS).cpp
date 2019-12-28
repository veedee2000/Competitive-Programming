class Solution {
public:
    unordered_map<string,vector<pair<string,double>>>v;
    vector<double>ans;
    unordered_map<string,bool>b;
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for(int i = 0;i < equations.size();i++){
            double val1 = values[i],val2 = 1.0 / val1;
            v[equations[i][0]].push_back({equations[i][1],val1});
            v[equations[i][1]].push_back({equations[i][0],val2});
        }
        for(int i = 0;i < queries.size();i++){
            if(!v[queries[i][0]].size() or !v[queries[i][1]].size()){
                ans.push_back(-1);
                continue;
            }
            dfs(queries[i][0],queries[i][1],1.0);
            if(ans.size() != i + 1) ans.push_back(-1);
        }
        return ans;
    }
    
    void dfs(string i,string f,double val){
        b[i] = 1;
        if(i == f){
            ans.push_back(1.0);
            b[i] = 0;
            return;
        }
        else{
            for(int j = 0;j < v[i].size();j++){
                if(v[i][j].first == f){
                    ans.push_back(val * v[i][j].second);
                    break;
                }
                else if(!b[v[i][j].first]) dfs(v[i][j].first,f,val * v[i][j].second);
            }
        }
        b[i] = 0;
    }
};
