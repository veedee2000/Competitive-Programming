class Solution {
public:
    vector<vector<int>>dp;
    int uniquePathsWithObstacles(vector<vector<int>>& v) {
        dp.resize(v.size(), vector<int>(v[0].size(), -1));
        if(!v.size()) return 0;
        return f(0,0,v);
    }
    
    int f(int i,int j,vector<vector<int>>& v){
        if(i == v.size() - 1 and j == v[0].size()) return 1;
        if(i >= v.size() or j >= v[0].size()) return 0;
        if(v[i][j]) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = f(i + 1,j,v) + f(i,j + 1,v);
    }
};
