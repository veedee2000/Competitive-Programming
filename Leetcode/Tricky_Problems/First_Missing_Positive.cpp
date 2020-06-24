class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        nums.push_back(0);
        int n = nums.size();
        for(auto& x:nums) if(x < 1 or x >= n) x = 0;
        for(int i = 0;i < n;i++){
            nums[nums[i] % n] += n;
        }
        for(int  i = 1;i < n;i++){
            if(nums[i] < n) return i;
        }
        return n;
    }
};
