class Solution {
public:
    vector<vector<int>>dp;
    int stoneGameII(vector<int>& piles) {
        dp.resize(piles.size(), vector<int>(piles.size(), INT_MIN));
        int sum = 0;
        for(auto x:piles) sum += x;
        int ans = sum + f(0,1,piles);
        ans /= 2;
        return ans;
    }
    
    int f(int i, int m, vector<int>& piles){
        if(i >= piles.size()) return 0;
        if(dp[i][m] != INT_MIN) return dp[i][m];
        int val = 0;
        for(int j = 1;j <= 2 * m;j++){
            if(i + j - 1 >= piles.size()) break;
            val += piles[i + j - 1];
            dp[i][m] = max(dp[i][m], val - f(i + j, max(j, m), piles));
        }
        return dp[i][m];
    }
};
