class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int ans = nums[0];
        int mmin = nums[0],mmax = nums[0],mmax1,mmin1;
        for(int i = 1; i < nums.size(); i++){
            mmax1 = max(mmax * nums[i], max(nums[i], mmin * nums[i]));
            mmin1 = min(mmax * nums[i], min(nums[i], mmin * nums[i]));
            mmax = mmax1;
            mmin = mmin1;
            ans = max(mmax, ans);
        }
        return ans;
    }
};
