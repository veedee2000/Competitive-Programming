class Solution {
public:
    vector<vector<int>>dp;
    int S;
    vector<int>num;
    int findTargetSumWays(vector<int>& nums, int S) {
        this -> S = abs(S);
        int sum = accumulate(nums.begin(),nums.end(),0),v = 0;
        for(auto x:nums){
            if(x) num.push_back(x);
            else v++;
        }
        dp.resize(num.size(),vector<int>(sum + 1,-1));
        return (1 << v) * f(num.size() - 1,sum);
    }
    
    int f(int i,int val){
        if(val == S) return 1;
        if(i < 0 or val < S) return 0;
        if(dp[i][val] != -1) return dp[i][val];
        return dp[i][val] = f(i - 1,val - 2 * num[i]) + f(i - 1,val);
    }
};
