class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int start = 0,end = 0,ans = 0,val = 1;
        while(end < nums.size()){
            val *= nums[end];
            while(start < end and val >= k) val /= nums[start++];
            if(val < k) ans += (end - start + 1);
            end++;
        }
        return ans;
    }
};
