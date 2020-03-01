class Solution {
public:
    vector<vector<int>>dp,matrix;
    vector<int>dr,dc;
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(!matrix.size()) return {};
        this -> matrix = matrix;
        dp.resize(matrix.size(),vector<int>(matrix[0].size(),-1));
        vector<vector<bool>>v(matrix.size(),vector<bool>(matrix[0].size(),0));
        dr = {0,0,-1,1},dc = {-1,1,0,0};
        int ans = 1;
        for(int i = 0;i < matrix.size();i++){
            for(int j = 0;j < matrix[0].size();j++){
                ans = max(ans,f(i,j,INT_MIN,v));
            }
        }
        return ans;
    }
    
    int f(int i,int j,int val,vector<vector<bool>>& v){
        if(i < 0 or j < 0 or i >= matrix.size() or j >= matrix[0].size()) return 0;
        if(matrix[i][j] <= val) return 0; 
        if(v[i][j]) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 1;
        v[i][j] = 1;
        for(int rc = 0;rc < 4;rc++){
            int x = i + dr[rc],y = j + dc[rc];
            ans = max(ans,1 + f(x,y,matrix[i][j],v));
        }
        v[i][j] = 0;
        return dp[i][j] = ans;
    }
};
