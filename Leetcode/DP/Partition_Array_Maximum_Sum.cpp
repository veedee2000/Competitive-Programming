class Solution {
public:
    vector<int>dp,A;
    int n,K;
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        this -> A = A;
        this -> K = K;
        n = A.size();
        dp.resize(n,-1);
        return f(0);
    }
    
    int f(int i){
        if(i > n - 1) return 0;
        if(dp[i] != -1) return dp[i];
        int val = A[i],ans = 0;
        for(int j = i;j < n;j++){
            val = max(val,A[j]);
            if(j - i + 1 > K) break;
            ans = max(ans, val * (j - i + 1) + f(j + 1));
        }
        return dp[i] = ans;
    }
};
