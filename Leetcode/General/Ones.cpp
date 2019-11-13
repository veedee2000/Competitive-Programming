class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int now = 0,ans = 0;
        for(auto x:nums){
            if(x == 1) ans = max(ans, ++now);
            else now = 0;
        }
        return ans;
    }
};
