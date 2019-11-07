class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        if(n < 3) return 0;
        unordered_map<long long, int>dp[n];
        long long ans = 0;
        for(int i = 0;i < n;i++){
            for(int j = i - 1;j >= 0;j--){
                long long diff = (long long) A[i] - A[j];
                if(dp[j].find(diff) != dp[j].end()){
                    ans += dp[j][diff];
                    dp[i][diff] += dp[j][diff];
                }
                ++dp[i][diff];
            }
        }
        return ans;
    }
};
