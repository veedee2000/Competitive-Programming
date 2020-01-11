const int INF = 10000000;

class Solution {
public:
    vector<vector<int>>dp;
    int minimumTotal(vector<vector<int>>& triangle) {
        dp.resize(triangle.size());
        for(int i = 0;i < triangle.size();i++){
            dp[i].resize(i + 1, INF);
        }
        return f(0,0,triangle);
    }
    
    int f(int i,int j,vector<vector<int>>& triangle){
        if(j > i) return INF;
        if(i >= triangle.size()) return 0;
        if(dp[i][j] != INF) return dp[i][j];
        return dp[i][j] = triangle[i][j] + min(f(i + 1,j,triangle),f(i + 1,j + 1,triangle));
    }
};
