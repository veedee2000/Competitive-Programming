class Solution {
public:
    vector<vector<int>>dp,maxes;
    int mctFromLeafValues(vector<int>& arr) {
        dp.resize(arr.size(),vector<int>(arr.size(),-1));
        maxes.resize(arr.size(),vector<int>(arr.size(),-1));
        return f(0,arr.size() - 1,arr);
    }
    
    int f(int l,int r,vector<int>& arr){
        if(l == r){
            maxes[l][r] = arr[l];
            return 0;
        }
        if(l + 1 == r){
            maxes[l][r] = max(arr[l],arr[r]);
            return arr[l] * arr[r];
        }
        if(dp[l][r] != -1) return dp[l][r];
        int currSum = INT_MAX;
        for(int i = l;i < r;i++){
            currSum = min(currSum, f(l,i,arr) + f(i + 1,r,arr) + maxes[l][i] * maxes[i + 1][r]);
        }
        maxes[l][r] = max(maxes[l][r - 1],arr[r]);
        return dp[l][r] = currSum;
    }
};
