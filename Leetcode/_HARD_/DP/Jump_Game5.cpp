class Solution {
public:
    vector<int>arr,dp;
    int d;
    int maxJumps(vector<int>& arr, int d) {
        this -> arr = arr;
        this -> d = d;
        dp.resize(arr.size(),-1);
        int ans = 0;
        for(int i = 0;i < arr.size();i++) ans = max(ans,f(i));
        return ans;
    }
    
    int f(int i){
        if(dp[i] != -1) return dp[i];
        int ans = 1;
        for(int j = i - 1;j >= max(i - d,0);j--){
            if(arr[j] >= arr[i]) break;
            ans = max(ans,1 + f(j));
        }
        for(int j = i + 1;j <= min(i + d,(int)arr.size() - 1);j++){
            if(arr[j] >= arr[i]) break;
            ans = max(ans,1 + f(j));
        }
        return dp[i] = ans;
    }
};
