class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr=0, ans = INT_MIN, mmax = INT_MIN;
        for(auto x:nums){
            curr += x;
            mmax = max(x, mmax);
            if(curr < 0) curr = 0;
            else ans = max(ans, curr);
        }
        if(mmax < 0) return mmax;
        else return ans;
    }
};
