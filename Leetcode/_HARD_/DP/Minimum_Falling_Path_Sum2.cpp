class Solution {
public:
    vector<vector<int>>dp,A;
    int minFallingPathSum(vector<vector<int>>& arr) {
        this -> A = arr;
        dp.resize(A.size(),vector<int>(A[0].size(), 10000));
        int ans = 10000;
        for(int i = 0;i < A[0].size();i++){
            ans = min(ans,f(0,i));
        }
        return ans;
    }
    
    int f(int i,int j){
        if(i > A.size() - 1) return 0;
        if(j < 0 or j > A[0].size() - 1) return 10000;
        if(dp[i][j] != 10000) return dp[i][j];
        for(int col = 0;col < A[0].size();col++){
            if(j != col) dp[i][j] = min(dp[i][j],f(i + 1,col));
        }
        return dp[i][j] += A[i][j];
    }
};

