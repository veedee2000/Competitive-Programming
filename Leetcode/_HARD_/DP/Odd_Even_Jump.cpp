class Solution {
public:
    int oddEvenJumps(vector<int>& A) {
        int n = A.size();
        vector<vector<bool>>dp(n,vector<bool>(2,0));
        map<int,int>mp;
        dp[n - 1] = {1,1};
        mp[A[n - 1]] = n - 1;
        int ans = 1;
        for(int i = n - 2;i >= 0;i--){
            auto upper = mp.lower_bound(A[i]);
            auto lower = mp.upper_bound(A[i]);
            if(upper != mp.end()){
                dp[i][0] = dp[upper->second][1];
            }
            if(lower != mp.begin()) {
                --lower;
                dp[i][1] = dp[lower->second][0];
            }
            ans += dp[i][0];
            mp[A[i]] = i;
        }
        return ans;
    }
};
