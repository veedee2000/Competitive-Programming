class Solution {
public:
    vector<vector<int>>dp;
    int n;
    vector<int>stones;
        
    bool canCross(vector<int>& stones) {
        if(stones[1] != 1) return 0;
        this -> stones = stones;
        n = stones.size();
        dp.resize(stones[n - 1] + 1,vector<int>(stones[n - 1] + 1,-1));
        return f(1,1);
    }
    
    bool f(int i,int k){
        if(i > stones[n - 1] or k <= 0) return 0;
        if(i == stones[n - 1]) return 1;
        if(dp[i][k] != -1) return dp[i][k];
        bool c = 0;
        for(int j = 0;j < n;j++){
            c |= (stones[j] == i);
        }
        if(!c) return 0; 
        return dp[i][k] = f(i + k - 1,k - 1) | f(i + k,k) | f(i + k + 1,k + 1);
    }
};
