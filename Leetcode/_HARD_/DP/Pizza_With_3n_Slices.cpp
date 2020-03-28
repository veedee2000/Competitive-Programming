class Solution {
public:
    vector<vector<int>>dp;
    int maxSizeSlices(vector<int>& slices) {
        dp.resize(slices.size(),vector<int>(slices.size() / 3,-1));
        int ans = f(slices,1,0);
        dp.clear();
        dp.resize(slices.size(),vector<int>(slices.size() / 3,-1));
        slices[slices.size() - 1] = 0;
        return max(ans,f(slices,0,0));
    }
    
    int f(vector<int>&slices,int i,int rem){
        if(i >= slices.size() or rem == slices.size() / 3) return 0;
        if(dp[i][rem] != -1) return dp[i][rem];
        return dp[i][rem] = max(f(slices,i + 1,rem),f(slices,i + 2,rem + 1) + slices[i]);
    }
};
