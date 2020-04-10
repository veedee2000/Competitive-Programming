class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size(),i = 0,sum = 0,ans = INT_MAX,start = 0;
        while(i < n){
            while(i < n and sum < s) sum += nums[i++];
            while(start <= i and sum >= s){
                ans = min(ans,i - start);
                sum -= nums[start++];
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
