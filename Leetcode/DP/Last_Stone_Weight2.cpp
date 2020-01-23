const int INF = 10000000;

class Solution {
public:
    int sum;
    vector<vector<int>>dp;
    int lastStoneWeightII(vector<int>& stones) {
        sum = accumulate(stones.begin(),stones.end(),0);
        dp.resize(stones.size(),vector<int>(sum / 2 + 1,-1));
        int ans = f(0,0,stones);
        return abs(sum - 2 * ans);
    }
    
    int f(int i,int total,vector<int>& stones){
        if(total > sum / 2) return -INF;
        if(i >= stones.size() or total == sum / 2) return 0;
        if(dp[i][total] != -1) return dp[i][total];
        dp[i][total] = max(stones[i] + f(i + 1,total + stones[i],stones),f(i + 1,total,stones));
        return dp[i][total];
    }
};
