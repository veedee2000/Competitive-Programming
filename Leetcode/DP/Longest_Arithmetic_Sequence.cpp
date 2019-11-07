class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int n = A.size();
        if(n == 2) return 2;
        unordered_map<int,unordered_map<int,int>>dp;
        int ans = 2;
        for(int i = 1;i < n;i++){
            for(int j = 0;j < i;j++){
                int diff = A[i] - A[j];
                if(dp[j].count(diff)){
                    dp[i][diff] = dp[j][diff] + 1;
                }
                else dp[i][diff] = 2;
                ans = max(ans, dp[i][diff]);
            }
        }
        return ans;
    }
};
