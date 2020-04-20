class Solution {
    
    vector<vector<double>>dp;
    vector<int>pre;
    
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        dp.resize(A.size(),vector<double>(K + 1,-1));
        pre.push_back(A[0]);
        for(int i = 1;i < A.size();i++) pre.push_back(A[i] + *(pre.end() - 1));
        return f(0,K,A);
    }
    
    double f(int i,int k,vector<int>& A){
        if(k == 0 and i < A.size()) return INT_MIN;
        if(i == A.size()) return 0;
        if(dp[i][k] != -1) return dp[i][k];
        for(int j = i;j < A.size();j++){
            dp[i][k] = max(dp[i][k],(double) (pre[j] - (i == 0 ? 0 : pre[i - 1])) / (j - i + 1) + f(j + 1,k - 1,A));
        }
        return dp[i][k];
    }
};
