class Solution {
public:
    int dp[1010][1010];
    bool stoneGame(vector<int>& piles) {
        for(int i = 0; i < 1000; i++){
            for(int j = 0;j < 1000; j++){
                dp[i][j] = INT_MIN;
            }
        }
        return (f(0,piles.size() - 1, piles) > 0);
    }
    
    int f(int i, int j, vector<int>& piles){
        if(i > j) return 0;
        if(dp[i][j] != INT_MIN) return dp[i][j];
        return dp[i][j] = max(piles[i] - f(i + 1, j, piles) , piles[j] - f(i, j - 1, piles));
    }
};
