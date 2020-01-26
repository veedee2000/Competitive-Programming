class Solution {
public:
    vector<vector<int>>dp;
    bool canCross(vector<int>& stones) {
        if(stones[1] != 1) return 0;
        dp.resize(stones.size(),vector<int>(stones.size(),-1));
        return f(1,0,stones);
    }
    
    int f(int now,int pre,vector<int>& stones){
        if(now == stones.size() - 1) return 1;
        if(dp[now][pre] != -1) return dp[now][pre];
        int k = stones[now] - stones[pre];
        dp[now][pre] = 0;
        for(int i = now + 1;i < stones.size();i++){
            if(stones[now] + k - 1 == stones[i] and k > 1) dp[now][pre] |= f(i,now,stones);
            if(stones[now] + k == stones[i]) dp[now][pre] |= f(i,now,stones);
            if(stones[now] + k + 1 == stones[i]) dp[now][pre] |= f(i,now,stones);
            if(stones[now] + k + 1 < stones[i]) break;
        }
        return dp[now][pre];
    }
};
