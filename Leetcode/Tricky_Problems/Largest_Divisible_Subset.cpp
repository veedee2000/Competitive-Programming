class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if(!n) return {};
        
        vector<int>dp(n, -1);
        vector<int>prev(n, -1);
        
        sort(nums.begin(), nums.end());
        
        int maxIndex = 0;
        
        for(int i = 0;i < nums.size();i++){
            for(int j = i - 1;j >= 0;j--){
                if(nums[i] % nums[j] == 0){
                    if(dp[i] < 1 + dp[j]){
                        dp[i] = 1 + dp[j];
                        prev[i] = j;
                        if(dp[i] > dp[maxIndex]) maxIndex = i;
                    }
                }
            }
        }
        
        vector<int>ans;
        
        while(maxIndex != -1){
            ans.push_back(nums[maxIndex]);
            maxIndex = prev[maxIndex];
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
